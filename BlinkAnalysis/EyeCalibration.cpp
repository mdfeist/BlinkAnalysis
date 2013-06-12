#include "StdAfx.h"
#include "EyeCalibration.h"
#include "Dikablis.h"

#include "EyeCalibrationWizardFormController.h"
#include "Marcos.h"

#include <algorithm>    // std::sort
#include <iostream>
#include <fstream>

#include <osg/Matrix>

EyeCalibration::EyeCalibration(void) { 
	this->rbHeadId = -1; 
	this->rbViewingObjectId = -1;

	this->eyeVectorArray = NULL;

	this->viewingWidth = ClientHandler::getDikablisViewingWidth();
	this->viewingHeight = ClientHandler::getDikablisViewingHeight();
	this->viewingMargin = ClientHandler::getDikablisViewingMargin();

	this->center_x = 0;
	this->center_y = 0;
}

EyeCalibration::~EyeCalibration(void) {
	if (this->eyeVectorArray != NULL)
		free(this->eyeVectorArray);
}

char* EyeCalibration::getNameById(int id) {
	if (id < 0)
		return 0;

	ClientHandler* client = AppData::getInstance()->getClient();

	if (client)
	{
		RigidBody* body = client->getRigidBody(id);
		if (body)
		{
			return body->getName();
		}
	}

	return 0;
}

bool EyeCalibration::addPoint() {

	ClientHandler* client = AppData::getInstance()->getClient();

	if (client == NULL)
		return false;
	
	RigidBody* head = client->getRigidBody(this->rbHeadId);
	RigidBody* viewing = client->getRigidBody(this->rbViewingObjectId);

	if (head == NULL || viewing == NULL)
		return false;

	osg::Matrixf headMatrix;
	headMatrix.makeIdentity();
	headMatrix.makeTranslate(head->getPosition());
	headMatrix.makeRotate(head->getRotation());

	if (!headMatrix.invert_4x4(headMatrix))
		return false;

	osg::Vec3 ray;
	ray = viewing->getPosition() - head->getPosition();
	ray = headMatrix * ray;
	ray.normalize();
	ray = ray/ray.z();

	Dikablis::journal_struct journal;
	journal = Dikablis::getJournal();

	CalibrationPoint point(journal.field_x, journal.field_y, ray);
	calibrationPoints.push_back(point);

	return true;
}

float EyeCalibration::area(CalibrationPointVector &contour) {
	int n = contour.size();

	float A=0.0f;

	for(int p=n-1,q=0; q<n; p=q++)
	{
		A+= contour[p].x()*contour[q].y() - contour[q].x()*contour[p].y();
	}
	return A*0.5f;
}

bool EyeCalibration::insideTriangle(CalibrationPoint A, CalibrationPoint B, CalibrationPoint C, CalibrationPoint P) {
	float ax, ay, bx, by, cx, cy, apx, apy, bpx, bpy, cpx, cpy;
	float cCROSSap, bCROSScp, aCROSSbp;

	ax = C.x() - B.x();  ay = C.y() - B.y();
	bx = A.x() - C.x();  by = A.y() - C.y();
	cx = B.x() - A.x();  cy = B.y() - A.y();
	apx= P.x() - A.x();  apy= P.y() - A.y();
	bpx= P.x() - B.x();  bpy= P.y() - B.y();
	cpx= P.x() - C.x();  cpy= P.y() - C.y();

	aCROSSbp = ax*bpy - ay*bpx;
	cCROSSap = cx*apy - cy*apx;
	bCROSScp = bx*cpy - by*cpx;

	return ((aCROSSbp >= 0.0f) && (bCROSScp >= 0.0f) && (cCROSSap >= 0.0f));
}

bool EyeCalibration::snip(CalibrationPointVector &contour,int u,int v,int w,int n,int *V) {
	int p;
	CalibrationPoint A, B, C, P;

	A = contour[V[u]];
	B = contour[V[v]];
	C = contour[V[w]];

	if ( EPSILON > (((B.x()-A.x())*(C.y()-A.y())) - ((B.y()-A.y())*(C.x()-A.x()))) ) return false;

	for (p=0;p<n;p++)
	{
		if( (p == u) || (p == v) || (p == w) ) continue;
		if (insideTriangle(A,B,C,contour[V[p]])) return false;
	}

	return true;
}

