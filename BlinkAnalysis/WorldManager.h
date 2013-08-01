#ifndef WORLDMANAGER_H
#define WORLDMANAGER_H

#include "CaptureWorld.h"
	
typedef std::map<int, CaptureWorld*>::iterator worlds_iterator;

/**
 * Singleton that manages all CaptureWorlds
 */
public class WorldManager
{
public:
	static WorldManager* getInstance() {
		if(!m_pInstance) m_pInstance = new WorldManager();
		return m_pInstance;
	}

	// Set/Get CaptureWorld
	// returns false or NULL if invalid world ID
	bool addWorld(CaptureWorld *world); 
	CaptureWorld* getWorld(int id);
	int getNumberWorlds();
	std::map<int, CaptureWorld*> getWorlds();
	bool removeWorld(int id);
	void clearWorlds(bool stopRender = false);

	// all worlds contained under one Group node
	bool addWorldNode(osg::Node* wNode);
	bool removeWorldNode(osg::Node* wNode);
	osg::Node* getWorldNode();

	std::string getWorldStaticData();

protected:
	WorldManager(void);
	~WorldManager(void);

private:
	WorldManager(WorldManager const&);
	WorldManager& operator=(WorldManager const&);

	static WorldManager* m_pInstance;
	std::map<int, CaptureWorld*> worlds;

	osg::ref_ptr<osg::Group> worldNode;

	void streamWorld(CaptureWorld* world, std::ostringstream& sstream);
	void streamObject(CaptureObject* object, std::ostringstream& sstream);
};



#endif
