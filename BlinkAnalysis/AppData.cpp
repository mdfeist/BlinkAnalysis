/**
 * AppData.cpp
 * Created By: Michael Feist
 */

#include "StdAfx.h"
#include "AppData.h"

#include <stdlib.h>
#include <stdio.h>
#include "MainFormController.h"

AppData* AppData::m_pInstance = NULL; 


AppData::AppData(void)
{
	this->needSaveFlag = false;

	strncpy_s(this->fileName, "Untitled.xml", strlen(this->filePath));
	strncpy_s(this->filePath, "", strlen(this->filePath));
	strncpy_s(this->error, "", strlen(this->error));
}


AppData::~AppData(void)
{
}

bool AppData::openFile(char* filePath) {
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

		MainFormController::getInstance()->setInfo();
	}

	strncpy_s(this->filePath, filePath, strlen(filePath));

	this->needSaveFlag = false;

	return true;
}

pugi::xml_node AppData::getNewRecording() {
	// Get Project
	pugi::xml_node project = doc.child("Project");

	// If no Project create new Project node
	if (!project) {
		project = doc.append_child();
		project.set_name("Project");
	}

	return project.append_child();
}

bool AppData::saveFile() {
	MainFormController::getInstance()->getInfo();

	// Get Project
	pugi::xml_node project = doc.child("Project");

	// If no Project create new Project node
	if (!project) {
		project = doc.append_child();
		project.set_name("Project");
	}

	// Save OptiTrack Information
	{
		pugi::xml_node OptiTrack = project.child("OptiTrack");

		if (!OptiTrack) {
			OptiTrack = project.append_child();
			OptiTrack.set_name("OptiTrack");
		}

		// Get Attributes
		pugi::xml_attribute localIP = OptiTrack.attribute("LocalIpAddress");
		pugi::xml_attribute serverIP = OptiTrack.attribute("ServerIpAddress");
		pugi::xml_attribute cmdPort = OptiTrack.attribute("CommandPort");
		pugi::xml_attribute dataPort = OptiTrack.attribute("DataPort");
		pugi::xml_attribute cType = OptiTrack.attribute("ConnectionType");

		// Create missing Attributes
		if (!localIP) {
			localIP = OptiTrack.append_attribute("LocalIpAddress");
		}

		if (!serverIP) {
			serverIP = OptiTrack.append_attribute("ServerIpAddress");
		}

		if (!cmdPort) {
			cmdPort = OptiTrack.append_attribute("CommandPort");
		}

		if (!dataPort) {
			dataPort = OptiTrack.append_attribute("DataPort");
		}

		if (!cType) {
			cType = OptiTrack.append_attribute("ConnectionType");
		}

		char buf[128];

		// Save Local IP Address
		this->client->getLocalIpAddress(buf);
		localIP.set_value(buf);

		// Save Server IP Address
		this->client->getOptiTrackServerIpAddress(buf);
		serverIP.set_value(buf);

		// Save Command Port
		cmdPort.set_value(this->client->getOptiTrackServerCommandPort());

		// Save Data Port
		dataPort.set_value(this->client->getOptiTrackServerDataPort());

		// Save Connection Type
		int iConnectionType = this->client->getOptiTrackServerConnectionType();
		if (iConnectionType == ConnectionType_Multicast)
			cType.set_value("Multicast");
		else if (iConnectionType == ConnectionType_Unicast)
			cType.set_value("Unicast");
		else
			cType.set_value("Multicast");
	}

	doc.save_file(this->filePath);

	this->needSaveFlag = false;
	MainFormController::getInstance()->updateFormTitle();

	return true;
}


