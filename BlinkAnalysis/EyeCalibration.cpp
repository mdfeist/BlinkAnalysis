#include "StdAfx.h"
#include "EyeCalibration.h"
#include "Dikablis.h"

#include "EyeCalibrationWizardFormController.h"
#include "Marcos.h"

#include <algorithm>    // std::sort
#include <iostream>
#include <fstream>
#include <math.h>

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
	//headMatrix.makeTranslate(head->getPosition());
	headMatrix.makeRotate(head->getRotation());

	if (!headMatrix.invert_4x4(headMatrix))
		return false;

	osg::Vec3 ray;
	ray = viewing->getPosition() - head->getPosition();
	ray = headMatrix * ray;
	ray.normalize();
	//ray = ray/ray.y();

	Dikablis::journal_struct journal;
	journal = Dikablis::getJournal();

	CalibrationPoint point(journal.field_x, journal.field_y, ray);

	bool exists = false;
	for (unsigned int i = 0; i < calibrationPoints.size(); i++) {
		if (point.equal(calibrationPoints[i])) {
			exists = true;
			break;
		}
	}

	if (!exists)
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

bool EyeCalibration::isInCircumCircle(CalibrationPoint &point, CalibrationPointVector &traingle) {

	CalibrationPoint center, P0;

	if (traingle.size() != 3)
		return false;

	CalibrationPoint A = traingle[0];
	CalibrationPoint B = traingle[1];
	CalibrationPoint C = traingle[2];

	P0 = A + (B - A)/2.f;
	center = C + (P0 - C)*(3.f/2.f);

	sort(traingle, center.x(), center.y());

	float ax_sq = A.x()*A.x();
	float ay_sq = A.y()*A.y();

	float bx_sq = B.x()*B.x();
	float by_sq = B.y()*B.y();

	float cx_sq = C.x()*C.x();
	float cy_sq = C.y()*C.y();

	float px_sq = point.x()*point.x();
	float py_sq = point.y()*point.y();

	float a11 = A.x() - point.x();
	float a12 = A.y() - point.y();
	float a13 = (ax_sq - px_sq) + (ay_sq - py_sq);

	float a21 = B.x() - point.x();
	float a22 = B.y() - point.y();
	float a23 = (bx_sq - px_sq) + (by_sq - py_sq);

	float a31 = C.x() - point.x();
	float a32 = C.y() - point.y();
	float a33 = (cx_sq - px_sq) + (cy_sq - py_sq);

	float det = (a11)*(a22*a33 - a32*a23) - (a12)*(a21*a33 - a31*a23) + (a13)*(a21*a32 - a31*a22);

	return det > 0;
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

	// Min/Max coordinates of the polygon
	CalibrationPoint 
		minX = calibrationPoints.at(0), 
		minY = calibrationPoints.at(0), 
		maxX = calibrationPoints.at(0), 
		maxY = calibrationPoints.at(0);

	// Print each points information and get the min and max
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

		// Get center
		this->center_x = (maxX.x() - minX.x())/2;
		this->center_y = (maxY.y() - minY.y())/2;

		sprintf_s(buf, "Center point is (%d, %d)\n", 
			center_x, center_y);
		EyeCalibrationWizardFormController::getInstance()->calibrationOutputLog(buf);
	}

	// Get Convex Hull
	CalibrationPointVector boundingPoints;
	SegmentVector convexHull = calculateConvexHull(calibrationPoints);
	// Get the bounding points of the convex hull
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

	// Resort the bounding points
	sort(boundingPoints, center_x, center_y);

	// Triangulate
	CalibrationPointVector traingles;
	triangulate(boundingPoints, traingles);

	// Check if the triangulation is valid 
	if (traingles.size() % 3 != 0) {
		EyeCalibrationWizardFormController::getInstance()->calibrationOutputLog("Error: Triangulating polygon.\n");
		return false;
	}

	// Get the remaining inner points of the convex hull
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

	// Flip edges of the triangles
	for (int k = traingleCount - 1; k > 0 ; k--) {
		CalibrationPointVector tri1;

		tri1.push_back(traingles[3*k + 0]);
		tri1.push_back(traingles[3*k + 1]);
		tri1.push_back(traingles[3*k + 2]);

		for (int i = k - 1; i >= 0; i--) {
			CalibrationPointVector tri2;

			tri2.push_back(traingles[3*i + 0]);
			tri2.push_back(traingles[3*i + 1]);
			tri2.push_back(traingles[3*i + 2]);

			// Get shared edge if exists
			int shared = 0;
			CalibrationPointVector sharedPoints;
			CalibrationPoint nonSharedPoint;
			for (unsigned int idx1 = 0; idx1 < 3; idx1++) {
				for (unsigned int idx2 = 0; idx2 < 3; idx2++) {
					if (tri2[idx2].equal(tri1[idx1])) {
						sharedPoints.push_back(tri1[idx1]);
						shared++;
					} else {
						nonSharedPoint = tri2[idx2];
					}
				}
			}


			if (shared == 2) {
				if (isInCircumCircle(nonSharedPoint, tri1)) {
					sprintf_s(buf, "Point %d - (%d, %d): In circle of triangle (%d, %d), (%d, %d), (%d, %d)\n", 
						i + 1, nonSharedPoint.x(), nonSharedPoint.y(), 
						tri1[0].x(), tri1[0].y(), 
						tri1[1].x(), tri1[1].y(), 
						tri1[2].x(), tri1[2].y());
					EyeCalibrationWizardFormController::getInstance()->calibrationOutputLog(buf);

					// Sort tri1
					for (unsigned int idx = 0; idx < 3; idx++) {
						if (tri1[idx].equal(sharedPoints[0]) || tri1[idx].equal(sharedPoints[1])) {
							CalibrationPoint shared = tri1[idx];
							tri1.erase(tri1.begin()+idx);
							tri1.insert(tri1.begin(), shared);
						}
					}

					// Sort tri2
					for (unsigned int idx = 0; idx < 3; idx++) {
						if (tri2[idx].equal(sharedPoints[0]) || tri2[idx].equal(sharedPoints[1])) {
							CalibrationPoint shared = tri2[idx];
							tri2.erase(tri2.begin()+idx);
							tri2.insert(tri2.begin(), shared);
						}
					}

					// Clean up old triangles
					traingles.erase(traingles.begin()+3*k, traingles.begin()+3*k+3);
					traingles.erase(traingles.begin()+3*i, traingles.begin()+3*i+3);

					CalibrationPoint center, P0;

					// New Triangle 1
					CalibrationPointVector new_tri1;
					new_tri1.push_back(tri1[0]);
					new_tri1.push_back(tri1[2]);
					new_tri1.push_back(tri2[2]);

					P0 = tri1[0] + (tri2[2] - tri1[0])/2.f;
					center = tri1[2] + (P0 - tri1[2])*(3.f/2.f);

					sort(new_tri1, center.x(), center.y());

					// New Triangle 2
					CalibrationPointVector new_tri2;
					new_tri2.push_back(tri1[1]);
					new_tri2.push_back(tri1[2]);
					new_tri2.push_back(tri2[2]);

					P0 = tri1[1] + (tri2[2] - tri1[1])/2.f;
					center = tri1[2] + (P0 - tri1[2])*(3.f/2.f);

					sort(new_tri2, center.x(), center.y());

					traingles.insert(traingles.end(), new_tri1.begin(), new_tri1.end());
					traingles.insert(traingles.end(), new_tri2.begin(), new_tri2.end());

					break;
				}
			}
		}
	}

	// Draw triangles
	for (unsigned int j = 0; j < (viewingHeight+2*viewingMargin); j++) {
		for (unsigned int i = 0; i < (viewingWidth+2*viewingMargin); i++) {
			CalibrationPoint P(i - viewingMargin, j - viewingMargin, osg::Vec3(0.f, 0.f, 0.f));

			for (unsigned int k = 0; k < traingleCount; k++) {
				CalibrationPoint A = traingles[3*k + 0];
				CalibrationPoint B = traingles[3*k + 1];
				CalibrationPoint C = traingles[3*k + 2];

				if (insideTriangle(A,B,C,P)) {
					osg::Vec3 ray;

					float det = A.x()*B.y()-B.x()*A.y()+B.x()*C.y()-C.x()*B.y()+C.x()*A.y()-A.x()*C.y();
					osg::Vec3 a = (A.ray()*(B.y()-C.y())+B.ray()*(C.y()-A.y())+C.ray()*(A.y()-B.y())) / det;
					osg::Vec3 b = (A.ray()*(C.x()-B.x())+B.ray()*(A.x()-C.x())+C.ray()*(B.x()-A.x())) / det;
					osg::Vec3 c = (A.ray()*(B.x()*C.y()-C.x()*B.y())+B.ray()*(C.x()*A.y()-A.x()*C.y())+C.ray()*(A.x()*B.y()-B.x()*A.y())) / det;
					ray = a*P.x()+b*P.y()+c;

					unsigned long location = 3*(j*(viewingWidth+2*viewingMargin) + i);
					
					this->eyeVectorArray[location + 0] = ray.x();
					this->eyeVectorArray[location + 1] = ray.y();
					this->eyeVectorArray[location + 2] = ray.z();

					break;
				}
			}
		}
	}

	// Draw Outside
	for (unsigned int j = 0; j < (viewingHeight+2*viewingMargin); j++) {
		for (unsigned int i = 0; i < (viewingWidth+2*viewingMargin); i++) {
			CalibrationPoint P(i - viewingMargin, j - viewingMargin, osg::Vec3(0.f, 0.f, 0.f));

			bool inside = false;
			for (unsigned int k = 0; k < traingleCount; k++) {
				CalibrationPoint A = traingles[3*k + 0];
				CalibrationPoint B = traingles[3*k + 1];
				CalibrationPoint C = traingles[3*k + 2];

				if (insideTriangle(A,B,C,P)) {
					inside = true;
					break;
				}
			}

			if (!inside) {

				CalibrationPoint closest;
				float min_distance = -1;
				for (unsigned int k = 0; k < convexHull.size(); k++) {
					CalibrationPoint A = convexHull[k].p1();
					CalibrationPoint B = convexHull[k].p2();

					CalibrationPoint P0 = getClosestPoint(A, B, P, true);
					
					float diff_x = P0.x() - P.x();
					float diff_y = P0.y() - P.y();

					float distance = diff_x*diff_x + diff_y*diff_y;

					if (min_distance < 0 || min_distance > distance) {
						min_distance = distance;
						closest = P0;
					}
				}

				osg::Vec3 ray = closest.ray();

				unsigned long location = 3*(j*(viewingWidth+2*viewingMargin) + i);

				this->eyeVectorArray[location + 0] = ray.x();
				this->eyeVectorArray[location + 1] = ray.y();
				this->eyeVectorArray[location + 2] = ray.z();
			}
		}
	}

