/**
 * ClientHandler.h
 * Created By: Michael Feist
 */
#pragma once
#include "stdafx.h"
#include <Windows.h>
#include <process.h>

#include <map>

#include "RigidBody.h"

#include "NatNetTypes.h"
#include "NatNetClient.h"


typedef std::map<int, Marker*>::iterator labeledmarker_iterator;

/*
 * The ClientHandler Class handles multiple
 * RigidBody's. You are able to add, get,
 * and update RigidBody's according to 
 * their given id.
 */
class ClientHandler
{
private:
	// Mutex used to lock the ClientHandler.
	// Allowing multiple threads to read/write 
	// data without errors.
	HANDLE g_hMutex;

	// Pointer to NatNetClient
	NatNetClient* client;
	// Used to see if the NatNetClient is connected to a server
	bool natNetServerRunning;
	// A map to store all the attached Rigid Bodies
	std::map<int, RigidBody*> rigidBodies;
	int rigidBodyTool;
	// map to store all other markers
	std::map<int, Marker*> labeledMarkers;

	// OptiTrack Server Settings 
	char cLocalIPAddress[128];					// Your local IP Address
	char cOtptiTrackServerIPAddress[128];		// The OptiTrack servers Ip Address

	unsigned int iOptiTrackServerDataPort;		// The Data port of the OptiTrack server
	unsigned int iOptiTrackServerCommandPort;	// The Command port of the OptiTrack server

	int iOptiTrackConnectionType;				// The Connection Type of the OptiTrack server

	// Dikablis
	// Width and Height of the Field of View for the Dikablis
	static int DikablisViewingWidth;
	static int DikablisViewingHeight;
	static int DikablisViewingMargin;
	static int DikablisViewingSize;

	// Used to store the calibrated eye vectors
	float *dikablisEyeVectorArray;
	
public:
	ClientHandler(void);						// Constructor
	~ClientHandler(void);						// Destructor

	// Lock the client so data cannot be changed while doing updates
	bool lock() { 
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

	// Unlocks the client allowing threads to change its data
	void unlock() {
		// Release the utex
		ReleaseMutex(g_hMutex);
	}

	// Set/Get the NatNetClient
	void setClient(NatNetClient* client) { this->client = client; }
	NatNetClient* getClient() { return this->client; }

	// Checks if the client is still connected to the server
	bool isNatNetServerRunning() { return this->natNetServerRunning; }
	// Tells the client to stop running
	void setNatNetServerRunning(bool running) { this->natNetServerRunning = running; }

	// Setters/Getters for OptiTrack settings
	// Your local Ip Address
	void setLocalIpAddress(const char *ip) { strncpy_s(cLocalIPAddress, 128, ip, 128); }
	void getLocalIpAddress(char *ip) { strncpy_s(ip, 128, cLocalIPAddress, 128); }

	// The OptiTrack servers Ip Address
	void setOptiTrackServerIpAddress(const char *ip) { strncpy_s(cOtptiTrackServerIPAddress, 128, ip, 128); }
	void getOptiTrackServerIpAddress(char *ip) { strncpy_s(ip, 128, cOtptiTrackServerIPAddress, 128); }

	// The Data port of the OptiTrack server
	void setOptiTrackServerDataPort(unsigned int port) { iOptiTrackServerDataPort = port; }
	int getOptiTrackServerDataPort() { return iOptiTrackServerDataPort; }

	// The Command port of the OptiTrack server
	void setOptiTrackServerCommandPort(unsigned int port) { iOptiTrackServerCommandPort = port; }
	int getOptiTrackServerCommandPort() { return iOptiTrackServerCommandPort; }

	// The Connection Type of the OptiTrack server
	void setOptiTrackServerConnectionType(int type) { iOptiTrackConnectionType = type; }
	int getOptiTrackServerConnectionType() { return iOptiTrackConnectionType; }

	// Add a RigidBody to the ClientHandler
	bool addRigidBody(int id, RigidBody* rigidBody);
	// Get RigidBody based on it's id
	RigidBody* getRigidBody(int id);
	// Get all RigidBody's in a map
	std::map<int, RigidBody*>* getRigidBodyMap();
	// Updates the RigidBody's transformation based on it's id
	void transformRigidBody(int id, osg::Vec3 pos, osg::Vec4 rot);

	// Labeled Markers
	bool addLabeledMarker(int id, Marker* marker);
	Marker* getLabeledMarker(int id);
	std::map<int, Marker*>* getLabeledMarkerMap();
	void clearLabeledMarkers();
	void clearStaleMarkers();

	// Rigid Body Tool for defining objects
	void setRigidBodyTool(int id) { rigidBodyTool = id; }
	int getRigidBodyTool() { return rigidBodyTool; }

	// Dikablis
	static int getDikablisViewingWidth() { return DikablisViewingWidth; }
	static int getDikablisViewingHeight() { return DikablisViewingHeight; }
	static int getDikablisViewingMargin() { return DikablisViewingMargin; }
	static int getDikablisViewingSize() { return DikablisViewingSize; }

	void setRay(osg::Vec3 ray, int x, int y);
	osg::Vec3 getRay(int x, int y);
	void save();
};

