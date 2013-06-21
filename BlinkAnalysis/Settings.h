#pragma once
#include "stdafx.h"
#include <string>

#include "pugixml.hpp"

class Settings
{
public:
	static Settings* getInstance() {
		if(!m_pInstance) m_pInstance = new Settings();
		return m_pInstance;
	}

	char* getLastError() { return this->error; }

	bool loadSettings();

	std::string getDefaultProjectDirectory() { return this->defaultProjectDirectory; }

protected:
	Settings(void);
	~Settings(void);
private:
	Settings(Settings const&);
	Settings& operator=(Settings const&);

	static Settings* m_pInstance;

	char error[1024];

	std::string defaultProjectDirectory;
};

