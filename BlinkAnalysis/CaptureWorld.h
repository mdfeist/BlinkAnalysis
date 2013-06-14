#ifndef CAPTUREWORLD_H
#define CAPTUREWORLD_H

#include <hash_map>
#include <osg/MatrixTransform>


#include "CaptureObject.h"
#include "CaptureObjectUtil.h"


typedef std::map<int, CaptureObject*>::iterator objects_iterator;

class CaptureWorld 
{
private:
	void initCaptureWorld();
	static int _lastWorldID;

	std::string name;
	int id;
	
	osg::Matrix* _globalToLocal;
	osg::ref_ptr<osg::MatrixTransform> node;
	bool render;
	
	// increments for each new object added
	int _lastObjectID;
	// map of IDs to objects in this world
	std::map<int, CaptureObject*> _objects;
	int addObject(CaptureObject* obj);
	
public:
	CaptureWorld();
	CaptureWorld(std::string name);
	CaptureWorld(std::string name, osg::Matrix* globToLoc);

	~CaptureWorld()
	{
		delete _globalToLocal;
		clearObjects();
	}

	const osg::Matrix getLocalToGlobalMatrix();
	const osg::Matrix getGlobalToLocalMatrix();

	std::string getName() { return name; }
	void setName(std::string name);
	int getID() { return id; }
	bool renderWorld() { return render; }
	void setRender(bool ren);
	bool toggleRender();

	void setRenderObject(int oid, bool ren);
	bool toggleRenderObject(int oid);

	void setCoordinateFrame(osg::Matrix* globToLoc, bool deleteObjects=false, bool updateObjects=false);

	CaptureObject* addPlane(osg::Vec3 corner, osg::Vec3 pt1, osg::Vec3 pt2, std::string name);

	CaptureObject* getObject(int oid);

	bool removeObject(int oid);

	void clearObjects();

	std::map<int, CaptureObject*> getObjects() { return _objects; }

	int getNumberObjects();

	osg::MatrixTransform* getAsGroup(bool renderMatrix=false);

	bool hasNode(osg::MatrixTransform* node) { return this->node == node; }

	void updateObjectsNode();
};



#endif