bool EyeCalibration::triangulate(CalibrationPointVector &contour, CalibrationPointVector &result) {
	/* allocate and initialize list of Vertices in polygon */

	int n = contour.size();
	if ( n < 3 ) return false;

	int *V = new int[n];

	/* we want a counter-clockwise polygon in V */

	if ( 0.0f < area(contour) )
		for (int v=0; v<n; v++) V[v] = v;
	else
		for(int v=0; v<n; v++) V[v] = (n-1)-v;

	int nv = n;

	/*  remove nv-2 Vertices, creating 1 triangle every time */
	int count = 2*nv;   /* error detection */

	for(int m=0, v=nv-1; nv>2; )
	{
		/* if we loop, it is probably a non-simple polygon */
		if (0 >= (count--))
		{
			//** Triangulate: ERROR - probable bad polygon!
			return false;
		}

		/* three consecutive vertices in current polygon, <u,v,w> */
		int u = v  ; if (nv <= u) u = 0;     /* previous */
		v = u+1; if (nv <= v) v = 0;     /* new v    */
		int w = v+1; if (nv <= w) w = 0;     /* next     */

		if ( snip(contour,u,v,w,nv,V) )
		{
			int a,b,c,s,t;

			/* true names of the vertices */
			a = V[u]; b = V[v]; c = V[w];

			/* output Triangle */
			result.push_back( contour[a] );
			result.push_back( contour[b] );
			result.push_back( contour[c] );

			m++;

			/* remove v from remaining polygon */
			for(s=v,t=v+1;t<nv;s++,t++) V[s] = V[t]; nv--;

			/* resest error detection counter */
			count = 2*nv;
		}
	}

	delete V;
	return true;
}

EyeCalibration::SegmentVector EyeCalibration::calculateConvexHull(CalibrationPointVector processingPoints) {
	// Edges
	SegmentVector segments;

	if (processingPoints.size() < 3)
		return segments;

	CalibrationPoint 
		minX = processingPoints.at(0), 
		minY = processingPoints.at(0), 
		maxX = processingPoints.at(0), 
		maxY = processingPoints.at(0);

	for (unsigned int i = 0; i < processingPoints.size(); i++) {
		CalibrationPoint point = processingPoints.at(i);
		osg::Vec3 ray = point.ray();

		if (minX.x() > point.x())
			minX = point;

		if (minY.y() > point.y())
			minY = point;

		if (maxX.x() < point.x())
			maxX = point;

		if (maxY.y() < point.y())
			maxY = point;
	}

	// Get center
	int center_x = (maxX.x() - minX.x())/2;
	int center_y = (maxY.y() - minY.y())/2;

	// Ordered Point
	CalibrationPointVector orderedPoints(processingPoints);

	// Sort Points
	sort(orderedPoints, center_x, center_y);

	// Create segments
	for (unsigned int i = 0; i < orderedPoints.size(); i++) {
		CalibrationPoint from = orderedPoints.at(i);

		for (unsigned int k = 0; k < orderedPoints.size(); k++) {
			if (i == k)
				continue;

			CalibrationPoint to = orderedPoints.at(k);

			Segment segment(from, to);
			segments.push_back(segment);
		}
	}

	unsigned int i = 0;
	unsigned int j = 0;
	while ( i < segments.size() )
	{
		//ProcessingPoints will be the points that are not in  the current segment
		CalibrationPointVector processingPoints(orderedPoints);
		Segment segment = segments.at(i);

		//this loop prepares the ProcessingPoints list for each segment
		while ( j < processingPoints.size() )
		{
			CalibrationPoint point = processingPoints.at(j);
			if((segment.x1() == point.x() && segment.y1() == point.y()) ||
				(segment.x2() == point.x() && segment.y2() == point.y()))
			{
				//eliminating the points that are already in the current segment...
				//we don't need them
				processingPoints.erase(processingPoints.begin()+j);
				j = 0;
			} else {
				j++;
			}
		}

		//checking if the current segment is an edge or notBy calling isEdge function
		if( !isEdge(processingPoints, segments.at(i)) )
		{
			segments.erase(segments.begin()+i);
			i = 0;
		} else {
			i++;
		} 
	}

	return segments;
}

