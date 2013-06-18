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

	// Get the Connection Type from the ClientHandler
	iConnectionType = (*theClient)->getOptiTrackServerConnectionType();

	// Get the Command Port from the ClientHandler
	MyServersCommandPort = (*theClient)->getOptiTrackServerCommandPort();
	// Get the Data Port from the ClientHandler
	MyServersDataPort = (*theClient)->getOptiTrackServerDataPort();

	// Get the Local Ip Address from the ClientHandler
	(*theClient)->getLocalIpAddress(szMyIPAddress);
	// Get the Server Ip Address from the ClientHandler
	(*theClient)->getOptiTrackServerIpAddress(szServerIPAddress);

	// A string buffer used to temporally store strings
	// for the output log.
	char buf[2048];

	// Print Connection Information to the Output Log
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

	// Get the NatNetClient from the ClientHandler
	NatNetClient* natnet = (*theClient)->getClient();

	// Check if successful at retrieving the NatNetClient from
	// the ClientHandler.
	if (!natnet)
	{
		sprintf_s(buf, "Failed to get client from client handler.\n");
		MainFormController::getInstance()->optiTrackOutputLog(buf);
		return 1;
	}

	// send/receive test request
	sprintf_s(buf, "Sending Test Request\n");
	MainFormController::getInstance()->optiTrackOutputLog(buf);

	// Test Connection
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

	// Set the Flag tell that the NatNetClient is connected
	// to a server to True.
	(*theClient)->setNatNetServerRunning(true);

	// Ready to receive marker stream!
	sprintf_s(buf, "Client is connected to server and listening for data...\n");
	MainFormController::getInstance()->optiTrackOutputLog(buf);

	// Initialize the OptiTack DataView on the MainForm
	MainFormController::getInstance()->optiTrackInitDataView();

	// Return Error Code OK
	return ErrorCode_OK;
}

// Closes the connection to the NatNetServer
int NatNetClientSetup::deleteClient(ClientHandler** theClient)
{
	// Get the NatNetClient from the ClientHandler
	NatNetClient* natnet = (*theClient)->getClient();

	char buf[2048];

	// Done - clean up.
	if (natnet) {
		sprintf_s(buf, "Disconnecting from Server...\n");
		MainFormController::getInstance()->optiTrackOutputLog(buf);

		// Disconnects from the server
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
	// Get the NatNetClient from the ClientHandler
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
	// Cast user data as ClientHandler
	ClientHandler* pClient = (ClientHandler*) pUserData;

	// Rigid Bodies
	for(int i = 0; i < data->nRigidBodies; i++)
	{
		// Get pointer to Rigid Body
		RigidBody* body = pClient->getRigidBody(data->RigidBodies[i].ID);

		// Check if Rigid Body with the given ID exists
		if ( body )
		{
			// Lock the ClientHandler so data isn't changed
			// by another thread.
			if (!pClient->lock())
				continue;

			// Update the Position and Orientation of the Rigid Body
			float x = -data->RigidBodies[i].x;
			float z = data->RigidBodies[i].y;
			float y = data->RigidBodies[i].z;

			float qx = data->RigidBodies[i].qx;
			float qy = -data->RigidBodies[i].qz;
			float qz = -data->RigidBodies[i].qy;
			float qw = data->RigidBodies[i].qw;

			body->addFrame(osg::Vec3(x, y, z),
					osg::Vec4(qx, qy, qz, qw));

			// Clear all the previous markers that were attached to the Rigid Body
			body->clearMarkers();

			// Gather all the Markers attached to the Rigid Body
			for(int iMarker = 0; iMarker < data->RigidBodies[i].nMarkers; iMarker++)
			{
				// Create a new marker
				Marker marker;

				// Get the information about the marker
				if(data->RigidBodies[i].MarkerIDs)
					marker.setID(data->RigidBodies[i].MarkerIDs[iMarker]);
				if(data->RigidBodies[i].MarkerSizes)
					marker.setSize(data->RigidBodies[i].MarkerSizes[iMarker]);
				if(data->RigidBodies[i].Markers)
				{
					x = -data->RigidBodies[i].Markers[iMarker][0];
					z = data->RigidBodies[i].Markers[iMarker][1];
					y = data->RigidBodies[i].Markers[iMarker][2];

					marker.setPosition(osg::Vec3(x, y, z));
				}

				// Add the marker to the Rigid Body
				body->addMarker(marker);
			}

			// Unlock the ClientHandler
			pClient->unlock();
		}
	}

	// TODO better handling of marker creation?
	// Labeled Markers

	for(int i = 0; i < data->nLabeledMarkers; i++)
	{
		if (!pClient->lock())
			continue;

		Marker* marker = pClient->getLabeledMarker(data->LabeledMarkers[i].ID);
		float x = -data->LabeledMarkers[i].x;
		float z = data->LabeledMarkers[i].y;
		float y = data->LabeledMarkers[i].z;
		
		if (marker)
		{
			marker->setPosition(osg::Vec3(x, y, z));
			marker->update();
		}
		else
		{
			marker = new Marker(data->LabeledMarkers[i].ID, x, y, z, data->LabeledMarkers[i].size);
			marker->update();
			marker->setColor(osg::Vec4(0, 0, 1, 1));
			pClient->addLabeledMarker(marker->getID(), marker);
		}
		
		pClient->unlock();
	}
	
	if (pClient->lock())
	{
		pClient->clearStaleMarkers();
		pClient->unlock();
	}

	// Update the OptiTrack page
	MainFormController::getInstance()->optiTrackUpdateData();
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
