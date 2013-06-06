#pragma once
#include "stdafx.h"
#include "AppData.h"

#include <vector>
#include <osg/Vec3>

class EyeCalibration {
private:
	class CalibrationPoint {
	private:
		int pixel_x, pixel_y;
		osg::Vec3 ray;
	public:
		CalibrationPoint() {}
		CalibrationPoint(int pixel_x, int pixel_y, osg::Vec3 ray) {
			this->pixel_x = pixel_x;
			this->pixel_y = pixel_y;
			this->ray = ray;
		}

		osg::Vec3 getRay() { return this->ray; }
		int& x() { return this->pixel_x; }
		int& y() { return this->pixel_y; }
	};

	class Segment {
	private:
		CalibrationPoint p1, p2;
	public:
		Segment() {}
		Segment(CalibrationPoint from, CalibrationPoint to) {
			this->p1 = from;
			this->p2 = to;
		}

		int x1() { return this->p1.x(); }
		int y1() { return this->p1.y(); }
		int x2() { return this->p2.x(); }
		int y2() { return this->p2.y(); }
	};

	int rbHeadId;
	int rbViewingObjectId;
	osg::Vec3 eyeVector;

	char* getNameById(int id);

	std::vector<CalibrationPoint> calibrationPoints;
	std::vector<Segment> segments;

	int center_x, center_y;

	bool isLess(CalibrationPoint a, CalibrationPoint b);
	bool isEdge(std::vector<CalibrationPoint> processingPoints, Segment edge);
	int isLeft(Segment segment, CalibrationPoint r);

public:
	EyeCalibration(void);
	~EyeCalibration(void) {};
	
	void setHeadId(int id) { this->rbHeadId = id; }
	int getHeadId() { return this->rbHeadId; }
	char* getHeadName() { return getNameById(this->rbHeadId); }

	void setViewingObjectId(int id) { this->rbViewingObjectId = id; }
	int getViewingObjectId() { return this->rbViewingObjectId; }
	char* getViewingObjectName() { return getNameById(this->rbViewingObjectId); }

	bool addPoint();
	bool calibrate();
	bool pointInPolygon(CalibrationPoint point);

	bool operator()(CalibrationPoint a, CalibrationPoint b) {
		return isLess(a, b);
	}

	void testPointInPolygon(CalibrationPoint point);
	void createTestData();
};