/**
 * ClientHandler.cpp
 * Created By: Michael Feist
 */
#include "StdAfx.h"
#include "ClientHandler.h"

#include <string.h>

#include <iostream>
#include <fstream>
#include <windows.h>
 
using namespace std;

// Dikablis
unsigned long ClientHandler::DikablisViewingWidth = 768;
unsigned long ClientHandler::DikablisViewingHeight = 576;

unsigned long ClientHandler::DikablisViewingMargin = 100;

unsigned long ClientHandler::DikablisViewingSize = 3 * ((DikablisViewingWidth + 2*DikablisViewingMargin) * (DikablisViewingHeight + 2*DikablisViewingMargin));

// Constructor: Sets the default values for the ClientHandler
ClientHandler::ClientHandler(void)
{ 
	this->client = 0;
	this->natNetServerRunning = false;
	
	this->iOptiTrackConnectionType = ConnectionType_Multicast;
	
	this->iOptiTrackServerCommandPort = 1510;
	this->iOptiTrackServerDataPort = 1511;

	this->setLocalIpAddress("127.0.0.1");
	this->setOptiTrackServerIpAddress("127.0.0.1");
	
	this->g_hMutex = CreateMutex(
		NULL,
		//(LPSECURITY_ATTRIBUTES)SYNCHRONIZE, 
		FALSE, 
		NULL);

	this->rigidBodyTool = -1;

	this->dikablisEyeVectorArray = (float*) malloc(sizeof(float) * ClientHandler::DikablisViewingSize);

	this->headid = -1;
}

// Cleans up the ClientHandler
ClientHandler::~ClientHandler(void)
{
	// Free the mutex
	CloseHandle(this->g_hMutex);

	if (this->dikablisEyeVectorArray != NULL)
		free(this->dikablisEyeVectorArray);

	clearLabeledMarkers();
	clearRigidBodyMap();
}
bool ClientHandler::lock() {
	// Request ownership of mutex
	DWORD  dwWaitResult;
	while(true)
	{
		// Wait for Mutex to be free
		dwWaitResult = WaitForSingleObject(g_hMutex, INFINITE);
		switch (dwWaitResult) 
		{
			// The thread got ownership of the mutex
		case WAIT_OBJECT_0: 
			return true;
			break; 

			// The thread got ownership of an abandoned mutex
			// The database is in an indeterminate state
		case WAIT_ABANDONED: 
			return false; 
			break;
		}
	}

	return false;
}

void ClientHandler::setRayCalibration(float *vectorArray) {
	if (this->dikablisEyeVectorArray != NULL &&
		vectorArray != NULL) {
		for (unsigned int i = 0; i < DikablisViewingSize; i++) {
			this->dikablisEyeVectorArray[i] = vectorArray[i];
		}
	}
}

osg::Vec3 ClientHandler::getRay(int x, int y) {
	osg::Vec3 ray;

	if (this->dikablisEyeVectorArray != NULL) {
		int i = x + DikablisViewingMargin;
		int j = y + DikablisViewingMargin;

		int loc = 3*((j*(DikablisViewingWidth+2*DikablisViewingMargin)) + i);

		if (loc >= 0 && loc < (int)DikablisViewingSize) {
			ray.x() = this->dikablisEyeVectorArray[loc + 0];
			ray.y() = this->dikablisEyeVectorArray[loc + 1];
			ray.z() = this->dikablisEyeVectorArray[loc + 2];
		}
	}

	return ray;
}

void ClientHandler::setHeadId(int id) {
	this->headid = id;
}

int ClientHandler::getHeadId() {
	return this->headid;
}

RigidBody* ClientHandler::getHead() {
	return getRigidBody(this->headid);
}

// Add a Rigid Body to the ClientHandler
bool ClientHandler::addRigidBody(int id, RigidBody* rigidBody)
{
	// Try to insert the Rigid Body
	std::pair<std::map<int,RigidBody*>::iterator,bool> ret;
	ret = this->rigidBodies.insert ( std::pair<int, RigidBody*>(id, rigidBody) );

	// Check if insertion was successful
	if (ret.second == false)
		return false;

	// If insertion was successful return true
	return true;
}

// Get Rigid Body based on ID
RigidBody* ClientHandler::getRigidBody(int id)
{
	// Try to find the Rigid Body
	std::map<int, RigidBody*>::iterator ret;
	ret = this->rigidBodies.find(id);

	// If not found return NULL
	if ( ret == this->rigidBodies.end())
		return 0;

	// If found return the Rigid Body
	return ret->second;
}

// Update the Position and Orientation of a Rigid Body based on it's Id
void ClientHandler::transformRigidBody(int id, osg::Vec3 pos, osg::Vec4 rot)
{
	// Find the Rigid Body based on its Id
	std::map<int, RigidBody*>::iterator ret;
	ret = this->rigidBodies.find(id);

	// If Rigid Body was not found return
	if ( ret == this->rigidBodies.end())
		return;

	// If the Rigid Body was found update its Position and Orientation
	ret->second->addFrame(pos, rot);
}

// Return the map of all the Rigid Bodies
std::map<int, RigidBody*>* ClientHandler::getRigidBodyMap()
{
	return &this->rigidBodies;
}

void ClientHandler::clearRigidBodyMap()
{
	for (std::map<int, RigidBody*>::iterator it=rigidBodies.begin(); it!=rigidBodies.end(); ++it)
	{
		delete it->second;
	}
}

bool ClientHandler::addLabeledMarker(int id, Marker* marker)
{
	std::pair<labeledmarker_iterator, bool> ret;
	ret = labeledMarkers.insert(std::pair<int, Marker*>(id, marker));

	return (ret.second == false) ? false : true;
}

Marker* ClientHandler::getLabeledMarker(int id)
{
	labeledmarker_iterator itr = labeledMarkers.find(id);

	return (itr == labeledMarkers.end()) ? NULL : itr->second;
}

std::map<int, Marker*>* ClientHandler::getLabeledMarkerMap()
{
	return &labeledMarkers;
}

void ClientHandler::clearLabeledMarkers()
{
	for (labeledmarker_iterator itr = labeledMarkers.begin(); itr != labeledMarkers.end(); itr++)
	{
		delete itr->second;
	}

	labeledMarkers.clear();
}

void ClientHandler::clearStaleMarkers()
{
	for (labeledmarker_iterator itr = labeledMarkers.begin(); itr != labeledMarkers.end();)
	{
		if (!itr->second->isUpdated())
		{
			delete itr->second;
			labeledMarkers.erase(itr++);
		}
		else
		{
			++itr;
		}
	}
}

void ClientHandler::addRigidBodyMarker(Marker marker) {
	rigidBodyMarkers.insert(marker);
}

bool ClientHandler::doesRigidBodyMarkerExist(Marker* marker) {
	std::set<Marker>::iterator ret;
	ret = rigidBodyMarkers.find((*marker));

	return (ret != rigidBodyMarkers.end());
}

void ClientHandler::clearRigidBodyMarkers() {
	rigidBodyMarkers.clear();
}

