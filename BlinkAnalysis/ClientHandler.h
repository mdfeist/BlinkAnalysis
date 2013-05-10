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

/*
 * The ClientHandler Class handles multiple
 * RigidBody's. You are able to add, get,
 * and update RigidBody's according to 
 * their given id.
 */
class ClientHandler
{
private:	
	HANDLE g_hMutex;

	NatNetClient* client;
	bool natNetServerRunning;
	std::map<int, RigidBody*> _rigidBodies;

	// OptiTrack Server Settings 
	char cLocalIPAddress[128];
	char cOtptiTrackServerIPAddress[128];

	unsigned int iOptiTrackServerDataPort;
	unsigned int iOptiTrackServerCommandPort;

	int iOptiTrackConnectionType;

public:
	ClientHandler(void);
	~ClientHandler(void);

	bool lock() { 
		// Request ownership of mutex
		DWORD  dwWaitResult;
		while(true)
		{
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

	void unlock() {
		// Release the mutex
		ReleaseMutex(g_hMutex);
	}

	void setClient(NatNetClient* client) { this->client = client; }
	NatNetClient* getClient() { return this->client; }

	bool isNatNetServerRunning() { return this->natNetServerRunning; }
	void setNatNetServerRunning(bool running) { this->natNetServerRunning = running; }

	// Setters/Getters for OptiTrack settings
	void setLocalIpAddress(const char *ip) { strncpy_s(cLocalIPAddress, 128, ip, 128); }
	void getLocalIpAddress(char *ip) { strncpy_s(ip, 128, cLocalIPAddress, 128); }

	void setOptiTrackServerIpAddress(const char *ip) { strncpy_s(cOtptiTrackServerIPAddress, 128, ip, 128); }
	void getOptiTrackServerIpAddress(char *ip) { strncpy_s(ip, 128, cOtptiTrackServerIPAddress, 128); }

	void setOptiTrackServerDataPort(unsigned int port) { iOptiTrackServerDataPort = port; }
	int getOptiTrackServerDataPort() { return iOptiTrackServerDataPort; }

	void setOptiTrackServerCommandPort(unsigned int port) { iOptiTrackServerCommandPort = port; }
	int getOptiTrackServerCommandPort() { return iOptiTrackServerCommandPort; }

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
};

