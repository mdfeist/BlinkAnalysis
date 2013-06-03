#include "StdAfx.h"
#include "EyeCalibration.h"

#include <osg/Matrix>

EyeCalibration::EyeCalibration(void) { 
	this->rbHeadId = -1; 
	this->rbViewingObjectId = -1; 
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