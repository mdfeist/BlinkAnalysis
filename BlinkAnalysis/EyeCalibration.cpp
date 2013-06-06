#include "StdAfx.h"
#include "EyeCalibration.h"
#include "Dikablis.h"

#include "EyeCalibrationWizardFormController.h"

#include <algorithm>    // std::sort
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
	EyeCalibrationWizardFormController::getInstance()->calibrationOutputLog("Ordering Points ...\n");
	std::sort (orderedPoints.begin(), orderedPoints.end(), *this);
	EyeCalibrationWizardFormController::getInstance()->calibrationOutputLog("Ordered Points\n");

	// Clearing previous segments
	segments.clear();
	EyeCalibrationWizardFormController::getInstance()->calibrationOutputLog("Cleared Previous Convex Hull\n");

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
	
	// Calculate Convex Hull
	{
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
	}

	// Print each segment information
	for (unsigned int i = 0; i < segments.size(); i++) {
		Segment segment = segments.at(i);
		sprintf_s(buf, "Edge %d: From (%d, %d) to (%d, %d)\n", 
			i + 1,
			segment.x1(), segment.y1(),
			segment.x2(), segment.y2());
		EyeCalibrationWizardFormController::getInstance()->calibrationOutputLog(buf);
	}

	// Group Points
	std::vector<CalibrationPoint> convexHullPoints;
	std::vector<CalibrationPoint> innerPoints;

	for (unsigned int i = 0; i < orderedPoints.size(); i++) {
		CalibrationPoint point = orderedPoints.at(i);

		if (pointInPolygon(point))
			innerPoints.push_back(point);
		else
			convexHullPoints.push_back(point);
	}

	// Print Inner points
	for (unsigned int i = 0; i < innerPoints.size(); i++) {
		CalibrationPoint point = innerPoints.at(i);

		sprintf_s(buf, "Inner Point %d: (%d, %d))\n", 
			i + 1,
			point.x(), point.y());
		EyeCalibrationWizardFormController::getInstance()->calibrationOutputLog(buf);
	}

	// Print Convex Hull points
	for (unsigned int i = 0; i < convexHullPoints.size(); i++) {
		CalibrationPoint point = convexHullPoints.at(i);

		sprintf_s(buf, "Convex Hull Point %d: (%d, %d))\n", 
			i + 1,
			point.x(), point.y());
		EyeCalibrationWizardFormController::getInstance()->calibrationOutputLog(buf);
	}

	CalibrationPoint pointIn(740, 320, osg::Vec3(0.f, 0.f, 0.f));
	testPointInPolygon(pointIn);

	CalibrationPoint pointOut(232, 2, osg::Vec3(0.f, 0.f, 0.f));
	testPointInPolygon(pointOut);

	return true;
}

bool EyeCalibration::pointInPolygon(CalibrationPoint point) {

	unsigned int n = segments.size();

	if (n < 3)
		false;

	// loop through all edges of the polygon
	for (unsigned int i = 0; i < n; i++)
	{ 
		Segment segment = segments.at(i);

		if(isLeft(segment, point) >= 0)
			return false;
	}

	return true;
}

void EyeCalibration::testPointInPolygon(CalibrationPoint point) {
	char buf[512];

	if (pointInPolygon(point)) {
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