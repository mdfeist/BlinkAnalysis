/**
 * AppData.h
 * Created By: Michael Feist
 *
 * Holds global information about the Application.
 */
#pragma once
#include "stdafx.h"
#include <string>

#include "ClientHandler.h"
#include "CaptureWorld.h"
#include "NatNetTypes.h"
#include "pugixml.hpp"

/**
 *  Manages ClientHandler and file save/load
 */
public class AppData
{
public:
	static AppData* getInstance() {
		if(!m_pInstance) m_pInstance = new AppData();
		return m_pInstance;
	}

	// Set/Get the ClientHandler
	void setClient(ClientHandler *client) { this->client = client; }
	ClientHandler* getClient() { return this->client; }

	void setFileName(char* fileName) { strncpy_s(this->fileName, fileName, strlen(fileName)); }
	char* getFileName() { return this->fileName; }
	void setFilePath(char* filePath) { strncpy_s(this->filePath, filePath, strlen(filePath)); }
	char* getFilePath() { return this->filePath; }

	char* getLastError() { return this->error; }

	bool openFile(char* filePath);
	bool saveFile();
	bool isSaveNeeded() { return this->needSaveFlag; }
	void needSave() { this->needSaveFlag = true; }

	std::string getRigidBodyStaticData();

protected:
	AppData(void);
	~AppData(void);
private:
	AppData(AppData const&);
	AppData& operator=(AppData const&);

	static AppData* m_pInstance;
	ClientHandler *client;

	bool needSaveFlag;
	pugi::xml_document doc;
	char fileName[1024];
	char filePath[1024];
	char error[1024];

	void saveWorld(CaptureWorld* world, pugi::xml_node& node);
	void saveObject(CaptureObject* object, pugi::xml_node& node);

	CaptureWorld* loadWorld(pugi::xml_node& worldNode);
	CaptureObject* loadObject(pugi::xml_node& objectNode);
};


