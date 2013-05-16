/**
 * AppData.cpp
 * Created By: Michael Feist
 */

#include "StdAfx.h"
#include "AppData.h"

#include <stdlib.h>
#include <stdio.h>
#include "pugixml.hpp"
#include "MainFormController.h"

AppData* AppData::m_pInstance = NULL; 


AppData::AppData(void)
{
}


AppData::~AppData(void)
{
}

bool AppData::openFile(char* filePath) {
	pugi::xml_document doc;

	pugi::xml_parse_result result = doc.load_file(filePath);

	if (result.status) {
		sprintf_s(this->error, "Load Project Result: %s.", result.description());
		return false;
	} else {
		if (!this->client) {
			sprintf_s(this->error, "Unable to load project because the client handler was not created.");
			return false;
		}

		// Get Project
		pugi::xml_node project = doc.child("Project");

		if (project) {
			// Get OptiTrack Information
			pugi::xml_node OptiTrack = project.child("OptiTrack");

			if (OptiTrack) {
				pugi::xml_attribute localIP = OptiTrack.attribute("LocalIpAddress");
				pugi::xml_attribute serverIP = OptiTrack.attribute("ServerIpAddress");
				pugi::xml_attribute cmdPort = OptiTrack.attribute("CommandPort");
				pugi::xml_attribute dataPort = OptiTrack.attribute("DataPort");
				pugi::xml_attribute cType = OptiTrack.attribute("ConnectionType");

				if (localIP) {
					this->client->setLocalIpAddress(localIP.value());
				}

				if (serverIP) {
					this->client->setOptiTrackServerIpAddress(serverIP.value());
				}

				if (cmdPort) {
					this->client->setOptiTrackServerCommandPort(cmdPort.as_int());
				}

				if (dataPort) {
					this->client->setOptiTrackServerDataPort(dataPort.as_int());
				}

				if (cType) {
					if (!strncmp(cType.value(), "Multicast", 128)) {
						this->client->setOptiTrackServerConnectionType(ConnectionType_Multicast);
					} else if (!strncmp(cType.value(), "Unicast", 128)) {
						this->client->setOptiTrackServerConnectionType(ConnectionType_Unicast);
					} else {
						this->client->setOptiTrackServerConnectionType(ConnectionType_Multicast);
					}
				}
			}
		}

		MainFormController::getInstance()->updateInfo();
	}

	return true;
}