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


typedef std::map<int, CaptureWorld*>::iterator worlds_iterator;

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

	// Set/Get CaptureWorld
	// returns false or NULL if invalid world ID
	bool addWorld(CaptureWorld *world); 
	CaptureWorld* getWorld(int id);
	int getNumberWorlds();
	std::map<int, CaptureWorld*> getWorlds();
	bool removeWorld(int id);
	void clearWorlds();

	void setFileName(char* fileName) { strncpy_s(this->fileName, fileName, strlen(fileName)); }
	char* getFileName() { return this->fileName; }
	void setFilePath(char* filePath) { strncpy_s(this->filePath, filePath, strlen(filePath)); }
	char* getFilePath() { return this->filePath; }

	char* getLastError() { return this->error; }

	bool openFile(char* filePath);
	bool saveFile();
	bool isSaveNeeded() { return this->needSaveFlag; }
	void needSave() { this->needSaveFlag = true; }

protected:
	AppData(void);
	~AppData(void);
private:
	AppData(AppData const&);
	AppData& operator=(AppData const&);

	static AppData* m_pInstance;
	ClientHandler *client;
	std::map<int, CaptureWorld*> worlds;

	bool needSaveFlag;
	pugi::xml_document doc;
	char fileName[1024];
	char filePath[1024];
	char error[1024];
};