bool EyeCalibration::minimalTriangulation(CalibrationPointVector &contour, CalibrationPointVector &result) {

	return true;
}

bool EyeCalibration::calibrate() {
	char buf[512];

	// Print starting message
	EyeCalibrationWizardFormController::getInstance()->calibrationOutputLog("Starting Calibration\n");

	// Create buffer
	if (this->eyeVectorArray == NULL)
		this->eyeVectorArray = (float*) malloc(sizeof(float) * ClientHandler::getDikablisViewingSize());

	sprintf_s(buf, "Creating buffer of size %d bytes\n", sizeof(float) * ClientHandler::getDikablisViewingSize());
	EyeCalibrationWizardFormController::getInstance()->calibrationOutputLog(buf);

	// Print the number of points used in the calibration
	sprintf_s(buf, "A total of %d points was collected.\n", calibrationPoints.size());
	EyeCalibrationWizardFormController::getInstance()->calibrationOutputLog(buf);

	if (calibrationPoints.size() < 4) {
		EyeCalibrationWizardFormController::getInstance()->calibrationOutputLog("Not enough points to calculate calibration.\n");
		return false;
	}

	CalibrationPoint 
		minX = calibrationPoints.at(0), 
		minY = calibrationPoints.at(0), 
		maxX = calibrationPoints.at(0), 
		maxY = calibrationPoints.at(0);

	// Print each points information
	for (unsigned int i = 0; i < calibrationPoints.size(); i++) {
		CalibrationPoint point = calibrationPoints.at(i);
		osg::Vec3 ray = point.ray();

		// Print info
		sprintf_s(buf, "Point %d (%d, %d) has a value of (%f, %f, %f)\n", 
			i + 1,
			point.x(), point.y(),
			ray.x(), ray.y(), ray.z());
		EyeCalibrationWizardFormController::getInstance()->calibrationOutputLog(buf);

		if (minX.x() > point.x())
			minX = point;

		if (minY.y() > point.y())
			minY = point;

		if (maxX.x() < point.x())
			maxX = point;

		if (maxY.y() < point.y())
			maxY = point;
	}

	// Print Bounding Info
	{
		sprintf_s(buf, "Point with min X value (%d, %d)\n", 
			minX.x(), minX.y());
		EyeCalibrationWizardFormController::getInstance()->calibrationOutputLog(buf);

		sprintf_s(buf, "Point with min Y value (%d, %d)\n", 
			minY.x(), minY.y());
		EyeCalibrationWizardFormController::getInstance()->calibrationOutputLog(buf);

		sprintf_s(buf, "Point with max X value (%d, %d)\n", 
			maxX.x(), maxX.y());
		EyeCalibrationWizardFormController::getInstance()->calibrationOutputLog(buf);

		sprintf_s(buf, "Point with max Y value (%d, %d)\n", 
			maxY.x(), maxY.y());
		EyeCalibrationWizardFormController::getInstance()->calibrationOutputLog(buf);

		this->center_x = (maxX.x() - minX.x())/2;
		this->center_y = (maxY.y() - minY.y())/2;

		sprintf_s(buf, "Center point is (%d, %d)\n", 
			center_x, center_y);
		EyeCalibrationWizardFormController::getInstance()->calibrationOutputLog(buf);
	}

	// Get Convex Hull
	CalibrationPointVector boundingPoints;
	SegmentVector convexHull = calculateConvexHull(calibrationPoints);
	boundingPointsOfHull(convexHull, boundingPoints);

	// Print each segment information
	for (unsigned int i = 0; i < convexHull.size(); i++) {
		Segment segment = convexHull.at(i);
		sprintf_s(buf, "Edge %d: From (%d, %d) to (%d, %d)\n", 
			i + 1,
			segment.x1(), segment.y1(),
			segment.x2(), segment.y2());
		EyeCalibrationWizardFormController::getInstance()->calibrationOutputLog(buf);
	}

	sort(boundingPoints, center_x, center_y);

	// Triangulate
	CalibrationPointVector traingles;
	triangulate(boundingPoints, traingles);

	if (traingles.size() % 3 != 0) {
		EyeCalibrationWizardFormController::getInstance()->calibrationOutputLog("Error: Triangulating polygon.\n");
		return false;
	}

	CalibrationPointVector innerPoints;
	for (unsigned int i = 0; i < calibrationPoints.size(); i++) {
		CalibrationPoint point = calibrationPoints[i];
		bool found = false;
		for (unsigned int k = 0; k < boundingPoints.size(); k++) {
			if (point.equal(boundingPoints[k])) {
				found = true;
				break;
			}
		}

		if (!found)
			innerPoints.push_back(point);
	}

	unsigned int traingleCount = traingles.size() / 3;
	for (unsigned int i = 0; i < innerPoints.size(); i++) {
		CalibrationPoint P = innerPoints[i];

		for (unsigned int k = 0; k < traingleCount; k++) {
			CalibrationPoint A = traingles[3*k + 0];
			CalibrationPoint B = traingles[3*k + 1];
			CalibrationPoint C = traingles[3*k + 2];

			if (insideTriangle(A,B,C,P)) {
				traingles.erase(traingles.begin()+3*k, traingles.begin()+3*k+3);

				CalibrationPoint center, P0;

				// Triangle 1
				CalibrationPointVector tri1;
				tri1.push_back(A);
				tri1.push_back(B);
				tri1.push_back(P);

				P0 = A + (B - A)/2.f;
				center = P + (P0 - P)*(3.f/2.f);

				sort(tri1, center.x(), center.y());

				// Triangle 2
				CalibrationPointVector tri2;
				tri2.push_back(A);
				tri2.push_back(C);
				tri2.push_back(P);
				
				P0 = A + (C - A)/2.f;
				center = P + (P0 - P)*(3.f/2.f);

				sort(tri2, center.x(), center.y());

				// Triangle 3
				CalibrationPointVector tri3;
				tri3.push_back(B);
				tri3.push_back(C);
				tri3.push_back(P);

				P0 = B + (C - B)/2.f;
				center = P + (P0 - P)*(3.f/2.f);

				sort(tri3, center.x(), center.y());

				traingles.insert(traingles.end(), tri1.begin(), tri1.end());
				traingles.insert(traingles.end(), tri2.begin(), tri2.end());
				traingles.insert(traingles.end(), tri3.begin(), tri3.end());

				break;
			}
		}
	}

	if (traingles.size() % 3 != 0) {
		EyeCalibrationWizardFormController::getInstance()->calibrationOutputLog("Error: Triangulating inner points in polygon.\n");
		return false;
	}

	traingleCount = traingles.size() / 3;

	for (unsigned int j = 0; j < (viewingHeight+2*viewingMargin); j++) {
		for (unsigned int i = 0; i < (viewingWidth+2*viewingMargin); i++) {
			CalibrationPoint P(i - viewingMargin, j - viewingMargin, osg::Vec3(0.f, 0.f, 0.f));

			for (unsigned int k = 0; k < traingleCount; k++) {
				CalibrationPoint A = traingles[3*k + 0];
				CalibrationPoint B = traingles[3*k + 1];
				CalibrationPoint C = traingles[3*k + 2];

				if (insideTriangle(A,B,C,P)) {
					osg::Vec3 ray = (A.ray() + B.ray() + C.ray())/3.f;

					unsigned long location = 3*(j*(viewingWidth+2*viewingMargin) + i);
					
					this->eyeVectorArray[location + 0] = ray.x();
					this->eyeVectorArray[location + 1] = ray.y();
					this->eyeVectorArray[location + 2] = ray.z();

					break;
				}
			}
		}
	}

	for (unsigned int c = 0; c < calibrationPoints.size(); c++) {
		CalibrationPoint point = calibrationPoints[c];

		for (int j = -10; j < 10; j++) {
			for (int i = -10; i < 10; i++) {

				int x = point.x() + i + viewingMargin;
				int y = point.y() + j + viewingMargin;

				if (x >= 0 && x < (int)(viewingWidth+2*viewingMargin) &&
					y >= 0 && y < (int)(viewingHeight+2*viewingMargin)) {

					unsigned long location = 3*(y*(viewingWidth+2*viewingMargin) + x);
					
					this->eyeVectorArray[location + 0] = 255;
					this->eyeVectorArray[location + 1] = 0;
					this->eyeVectorArray[location + 2] = 0;
				}
			}
		}
	}

	for (unsigned int c = 0; c < boundingPoints.size(); c++) {
		CalibrationPoint point = boundingPoints[c];

		for (int j = -10; j < 10; j++) {
			for (int i = -10; i < 10; i++) {

				int x = point.x() + i + viewingMargin;
				int y = point.y() + j + viewingMargin;

				if (x >= 0 && x < (int)(viewingWidth+2*viewingMargin) &&
					y >= 0 && y < (int)(viewingHeight+2*viewingMargin)) {

					unsigned long location = 3*(y*(viewingWidth+2*viewingMargin) + x);
					
					this->eyeVectorArray[location + 0] = 0;
					this->eyeVectorArray[location + 1] = 255;
					this->eyeVectorArray[location + 2] = 0;
				}
			}
		}
	}

	saveRayMap();

	EyeCalibrationWizardFormController::getInstance()->calibrationOutputLog("Done\n");

	return true;
}

