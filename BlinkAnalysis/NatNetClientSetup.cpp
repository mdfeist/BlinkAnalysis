/**
 * NatNetClient.cpp
 * Original code from NatNetSDK2.2 SampleClient.
 * Modified By: Michael Feist
 */
#include "StdAfx.h"

#include "NatNetClientSetup.h"

#include <Windows.h>
#include <stdio.h>
#include <math.h>

#include <tchar.h>
#include <conio.h>

#include <osg/AutoTransform>

#include "NatNetTypes.h"
#include "NatNetClient.h"

#include "MainFormController.h"

#pragma warning( disable : 4996 )

// receives data from the server
void __cdecl DataHandler(sFrameOfMocapData* data, void* pUserData);
// receives NatNet error messages
void __cdecl MessageHandler(int msgType, char* msg);
// Establish a NatNet Client connection
int initClient(ClientHandler** theClient, int iConnectionType);
// Resets the NatNet Client connection
void resetClient(ClientHandler** theClient);

unsigned int MyServersDataPort = 1511;
unsigned int MyServersCommandPort = 1510;

char szMyIPAddress[128] = "192.168.1.3";
char szServerIPAddress[128] = "192.168.1.3";

int NatNetClientSetup::createClient(ClientHandler** theClient)
{
	int iResult;
    int iConnectionType = ConnectionType_Multicast;

	iConnectionType = (*theClient)->getOptiTrackServerConnectionType();

	MyServersCommandPort = (*theClient)->getOptiTrackServerCommandPort();
	MyServersDataPort = (*theClient)->getOptiTrackServerDataPort();

	(*theClient)->getLocalIpAddress(szMyIPAddress);
	(*theClient)->getOptiTrackServerIpAddress(szServerIPAddress);

	char buf[2048];

	sprintf_s(buf, "Connecting to Server...\n");
	MainFormController::getInstance()->optiTrackOutputLog(buf);

	if (iConnectionType == ConnectionType_Unicast) {
		sprintf_s(buf, "Connection Type: Unicast\n");
		MainFormController::getInstance()->optiTrackOutputLog(buf);
	} else if (iConnectionType == ConnectionType_Multicast) {
		sprintf_s(buf, "Connection Type: Multicast\n");
		MainFormController::getInstance()->optiTrackOutputLog(buf);
	} else {
		sprintf_s(buf, "Connection Type: Unknown\n");
		MainFormController::getInstance()->optiTrackOutputLog(buf);
	}

	sprintf_s(buf, "Command port of server: %d\n", MyServersCommandPort);
	MainFormController::getInstance()->optiTrackOutputLog(buf);

	sprintf_s(buf, "Data port of server: %d\n", MyServersDataPort);
	MainFormController::getInstance()->optiTrackOutputLog(buf);

    sprintf_s(buf, "Connecting to server at %s...\n", szServerIPAddress);
	MainFormController::getInstance()->optiTrackOutputLog(buf);

	sprintf_s(buf, "Connecting from %s...\n", szMyIPAddress);
	MainFormController::getInstance()->optiTrackOutputLog(buf);

    // Create NatNet Client
    iResult = initClient(theClient, iConnectionType);
    if(iResult != ErrorCode_OK)
    {
        sprintf_s(buf, "Error initializing client.  See log for details.  Exiting\n");
		MainFormController::getInstance()->optiTrackOutputLog(buf);
        return 1;
    }
    else
    {
        sprintf_s(buf, "Client initialized and ready.\n");
		MainFormController::getInstance()->optiTrackOutputLog(buf);
    }

	NatNetClient* natnet = (*theClient)->getClient();

	if (!natnet)
	{
		sprintf_s(buf, "Failed to get client from client handler.\n");
		MainFormController::getInstance()->optiTrackOutputLog(buf);
		return 1;
	}

	// send/receive test request
	sprintf_s(buf, "Sending Test Request\n");
	MainFormController::getInstance()->optiTrackOutputLog(buf);

	void* response;
	int nBytes;
	iResult = natnet->SendMessageAndWait("TestRequest", &response, &nBytes);
	if (iResult == ErrorCode_OK)
	{
		sprintf_s(buf, "Received: %s\n", (char*)response);
		MainFormController::getInstance()->optiTrackOutputLog(buf);
	}

	// Retrieve Data Descriptions from server
	sprintf_s(buf, "Requesting Data Descriptions...\n");
	MainFormController::getInstance()->optiTrackOutputLog(buf);

	sDataDescriptions* pDataDefs = NULL;
	int nBodies = natnet->GetDataDescriptions(&pDataDefs);
	if(!pDataDefs)
	{
		sprintf_s(buf, "Unable to retrieve Data Descriptions.\n");
		MainFormController::getInstance()->optiTrackOutputLog(buf);
		//return 1;
	}
	else
	{
        sprintf_s(buf, "Received %d Data Descriptions:\n", pDataDefs->nDataDescriptions );
		MainFormController::getInstance()->optiTrackOutputLog(buf);
        for(int i=0; i < pDataDefs->nDataDescriptions; i++)
        {
            printf("Data Description # %d (type=%d)\n", i, pDataDefs->arrDataDescriptions[i].type);
            if(pDataDefs->arrDataDescriptions[i].type == Descriptor_MarkerSet)
            {
                // MarkerSet
                sMarkerSetDescription* pMS = pDataDefs->arrDataDescriptions[i].Data.MarkerSetDescription;
                printf("MarkerSet Name : %s\n", pMS->szName);
                for(int i=0; i < pMS->nMarkers; i++)
                    printf("%s\n", pMS->szMarkerNames[i]);

            }
            else if(pDataDefs->arrDataDescriptions[i].type == Descriptor_RigidBody)
            {
                // RigidBody
                sRigidBodyDescription* pRB = pDataDefs->arrDataDescriptions[i].Data.RigidBodyDescription;
                printf("RigidBody Name : %s\n", pRB->szName);
                printf("RigidBody ID : %d\n", pRB->ID);
                printf("RigidBody Parent ID : %d\n", pRB->parentID);
                printf("Parent Offset : %3.2f,%3.2f,%3.2f\n", pRB->offsetx, pRB->offsety, pRB->offsetz);

				RigidBody* body = new RigidBody();
				body->setID(pRB->ID);
				body->setName(pRB->szName);

				if (!(*theClient)->addRigidBody(body->getID(), body))
					delete body;

            }
            else if(pDataDefs->arrDataDescriptions[i].type == Descriptor_Skeleton)
            {
                // Skeleton
                sSkeletonDescription* pSK = pDataDefs->arrDataDescriptions[i].Data.SkeletonDescription;
                printf("Skeleton Name : %s\n", pSK->szName);
                printf("Skeleton ID : %d\n", pSK->skeletonID);
                printf("RigidBody (Bone) Count : %d\n", pSK->nRigidBodies);
                for(int j=0; j < pSK->nRigidBodies; j++)
                {
                    sRigidBodyDescription* pRB = &pSK->RigidBodies[j];
                    printf("  RigidBody Name : %s\n", pRB->szName);
                    printf("  RigidBody ID : %d\n", pRB->ID);
                    printf("  RigidBody Parent ID : %d\n", pRB->parentID);
                    printf("  Parent Offset : %3.2f,%3.2f,%3.2f\n", pRB->offsetx, pRB->offsety, pRB->offsetz);
                }
            }
            else
            {
                printf("Unknown data type.");
                // Unknown
            }
        }      
	}

	(*theClient)->setNatNetServerRunning(true);

	// Ready to receive marker stream!
	sprintf_s(buf, "Client is connected to server and listening for data...\n");
	MainFormController::getInstance()->optiTrackOutputLog(buf);

	MainFormController::getInstance()->optiTrackInitDataView();

	return ErrorCode_OK;
}

