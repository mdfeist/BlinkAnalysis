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

	void setClient(ClientHandler *client) { this->client = client; }
	ClientHandler* getClient() { return this->client; }

protected:
	AppData(void);
	~AppData(void);
private:
	AppData(AppData const&);
	AppData& operator=(AppData const&);

	static AppData* m_pInstance;
	ClientHandler *client;
};


