
#include "StdAfx.h"

#include "MainFormController.h"

#include "WorldManager.h"


WorldManager* WorldManager::m_pInstance = NULL; 

WorldManager::WorldManager(void)
{
}

WorldManager::~WorldManager(void)
{
}

bool WorldManager::addWorld(CaptureWorld *world)
{
	int id = world->getID();

	std::pair<worlds_iterator, bool> ret;
	ret = worlds.insert(std::pair<int, CaptureWorld*>(id, world));

	if (ret.second) // added successfully
	{
		MainFormController::getInstance()->worldUpdateList();
		return true;
	}
	return false;
}

CaptureWorld* WorldManager::getWorld(int id)
{
	worlds_iterator itr = worlds.find(id);
	
	if (itr == worlds.end())
		return NULL;

	return itr->second;
}

int WorldManager::getNumberWorlds()
{
	return worlds.size();
}

std::map<int, CaptureWorld*> WorldManager::getWorlds()
{
	return worlds;
}

bool WorldManager::removeWorld(int id)
{
	worlds_iterator itr = worlds.find(id);
	
	if (itr == worlds.end())
		return false;

	delete itr->second;
	worlds.erase(id);
	return true;
}

void WorldManager::clearWorlds()
{
	for (worlds_iterator itr = worlds.begin(); itr != worlds.end(); itr++)
	{
		delete itr->second;
	}
	worlds.clear();
}