bool EyeCalibration::sort(CalibrationPointVector &points, int center_x, int center_y) {
	int i, j;
	CalibrationPoint key;
	int size = points.size( );

	for(j = 1; j < size; j++)    // Start with 1 (not 0)
	{
		key = points[j];
		for(i = j - 1; (i >= 0) && (isLess(points[i], key, center_x, center_y)); i--)   // Smaller values move up
		{
			points[i+1] = points[i];
		}

		points[i+1] = key;    //Put key into its proper location
	}

	return true;
}

bool EyeCalibration::boundingPointsOfHull(SegmentVector &contour, CalibrationPointVector &result) {

	for (unsigned int i = 0; i < contour.size(); i++) {
		Segment edge = contour[i];
		CalibrationPoint A = edge.p1();
		CalibrationPoint B = edge.p2();

		bool foundA = false;
		bool foundB = false;
		for (unsigned int k = 0; k < result.size(); k++) {
			if (result[k].equal(A))
				foundA = true;
			if (result[k].equal(B))
				foundB = true;
			if (foundA && foundB)
				break;
		}

		if (!foundA)
			result.push_back(A);
		if (!foundB)
			result.push_back(B);
	}

	return true;
}

bool EyeCalibration::isLess(CalibrationPoint a, CalibrationPoint b, int center_x, int center_y)
{
    if (a.x() >= 0 && b.x() < 0)
        return true;
    if (a.x() == 0 && b.x() == 0)
        return a.y() > b.y();

    // compute the cross product of vectors (center -> a) x (center -> b)
    int det = (a.x() - center_x) * (b.y() - center_y) - (b.x() - center_x) * (a.y() - center_y);
    if (det < 0)
        return true;
    if (det > 0)
        return false;

    // points a and b are on the same line from the center
    // check which point is closer to the center
    int d1 = (a.x() - center_x) * (a.x() - center_x) + (a.y() - center_y) * (a.y() - center_y);
    int d2 = (b.x() - center_x) * (b.x() - center_x) + (b.y() - center_y) * (b.y() - center_y);
    return d1 > d2;
}