// Testing
#if 0
	// Draw points
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

	// Draw bounding points
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
#endif

	saveRayMap();

	ClientHandler* client = AppData::getInstance()->getClient();

	if (client) {
		client->setRayCalibration(this->eyeVectorArray);
		client->setHeadId(this->rbHeadId);
	} else {
		EyeCalibrationWizardFormController::getInstance()->calibrationOutputLog("Failed: Unable to find client.\n");
		return false;
	}

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

	float max = 0.f;
	for (unsigned int i = 0; i < (viewingWidth+2*viewingMargin)*(viewingHeight+2*viewingMargin); i++) {
		float value = fabsf(this->eyeVectorArray[i]);

		if (value > max)
			max = value;
	}
	
	for (int j = 0; j < height; j++) {
		for (int i = 0; i < width; i++) {

			int index = (height-1-j)*width+i;
			int pi_width = (((float)i/width)*(viewingWidth+2*viewingMargin));
			int pi_height = (((float)j/height)*(viewingHeight+2*viewingMargin));
			int pi = 3*(pi_height*(viewingWidth+2*viewingMargin) + pi_width);

			int blue = ((this->eyeVectorArray[pi + 2] + max)/(2*max))*255;
			int green = ((this->eyeVectorArray[pi + 1] + max)/(2*max))*255;
			int red = ((this->eyeVectorArray[pi + 0] + max)/(2*max))*255;

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

	CalibrationPoint point1(20, 5, osg::Vec3(-1.2f, -1.f, 2.f));
	calibrationPoints.push_back(point1);

	CalibrationPoint point2(700, 25, osg::Vec3(1.4f, -1.f, 1.6f));
	calibrationPoints.push_back(point2);

	CalibrationPoint point3(-10, 520, osg::Vec3(-0.8, -1.f, -1.4f));
	calibrationPoints.push_back(point3);

	CalibrationPoint point4(730, 542, osg::Vec3(1.f, -1.f, -1.3f));
	calibrationPoints.push_back(point4);

}