int NatNetClientSetup::deleteClient(ClientHandler** theClient)
{
	NatNetClient* natnet = (*theClient)->getClient();

	char buf[2048];

	// Done - clean up.
	if (natnet) {
		sprintf_s(buf, "Disconnecting from Server...\n");
		MainFormController::getInstance()->optiTrackOutputLog(buf);

		natnet->Uninitialize();

		sprintf_s(buf, "Client is Disconnected.\n");
		MainFormController::getInstance()->optiTrackOutputLog(buf);
	} else {
		sprintf_s(buf, "Client is already not connected to the server.\n");
		MainFormController::getInstance()->optiTrackOutputLog(buf);
	}

	(*theClient)->setNatNetServerRunning(false);

	return ErrorCode_OK;
}


// Establish a NatNet Client connection
int initClient(ClientHandler** theClient, int iConnectionType)
{
	NatNetClient* natnet = (*theClient)->getClient();
    // release previous server
    if(natnet != 0)
    {
        natnet->Uninitialize();
        delete natnet;
    }

    // create NatNet client
    natnet = new NatNetClient(iConnectionType);
	(*theClient)->setClient(natnet);

	char buf[2048];

    // print version info
    unsigned char ver[4];
    natnet->NatNetVersion(ver);

    sprintf_s(buf, "NatNet Client (NatNet ver. %d.%d.%d.%d)\n", ver[0], ver[1], ver[2], ver[3]);
	MainFormController::getInstance()->optiTrackOutputLog(buf);

    // Set callback handlers
    natnet->SetMessageCallback(MessageHandler);
    natnet->SetVerbosityLevel(Verbosity_Debug);
    natnet->SetDataCallback( DataHandler, (*theClient) );	// this function will receive data from the server

    // Init Client and connect to NatNet server
    // to use NatNet default port assignments
    // int retCode = (*theClient)->Initialize(szMyIPAddress, szServerIPAddress);
    // to use a different port for commands and/or data:
    int retCode = natnet->Initialize(szMyIPAddress, szServerIPAddress, MyServersCommandPort, MyServersDataPort);
    if (retCode != ErrorCode_OK)
    {
        sprintf_s(buf, "Unable to connect to server.  Error code: %d. Exiting\n", retCode);
		MainFormController::getInstance()->optiTrackOutputLog(buf);
        return ErrorCode_Internal;
    }
    else
    {
        // print server info
        sServerDescription ServerDescription;
        memset(&ServerDescription, 0, sizeof(ServerDescription));
        natnet->GetServerDescription(&ServerDescription);
        if(!ServerDescription.HostPresent)
        {
            sprintf_s(buf, "Unable to connect to server. Host not present. Exiting.\n");
			MainFormController::getInstance()->optiTrackOutputLog(buf);
            return 1;
        }

        sprintf_s(buf, "\nServer application info:\n");
		MainFormController::getInstance()->optiTrackOutputLog(buf);

        sprintf_s(buf, "Application: %s (ver. %d.%d.%d.%d)\n", ServerDescription.szHostApp, ServerDescription.HostAppVersion[0],
            ServerDescription.HostAppVersion[1],ServerDescription.HostAppVersion[2],ServerDescription.HostAppVersion[3]);
		MainFormController::getInstance()->optiTrackOutputLog(buf);

        sprintf_s(buf, "NatNet Version: %d.%d.%d.%d\n", ServerDescription.NatNetVersion[0], ServerDescription.NatNetVersion[1],
            ServerDescription.NatNetVersion[2], ServerDescription.NatNetVersion[3]);
		MainFormController::getInstance()->optiTrackOutputLog(buf);

        sprintf_s(buf, "Client IP:%s\n", szMyIPAddress);
		MainFormController::getInstance()->optiTrackOutputLog(buf);

        sprintf_s(buf, "Server IP:%s\n", szServerIPAddress);
		MainFormController::getInstance()->optiTrackOutputLog(buf);

        sprintf_s(buf, "Server Name:%s\n\n", ServerDescription.szHostComputerName);
		MainFormController::getInstance()->optiTrackOutputLog(buf);
    }

    return ErrorCode_OK;
}

