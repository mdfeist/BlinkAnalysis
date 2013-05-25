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

		CalibrationPoint(int pixel_x, int pixel_y, 
			osg::Vec3 from, osg::Vec3 to,
			osg::Matrix head_inverse) {
			this->pixel_x = pixel_x;
			this->pixel_y = pixel_y;
			this->ray = head_inverse*(to - from);
			this->ray.normalize();
			this->ray = this->ray/this->ray.z();
		}

		osg::Vec3 getRay() { return this->ray; }
		int getX() { return this->pixel_x; }
		int getY() { return this->pixel_y; }
	};

	int rbHeadId;
	int rbViewingObjectId;
	osg::Vec3 eyeVector;

	static int fieldOfViewWidth;
	static int fieldOfViewHeight;

	char* getNameById(int id) {
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

	std::vector<CalibrationPoint> calibrationPoints;
public:
	EyeCalibration(void) { this->rbHeadId = -1; };
	~EyeCalibration(void) {};

	static void setFieldOfViewWidth(int width) { EyeCalibration::fieldOfViewWidth = width; }
	static int getFieldOfViewWidth() { return EyeCalibration::fieldOfViewWidth; }

	static void setFieldOfViewHeight(int height) { EyeCalibration::fieldOfViewHeight = height; }
	static int getFieldOfViewHeight() { return EyeCalibration::fieldOfViewHeight; }

	void setHeadId(int id) { this->rbHeadId = id; }
	int getHeadId() { return this->rbHeadId; }
	char* getHeadName()
	{
		if (this->rbHeadId < 0)
			return 0;

		return getNameById(this->rbHeadId);
	}

	void setViewingObjectId(int id) { this->rbViewingObjectId = id; }
	int getViewingObjectId() { return this->rbViewingObjectId; }
	char* getViewingObjectName()
	{
		if (this->rbViewingObjectId < 0)
			return 0;

		return getNameById(this->rbViewingObjectId);
	}
};