bool EyeCalibration::isEdge(CalibrationPointVector processingPoints, Segment edge)
{
	for(unsigned int k = 0; k < processingPoints.size(); k++)
	{  
		if(isLeft(edge, processingPoints.at(k)) > 0)
		{
			return false;
		}
	}
	return true;
}

int EyeCalibration::isLeft(Segment segment, CalibrationPoint r) {
	float D = 0;
	float px, py, qx, qy, rx, ry = 0;
	//The determinant 
	// | 1 px py | 
	// | 1 qx qy | 
	// | 1 rx ry | 
	//if the determinant result is positive the point is
	//left of the segment 
	px = segment.x1();
	py = segment.y1();
	qx = segment.x2(); 
	qy = segment.y2();
	rx = r.x();
	ry = r.y();
	D = ((qx * ry) - (qy * rx)) - (px *(ry - qy)) + (py * (rx - qx));

	if (D > 0)
		return 1;
	else if (D < 0)
		return -1;
	else
		return 0;
}

EyeCalibration::SegmentVector EyeCalibration::getEdges(CalibrationPointVector processingPoints) {
	SegmentVector edges;
	for (unsigned int i = 0; i < processingPoints.size(); i++) {
		for (unsigned int j = i + 1; j < processingPoints.size(); j++) {
			edges.push_back( Segment(processingPoints.at(i), processingPoints.at(j)) );
		}
	}

	return edges;
}

