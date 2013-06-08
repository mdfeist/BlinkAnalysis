#include "StdAfx.h"
#include "EyeCalibration.h"
#include "Dikablis.h"

#include "EyeCalibrationWizardFormController.h"

#include <algorithm>    // std::sort
#include <iostream>
#include <fstream>

#include <osg/Matrix>

EyeCalibration::EyeCalibration(void) { 
	this->rbHeadId = -1; 
	this->rbViewingObjectId = -1; 

	this->center_x = 0;
	this->center_y = 0;
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

bool EyeCalibration::isLess(CalibrationPoint a, CalibrationPoint b)
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

bool EyeCalibration::isEdge(std::vector<CalibrationPoint> processingPoints, Segment edge)
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

std::vector<EyeCalibration::Segment> EyeCalibration::calculateConvexHull(std::vector<CalibrationPoint> processingPoints) {
	// Edges
	std::vector<Segment> segments;

	// Ordered Point
	std::vector<CalibrationPoint> orderedPoints(processingPoints);

	// Sort Points
	std::sort (orderedPoints.begin(), orderedPoints.end(), ComparePoints(this));

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
		std::vector<CalibrationPoint> processingPoints(orderedPoints);
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

bool EyeCalibration::calibrate() {
	char buf[512];

	// Print starting message
	EyeCalibrationWizardFormController::getInstance()->calibrationOutputLog("Starting Calibration\n");

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
		osg::Vec3 ray = point.getRay();

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

	// Ordered Point
	std::vector<CalibrationPoint> orderedPoints(calibrationPoints);
	// Sort Points
	std::sort (orderedPoints.begin(), orderedPoints.end(), ComparePoints(this));

	// Calculate Convex Hull
	this->convexHull = calculateConvexHull(calibrationPoints);

	// Print each segment information
	for (unsigned int i = 0; i < convexHull.size(); i++) {
		Segment segment = convexHull.at(i);
		sprintf_s(buf, "Edge %d: From (%d, %d) to (%d, %d)\n", 
			i + 1,
			segment.x1(), segment.y1(),
			segment.x2(), segment.y2());
		EyeCalibrationWizardFormController::getInstance()->calibrationOutputLog(buf);
	}

	// Group Points
	std::vector<CalibrationPoint> convexHullPoints;
	std::vector<CalibrationPoint> innerPoints;
	std::vector<CalibrationPoint> innerUnknownPoints;
	std::vector<CalibrationPoint> outerUnknownPoints;

	for (unsigned int i = 0; i < orderedPoints.size(); i++) {
		CalibrationPoint point = orderedPoints.at(i);

		if (pointInPolygon(convexHull, point) < 0)
			innerPoints.push_back(point);
		else
			convexHullPoints.push_back(point);
	}

	// Print Inner points
	for (unsigned int i = 0; i < innerPoints.size(); i++) {
		CalibrationPoint point = innerPoints.at(i);

		sprintf_s(buf, "Inner Point %d: (%d, %d)\n", 
			i + 1,
			point.x(), point.y());
		EyeCalibrationWizardFormController::getInstance()->calibrationOutputLog(buf);
	}

	// Print Convex Hull points
	for (unsigned int i = 0; i < convexHullPoints.size(); i++) {
		CalibrationPoint point = convexHullPoints.at(i);

		sprintf_s(buf, "Convex Hull Point %d: (%d, %d)\n", 
			i + 1,
			point.x(), point.y());
		EyeCalibrationWizardFormController::getInstance()->calibrationOutputLog(buf);
	}

	unsigned int margin =  + 2*ClientHandler::getDikablisViewingMargin();
	for (unsigned int j = 0; j < ClientHandler::getDikablisViewingHeight() + margin; j++) {
		for (unsigned int i = 0; i < ClientHandler::getDikablisViewingWidth() + margin; i++) {
			int x = i - ClientHandler::getDikablisViewingMargin();
			int y = j - ClientHandler::getDikablisViewingMargin();

			// Create point
			CalibrationPoint point(x, y, osg::Vec3(0.f, 0.f, 0.f));

			// Check if point has an already known ray
			bool alreadyKnown = false;
			for (unsigned int i = 0; i < orderedPoints.size(); i++) {
				CalibrationPoint knownPoint = orderedPoints.at(i);

				if ((knownPoint.x() == point.x()) &&
					(knownPoint.y() == point.y())) {
						alreadyKnown = true;
						break;
				}
			}

			if (!alreadyKnown) {
				// Check if point is inside the convex hull
				if (pointInPolygon(convexHull, point) <= 0) {
					innerUnknownPoints.push_back(point);
				} else {
					outerUnknownPoints.push_back(point);
				}
			}
		}
	}

	// Print Convex Hull
	for (unsigned int j = 0; j < ClientHandler::getDikablisViewingHeight() + margin; j+=20) {
		for (unsigned int i = 0; i < ClientHandler::getDikablisViewingWidth() + margin; i+=20) {
			int x = i - ClientHandler::getDikablisViewingMargin();
			int y = j - ClientHandler::getDikablisViewingMargin();

			// Create point
			CalibrationPoint point(x, y, osg::Vec3(0.f, 0.f, 0.f));

			// Check if point is inside the convex hull
			if (pointInPolygon(convexHull, point) <= 0) {
				EyeCalibrationWizardFormController::getInstance()->calibrationOutputLog("1");
			} else {
				EyeCalibrationWizardFormController::getInstance()->calibrationOutputLog("0");
			}
		}
		EyeCalibrationWizardFormController::getInstance()->calibrationOutputLog("\n");
	}

	// Save calibrarion
	/*
	bool fileOpen = false;
	std::ofstream myfile ("C:\\Users\\mdfeist\\Desktop\\segments.txt");
	if (myfile.is_open())
	{
		fileOpen = true;
	}
	*/

	// Calculate Inner Interpolation
	for (int innerPointIndex = innerUnknownPoints.size() - 1; innerPointIndex >= 0; innerPointIndex--) {
		CalibrationPoint innerPoint = innerUnknownPoints.at(innerPointIndex);

		std::vector<CalibrationPoint> boundingPoints;
		std::vector<Segment> boundingEdges;

		std::vector<CalibrationPoint> possibleBoundingPoints(calibrationPoints);
		std::sort (possibleBoundingPoints.begin(), possibleBoundingPoints.end(), ComparePointsDistanceFrom(this, innerPoint));
		
		for (unsigned int boundingIndex = 0; boundingIndex < 4; boundingIndex++) {
			boundingPoints.push_back(possibleBoundingPoints.back());
			possibleBoundingPoints.pop_back();
		}

		bool foundBoundingHull = false;
		while (!foundBoundingHull) {
			if (boundingPoints.size() != 4) {
				break;
			}

			// Get min and max
			CalibrationPoint 
				minX = boundingPoints.at(0), 
				minY = boundingPoints.at(0), 
				maxX = boundingPoints.at(0), 
				maxY = boundingPoints.at(0);

			for (unsigned int boundingIndex = 0; boundingIndex < boundingPoints.size(); boundingIndex++) {
				CalibrationPoint point = boundingPoints.at(boundingIndex);

				if (minX.x() > point.x())
					minX = point;

				if (minY.y() > point.y())
					minY = point;

				if (maxX.x() < point.x())
					maxX = point;

				if (maxY.y() < point.y())
					maxY = point;
			}

			// Get center of bounding polygon
			int boundingCenterX = (maxX.x() - minX.x())/2;
			int boundingCenterY = (maxY.y() - minY.y())/2;

			// Calculate Ray through center
			int ray_x = innerPoint.x() - boundingCenterX;
			int ray_y = innerPoint.y() - boundingCenterY;

			ray_x *= 1000;
			ray_y *= 1000;

			CalibrationPoint pointRayEnd(ray_x, ray_y, osg::Vec3(0.f, 0.f, 0.f));
			Segment ray(innerPoint, pointRayEnd);
		
			// Get bounding edges
			std::sort (boundingPoints.begin(), boundingPoints.end(), ComparePoints(this));
			boundingEdges.clear();

			for (unsigned int i = 0; i < boundingPoints.size(); i++) {
				if (i < boundingPoints.size() - 1) {
					boundingEdges.push_back( Segment(boundingPoints.at(i), boundingPoints.at(i + 1)) );
				} else {
					boundingEdges.push_back( Segment(boundingPoints.at(i), boundingPoints.at(0)) );
				}
			}

			// Used to check and see if point is contained in bounding points
			unsigned int collisionCount = 0;
			for (unsigned int i = 0; i < boundingEdges.size(); i++) {
				if ( getLineIntersection(ray, boundingEdges.at(i)) )
					collisionCount++;
			}

			// Print
			/*
			myfile << "Point (" << innerPoint.x() << ", " << innerPoint.y() << ")";
			if (collisionCount % 2 == 1) {
				myfile << " Bounded By ";
			} else {
				myfile << " Not Bounded By ";
			}

			for (unsigned int i = 0; i < boundingPoints.size(); i++) {
				CalibrationPoint point = boundingPoints.at(i);
				myfile << " (" << point.x() << ", " << point.y() << ")";
			}

			myfile << "\n";
			*/
			if (collisionCount % 2 == 1) {
				foundBoundingHull = true;
			} else {
				int closestEdge = -1;
				float closestDistance = -1.f;
				for (unsigned int i = 0; i < boundingEdges.size(); i++) {
					Segment edge = boundingEdges.at(i);
					CalibrationPoint closest = getClosestPoint(edge.p1(), edge.p2(), innerPoint, true);

					if (!(closest.x() == edge.x1() && closest.y() == edge.y1()) && 
						!(closest.x() == edge.x2() && closest.y() == edge.y2())) {
						float dif_x = closest.x()-innerPoint.x();
						float dif_y = closest.y()-innerPoint.y();

						float distance = (dif_x)*(dif_x) + (dif_y)*(dif_y);
						if (closestDistance < 0.f || closestDistance > distance) {
							closestDistance = distance;
							closestEdge = i;
						}
					}
				}

				if (closestEdge != -1) {
					Segment edge = boundingEdges.at(closestEdge);

					for (int i = boundingPoints.size() - 1; i >= 0; i--) {
						CalibrationPoint point = boundingPoints.at(i);

						if (!(point.x() == edge.x1() && point.y() == edge.y1()) && 
						!(point.x() == edge.x2() && point.y() == edge.y2())) {
							boundingPoints.erase(boundingPoints.begin()+i);
						}
					}

					if (possibleBoundingPoints.size() >= 2) {
						boundingPoints.push_back(possibleBoundingPoints.back());
						possibleBoundingPoints.pop_back();
						boundingPoints.push_back(possibleBoundingPoints.back());
						possibleBoundingPoints.pop_back();
					} else {
						break;
					}
				} else {
					break;
				}
			}
		}

		if (!foundBoundingHull) {
			outerUnknownPoints.push_back(innerPoint);
			innerUnknownPoints.erase(innerUnknownPoints.begin()+innerPointIndex);
		} else {
			CalibrationPoint closestPoints[4];
			for (unsigned int i = 0; i < boundingEdges.size(); i++) {
				Segment edge = boundingEdges.at(i);
				closestPoints[i] = getClosestPoint(edge.p1(), edge.p2(), innerPoint, true);
			}

			CalibrationPoint 
				minX = closestPoints[0], 
				minY = closestPoints[0], 
				maxX = closestPoints[0], 
				maxY = closestPoints[0];

			for (unsigned int i = 0; i < boundingEdges.size(); i++) {
				if (minX.x() > closestPoints[i].x())
					minX = closestPoints[i];

				if (minY.y() > closestPoints[i].y())
					minY = closestPoints[i];

				if (maxX.x() < closestPoints[i].x())
					maxX = closestPoints[i];

				if (maxY.y() < closestPoints[i].y())
					maxY = closestPoints[i];
			}

			float t;
			t = (innerPoint.x() - minX.x()) / (maxX.x() - minX.x());
			osg::Vec3 ray_x = minX.getRay() + (maxX.getRay() - minX.getRay()) * t;

			t = (innerPoint.y() - minY.y()) / (maxY.y() - minY.y());
			osg::Vec3 ray_y = minY.getRay() + (maxY.getRay() - minY.getRay()) * t;

			osg::Vec3 ray = (ray_x + ray_y) / 2.f;

			ClientHandler* client = AppData::getInstance()->getClient();

			if (client) {
				client->setRay(ray, innerPoint.x(), innerPoint.y());
			}
		}
	}

	//myfile.close();

	ClientHandler* client = AppData::getInstance()->getClient();

	if (client) {
		client->save();
	}

	EyeCalibrationWizardFormController::getInstance()->calibrationOutputLog("Done\n");

	return true;
}

std::vector<EyeCalibration::Segment> EyeCalibration::getEdges(std::vector<CalibrationPoint> processingPoints) {
	std::vector<Segment> edges;
	for (unsigned int i = 0; i < processingPoints.size(); i++) {
		for (unsigned int j = i + 1; j < processingPoints.size(); j++) {
			edges.push_back( Segment(processingPoints.at(i), processingPoints.at(j)) );
		}
	}

	return edges;
}

// Returns 1 if the lines intersect, otherwise 0. 
int EyeCalibration::getLineIntersection(Segment edge1, Segment edge2)
{
	int p0_x, p0_y, p1_x, p1_y, p2_x, p2_y, p3_x, p3_y;
	// Edge 1
	p0_x = edge1.x1();
	p0_y = edge1.y1();
	p1_x = edge1.x2();
	p1_y = edge1.y2();

	// Edge 2
	p2_x = edge2.x1();
	p2_y = edge2.y1();
	p3_x = edge2.x2();
	p3_y = edge2.y2();

    float s1_x, s1_y, s2_x, s2_y;
    s1_x = p1_x - p0_x;     s1_y = p1_y - p0_y;
    s2_x = p3_x - p2_x;     s2_y = p3_y - p2_y;

    float s, t;
    s = (-s1_y * (p0_x - p2_x) + s1_x * (p0_y - p2_y)) / (-s2_x * s1_y + s1_x * s2_y);
    t = ( s2_x * (p0_y - p2_y) - s2_y * (p0_x - p2_x)) / (-s2_x * s1_y + s1_x * s2_y);

    if (s >= 0 && s <= 1 && t >= 0 && t <= 1)
    {
        // Collision detected
        return 1;
    }

    return 0; // No collision
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

	osg::Vec3 ab_ray = b.getRay() - a.getRay();
	osg::Vec3 ray = a.getRay() + ab_ray * t;

	CalibrationPoint closest(closest_x, closest_y, ray);
	return closest;
}

int EyeCalibration::pointInPolygon(std::vector<Segment> hull, CalibrationPoint point) {

	unsigned int n = hull.size();

	if (n < 3)
		false;

	// loop through all edges of the polygon
	for (unsigned int i = 0; i < n; i++)
	{ 
		Segment segment = hull.at(i);

		int left = isLeft(segment, point);
		if(left >= 0)
			return left;
	}

	return -1;
}

void EyeCalibration::testPointInPolygon(CalibrationPoint point) {
	char buf[512];

	if (pointInPolygon(convexHull, point) < 0) {
		sprintf_s(buf, "Point (%d, %d) is inside.\n", point.x(), point.y()); 
		EyeCalibrationWizardFormController::getInstance()->calibrationOutputLog(buf);
	} else {
		sprintf_s(buf, "Point (%d, %d) is outside.\n", point.x(), point.y()); 
		EyeCalibrationWizardFormController::getInstance()->calibrationOutputLog(buf);
	}
}

void EyeCalibration::createTestData() {

	CalibrationPoint point1(10, 5, osg::Vec3(-10.f, 10.f, 1.f));
	calibrationPoints.push_back(point1);

	CalibrationPoint point2(322, 50, osg::Vec3(-2.f, 12.f, 1.f));
	calibrationPoints.push_back(point2);

	CalibrationPoint point3(700, 25, osg::Vec3(12.f, 8.f, 1.f));
	calibrationPoints.push_back(point3);

	CalibrationPoint point4(15, 280, osg::Vec3(-8.f, 2.f, 1.f));
	calibrationPoints.push_back(point4);

	CalibrationPoint point5(374, 180, osg::Vec3(5.f, -2.f, 1.f));
	calibrationPoints.push_back(point5);

	CalibrationPoint point6(742, 320, osg::Vec3(14.f, -1.f, 1.f));
	calibrationPoints.push_back(point6);

	CalibrationPoint point7(4, 480, osg::Vec3(-12.f, -10.f, 1.f));
	calibrationPoints.push_back(point7);

	CalibrationPoint point8(280, 465, osg::Vec3(0.f, -9.f, 1.f));
	calibrationPoints.push_back(point8);

	CalibrationPoint point9(724, 520, osg::Vec3(11.f, -12.f, 1.f));
	calibrationPoints.push_back(point9);
}