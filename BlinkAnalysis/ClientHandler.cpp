/**
 * ClientHandler.cpp
 * Created By: Michael Feist
 */
#include "StdAfx.h"
#include "ClientHandler.h"

#include <string.h>

ClientHandler::ClientHandler(void)
{ 
	this->client = 0;
	this->natNetServerRunning = false;
	
	this->iOptiTrackConnectionType = ConnectionType_Multicast;
	
	this->iOptiTrackServerCommandPort = 1510;
	this->iOptiTrackServerDataPort = 1511;

	this->setLocalIpAddress("127.0.0.1");
	this->setOptiTrackServerIpAddress("127.0.0.1");
}

ClientHandler::~ClientHandler(void)
{
}

bool ClientHandler::addRigidBody(int id, RigidBody* rigidBody)
{
	std::pair<std::map<int,RigidBody*>::iterator,bool> ret;
	ret = _rigidBodies.insert ( std::pair<int, RigidBody*>(id, rigidBody) );

	if (ret.second == false)
		return false;

	return true;
}

RigidBody* ClientHandler::getRigidBody(int id)
{
	std::map<int, RigidBody*>::iterator ret;
	ret = _rigidBodies.find(id);

	if ( ret == _rigidBodies.end())
		return 0;

	return ret->second;
}

void ClientHandler::transformRigidBody(int id, osg::Vec3 pos, osg::Vec4 rot)
{
	std::map<int, RigidBody*>::iterator ret;
	ret = _rigidBodies.find(id);

	if ( ret == _rigidBodies.end())
		return;

	ret->second->addFrame(pos, rot);
}

std::map<int, RigidBody*>* ClientHandler::getRigidBodyMap()
{
	return &_rigidBodies;
}