EyeCalibration::CalibrationPoint EyeCalibration::getClosestPoint(CalibrationPoint a, CalibrationPoint b, CalibrationPoint point, bool segmentClamp) {
	int ap_x = point.x() - a.x();
	int ap_y = point.y() - a.y();

	int ab_x = b.x() - a.x();
	int ab_y = b.y() - a.y();

	float ab2 = ab_x*ab_x + ab_y*ab_y;
	float ap_ab = ap_x*ab_x + ap_y*ab_y;

	float t = ap_ab / ab2;

	if (segmentClamp) {
		if (t < 0.f) t = 0.f;
		else if (t > 1.f) t = 1.f;
	}

	int closest_x = a.x() + ab_x * t;
	int closest_y = a.y() + ab_y * t;

	osg::Vec3 ab_ray = b.ray() - a.ray();
	osg::Vec3 ray = a.ray() + ab_ray * t;

	CalibrationPoint closest(closest_x, closest_y, ray);
	return closest;
}

// Returns 1 if the lines intersect, otherwise 0. In addition, if the lines 
// intersect the intersection point may be stored in the floats i_x and i_y.
int EyeCalibration::getLineIntersection(CalibrationPoint A, CalibrationPoint B, CalibrationPoint C, CalibrationPoint D)
{
	if ((A.equal(C) && B.equal(D) || A.equal(D) && B.equal(C))) {
		return 0;
	}

    float s1_x, s1_y, s2_x, s2_y, sn, tn, sd, td;
    s1_x = B.x() - A.x();     s1_y = B.y() - A.y();
    s2_x = D.x() - C.x();     s2_y = D.y() - C.y();
 
    sn = -s1_y * (A.x() - C.x()) + s1_x * (A.y() - C.y());
    sd = -s2_x * s1_y + s1_x * s2_y;
    tn =  s2_x * (A.y() - C.y()) - s2_y * (A.x() - C.x());
    td = -s2_x * s1_y + s1_x * s2_y;
 
    if (sn >= 0 && sn <= sd && tn >= 0 && tn <= td)
    {
        // Collision detected
        return 1;
    }
 
    return 0; // No collision
}

