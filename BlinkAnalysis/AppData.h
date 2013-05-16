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
#include "NatNetTypes.h"

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

	void setFilePath(char* filePath) { strncpy_s(this->filePath, filePath, strlen(filePath)); }
	char* getFilePath() { return this->filePath; }

	char* getLastError() { return this->error; }

	bool openFile(char* filePath);

protected:
	AppData(void);
	~AppData(void);
private:
	AppData(AppData const&);
	AppData& operator=(AppData const&);

	static AppData* m_pInstance;
	ClientHandler *client;

	char filePath[1024];
	char error[1024];
};


