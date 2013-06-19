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

	this->transform = 0;
	this->objectTransform = 0;
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
	if (this->objectTransform)
	{
		this->objectTransform->setPosition(position);
		this->objectTransform->setRotation(rotation);
	}
}

osg::AutoTransform* RigidBody::getObjectTransform()
{
	if (!this->objectTransform)
	{
		this->objectTransform = new osg::AutoTransform();
		this->objectTransform->setPosition(position);
		this->objectTransform->setRotation(rotation);
	}
	return objectTransform;
}

