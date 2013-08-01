/** 
 * NatNetClient.h
 * Original code from NatNetSDK2.2 SampleClient.
 * Modified By: Michael Feist
 */
#pragma once
#include "stdafx.h"

#include "ClientHandler.h"

/**
 * The NatNetClient handles the start up process
 * of the NatNetSDK.
 */
namespace NatNetClientSetup
{
	// Creates a new connection to the OptiTrack System
	int createClient(ClientHandler** theClient);
	// Cleans up the connection
	int deleteClient(ClientHandler** theClient);
};