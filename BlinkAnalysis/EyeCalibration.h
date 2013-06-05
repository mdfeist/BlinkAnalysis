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
		CalibrationPoint(int pixel_x, int pixel_y, osg::Vec3 ray) {
			this->pixel_x = pixel_x;
			this->pixel_y = pixel_y;
			this->ray = ray;
		}

		osg::Vec3 getRay() { return this->ray; }
		int getX() { return this->pixel_x; }
		int getY() { return this->pixel_y; }
	};

	int rbHeadId;
	int rbViewingObjectId;
	osg::Vec3 eyeVector;

	char* getNameById(int id);

	std::vector<CalibrationPoint> calibrationPoints;
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
	void calibrate();
};