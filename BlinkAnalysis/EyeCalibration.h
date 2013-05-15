#pragma once
#include "stdafx.h"

#include <osg/Vec3>

class EyeCalibration {
private:
	int rbHeadId;

	osg::Vec3 eyeVector;

public:
	EyeCalibration(void) { this->rbHeadId = -1; };
	~EyeCalibration(void) {};

	void setHeadId(int id) { this->rbHeadId = id; }
	int getHeadId() { return this->rbHeadId; }
};