// DataHandler receives data from the server
void __cdecl DataHandler(sFrameOfMocapData* data, void* pUserData)
{
	ClientHandler* pClient = (ClientHandler*) pUserData;

	if (!pClient->lock())
		return;

	int i=0;

    // same system latency test
    float fThisTick = (float)GetTickCount();
    float fDiff = fThisTick - data->fLatency;
    double dDuration = fDiff;

	// Rigid Bodies
	for(i=0; i < data->nRigidBodies; i++)
	{
		RigidBody* body = pClient->getRigidBody(data->RigidBodies[i].ID);

		if ( body )
		{
			body->addFrame(osg::Vec3(-data->RigidBodies[i].x, data->RigidBodies[i].z, data->RigidBodies[i].y),
					osg::Vec4(data->RigidBodies[i].qx, -data->RigidBodies[i].qz, -data->RigidBodies[i].qy, data->RigidBodies[i].qw));

			body->clearMarkers();

			for(int iMarker = 0; iMarker < data->RigidBodies[i].nMarkers; iMarker++)
			{
				Marker marker;

				if(data->RigidBodies[i].MarkerIDs)
					marker.id = data->RigidBodies[i].MarkerIDs[iMarker];
				if(data->RigidBodies[i].MarkerSizes)
					marker.size = data->RigidBodies[i].MarkerSizes[iMarker];
				if(data->RigidBodies[i].Markers)
				{
					marker.x = data->RigidBodies[i].Markers[iMarker][0];
					marker.y = data->RigidBodies[i].Markers[iMarker][1];
					marker.z = data->RigidBodies[i].Markers[iMarker][2];
				}

				char buf[4096];
				sprintf(buf, "Marker ID: %d\n\t{%f, %f, %f}\n", marker.id, marker.x, marker.y, marker.z);
				OutputDebugStringA(buf);

				body->addMarker(marker);
			}

			
		}
	}
	
	// Calculate the number of frames per one second:
	static unsigned int fps = 0;
	static int dwFrames = 0;
	static float dwCurrentTime = 0.f;
	static float dwElapsedTime = 0.f;
	static float dwLastUpdateTime = 0.f;
	static float delay = 0.f;
	static float delayCount = 0.f;

	dwFrames++;
	dwCurrentTime = (float)GetTickCount(); // Even better to use timeGetTime()
	dwElapsedTime = dwCurrentTime - dwLastUpdateTime;

	if(dwElapsedTime >= 1000)
	{
		unsigned int fps = (unsigned int)(dwFrames * 1000.0 / dwElapsedTime);
		dwFrames = 0;
		dwLastUpdateTime = dwCurrentTime;

		delay = 5.f/fps;
	}
	
	delayCount += delay;
	if (delayCount >= 1.0f)
	{
		MainFormController::getInstance()->optiTrackUpdateData();
		delayCount = 0.f;
	}

	pClient->unlock();
}

// MessageHandler receives NatNet error/debug messages
void __cdecl MessageHandler(int msgType, char* msg)
{
	//printf("\n%s\n", msg);
}

void resetClient(ClientHandler** theClient)
{
	NatNetClient* natnet = (*theClient)->getClient();
	
	if (!natnet)
	{
		printf("Failed to get client from client handler during reset.\n");
		return;
	}

	int iSuccess;

	printf("\nre-setting Client\n\n.");

	iSuccess = natnet->Uninitialize();
	if(iSuccess != 0)
		printf("error un-initting Client\n");

	iSuccess = natnet->Initialize(szMyIPAddress, szServerIPAddress);
	if(iSuccess != 0)
		printf("error re-initting Client\n");
}
