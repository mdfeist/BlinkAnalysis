#pragma once
#include "stdafx.h"
#include "AppData.h"

#include <osg/Vec3>

class EyeCalibration {
private:
	int rbHeadId;
	osg::Vec3 eyeVector;

	static int hoirzontalSizeForTheFieldOfView;
	static int verticalSizeForTheFieldOfView;
public:
	EyeCalibration(void) { this->rbHeadId = -1; };
	~EyeCalibration(void) {};

	void setHeadId(int id) { this->rbHeadId = id; }
	int getHeadId() { return this->rbHeadId; }
	char* getHeadName()
	{
		if (this->rbHeadId < 0)
			return 0;

		ClientHandler* client = AppData::getInstance()->getClient();

		if (client)
		{
			RigidBody* body = client->getRigidBody(this->rbHeadId);
			if (body)
			{
				return body->getName();
			}
		}

		return 0;
	}
};