void EyeCalibration::saveRayMap() {
	int width = 512;
	int height = 512;

    HANDLE file;
    BITMAPFILEHEADER fileHeader;
    BITMAPINFOHEADER fileInfo;
    RGBTRIPLE *image;
    DWORD write = 0;
    image = new RGBTRIPLE[width*height*24];
 
    file = CreateFile(L"rayMap.bmp",GENERIC_WRITE,0,NULL,CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL,NULL);  //Sets up the new bmp to be written to
 
    fileHeader.bfType = 19778;                                                                    //Sets our type to BM or bmp
    fileHeader.bfSize = sizeof(fileHeader.bfOffBits) + sizeof(RGBTRIPLE);                                                //Sets the size equal to the size of the header struct
    fileHeader.bfReserved1 = 0;                                                                    //sets the reserves to 0
    fileHeader.bfReserved2 = 0;
    fileHeader.bfOffBits = sizeof(BITMAPFILEHEADER)+sizeof(BITMAPINFOHEADER);                    //Sets offbits equal to the size of file and info header
 
    fileInfo.biSize = sizeof(BITMAPINFOHEADER);
    fileInfo.biWidth = width;
    fileInfo.biHeight = height;
    fileInfo.biPlanes = 1;
    fileInfo.biBitCount = 24;
    fileInfo.biCompression = BI_RGB;
    fileInfo.biSizeImage = width * height * (24/8);
    fileInfo.biXPelsPerMeter = 2400;
    fileInfo.biYPelsPerMeter = 2400;
    fileInfo.biClrImportant = 0;
    fileInfo.biClrUsed = 0;
 
    WriteFile(file,&fileHeader,sizeof(fileHeader),&write,NULL);
    WriteFile(file,&fileInfo,sizeof(fileInfo),&write,NULL);
	
	for (int j = 0; j < height; j++) {
		for (int i = 0; i < width; i++) {

			int index = (height-1-j)*width+i;
			int pi_width = (((float)i/width)*(viewingWidth+2*viewingMargin));
			int pi_height = (((float)j/height)*(viewingHeight+2*viewingMargin));
			int pi = 3*(pi_height*(viewingWidth+2*viewingMargin) + pi_width);

			int blue = this->eyeVectorArray[pi + 2];
			int green = this->eyeVectorArray[pi + 1];
			int red = this->eyeVectorArray[pi + 0];

			if (blue < 0)
				blue = 0;
			else if (blue > 255)
				blue = 255;
			
			if (green < 0)
				green = 0;
			else if (green > 255)
				green = 255; 

			if (red < 0)
				red = 0;
			else if (red > 255)
				red = 255;

			image[index].rgbtBlue = blue;
			image[index].rgbtGreen = green;
			image[index].rgbtRed = red;

			/*
			if (index >= 0 && index < DikablisViewingSize - 3) {
			int b = 10*(this->dikablisEyeVectorArray[3*index + 0] + 20);
			int g = 10*(this->dikablisEyeVectorArray[3*index + 1] + 20);
			int r = 10*(this->dikablisEyeVectorArray[3*index + 2] + 20);


			image[i].rgbtBlue = b;
			image[i].rgbtGreen = g;
			image[i].rgbtRed = r;
			} else {
			image[index].rgbtBlue = 0;
			image[index].rgbtGreen = 0;
			image[index].rgbtRed = 0;
			}
			*/
		}
	}
 
    WriteFile(file, image, fileInfo.biSizeImage, &write, NULL);
 
    CloseHandle(file);
}

void EyeCalibration::createTestData() {

	CalibrationPoint point1(20, 5, osg::Vec3(255.f, 0.f, 0.f));
	calibrationPoints.push_back(point1);

	CalibrationPoint point2(322, 2, osg::Vec3(125.f, 125.f, 0.f));
	calibrationPoints.push_back(point2);

	CalibrationPoint point3(700, 25, osg::Vec3(0, 0.f, 125.f));
	calibrationPoints.push_back(point3);

	CalibrationPoint point4(-10, 280, osg::Vec3(0.f, 125.f, 0.f));
	calibrationPoints.push_back(point4);

	CalibrationPoint point5(374, 180, osg::Vec3(0.f, 0.f, 255.f));
	calibrationPoints.push_back(point5);

	CalibrationPoint point6(742, 320, osg::Vec3(0.f, 125.f, 125.f));
	calibrationPoints.push_back(point6);

	CalibrationPoint point7(4, 480, osg::Vec3(125.f, 0.f, 125.f));
	calibrationPoints.push_back(point7);

	CalibrationPoint point8(280, 465, osg::Vec3(125.f, 0.f, 0.f));
	calibrationPoints.push_back(point8);

	CalibrationPoint point9(724, 520, osg::Vec3(0.f, 255.f, 255.f));
	calibrationPoints.push_back(point9);
}