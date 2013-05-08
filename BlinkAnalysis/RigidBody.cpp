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

	this->nMarkers = 0;
	this->Markers = 0;
    this->MarkerIDs = 0;
    this->MarkerSizes = 0;
    float MeanError = 0;
}


RigidBody::~RigidBody(void)
{
	if (this->Markers)
		free(this->Markers);
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