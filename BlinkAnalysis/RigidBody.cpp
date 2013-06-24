/**
 * RigidBody.cpp
 * Created By: Michael Feist
 */
#include "StdAfx.h"
#include "RigidBody.h"

RigidBody::RigidBody(void)
{
	this->id = 0;
	this->name[0] = '\0';

	this->transform = new osg::AutoTransform();
	this->worldID = -1;
    float MeanError = 0;
}


RigidBody::~RigidBody(void)
{
	
}

void RigidBody::addFrame(osg::Vec3 position, osg::Vec4 rotation)
{
	this->position = position;
	this->rotation = osg::Quat(rotation);

	if (this->transform)
	{
		this->transform->setPosition(position);
		this->transform->setRotation(rotation);
	}
}

