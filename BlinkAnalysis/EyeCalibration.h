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
		CalibrationPoint _p1, _p2;
	public:
		Segment() {}
		Segment(CalibrationPoint from, CalibrationPoint to) {
			_p1 = from;
			_p2 = to;
		}

		CalibrationPoint p1() { return _p1; }
		CalibrationPoint p2() { return _p2; }

		int x1() { return _p1.x(); }
		int y1() { return _p1.y(); }
		int x2() { return _p2.x(); }
		int y2() { return _p2.y(); }
	};

	int rbHeadId;
	int rbViewingObjectId;
	osg::Vec3 eyeVector;

	char* getNameById(int id);

	std::vector<CalibrationPoint> calibrationPoints;
	std::vector<Segment> convexHull;

	int center_x, center_y;

	bool isLess(CalibrationPoint a, CalibrationPoint b);
	bool isEdge(std::vector<CalibrationPoint> processingPoints, Segment edge);
	int isLeft(Segment segment, CalibrationPoint r);

	std::vector<Segment> calculateConvexHull(std::vector<CalibrationPoint> processingPoints);
	std::vector<Segment> getEdges(std::vector<CalibrationPoint> processingPoints);
	int getLineIntersection(Segment edge1, Segment edge2);
	CalibrationPoint getClosestPoint(CalibrationPoint a, CalibrationPoint b, CalibrationPoint point, bool segmentClamp);

	struct ComparePoints : std::binary_function<CalibrationPoint, CalibrationPoint, bool> {
		ComparePoints(EyeCalibration * cal) : _cal(cal) {}
		bool operator() (CalibrationPoint a, CalibrationPoint b) const {
			return _cal->isLess(a, b);
		}

		EyeCalibration * _cal;
	};

	struct ComparePointsDistanceFrom : std::binary_function<CalibrationPoint, CalibrationPoint, bool> {
		ComparePointsDistanceFrom(EyeCalibration * cal, CalibrationPoint point) : _cal(cal), _point(point) {}
		bool operator() (CalibrationPoint a, CalibrationPoint b) {
			float distanceA = (_point.x()-a.x())*(_point.x()-a.x()) + (_point.y()-a.y())*(_point.y()-a.y());
			float distanceB = (_point.x()-b.x())*(_point.x()-b.x()) + (_point.y()-b.y())*(_point.y()-b.y());

			if (distanceA > distanceB)
				return true;

			return false;
		}

		EyeCalibration * _cal;
		CalibrationPoint _point;
	};

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
	int pointInPolygon(std::vector<Segment> hull, CalibrationPoint point);

	void testPointInPolygon(CalibrationPoint point);
	void createTestData();
};