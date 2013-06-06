#ifndef CAPTUREWORLD_H
#define CAPTUREWORLD_H

#include <hash_map>
#include <osg/Node>
#include <osg/Matrix>
#include <osg/MatrixTransform>


#include "CaptureObject.h"
#include "CaptureObjectUtil.h"


typedef std::map<int, CaptureObject*>::iterator objects_iterator;

class CaptureWorld 
{
private:
	static int _lastWorldID;

	std::string name;
	int id;

	osg::Matrix* _globalToLocal;
	// true: object positions are relative to transformation
	// false: object positions are global position data
	bool objectsRelative;

	// increments for each new object added
	int _lastObjectID;
	// map of IDs to objects in this world
	std::map<int, CaptureObject*> _objects;
	
	int addObject(CaptureObject* obj);
	osg::ref_ptr<osg::MatrixTransform> node;
	
public:
	CaptureWorld();
	CaptureWorld(std::string name);
	CaptureWorld(std::string name, osg::Matrix* globToLoc);
	~CaptureWorld()
	{
		delete _globalToLocal;
		clearObjects();
	}

	const osg::Matrix getLocalToGlobalMatrix()
	{
		return osg::Matrix::inverse(*_globalToLocal);
	}

	const osg::Matrix getGlobalToLocalMatrix()
	{
		return *_globalToLocal;
	}

	std::string getName() { return name; }
	void setName(std::string name) { this->name = name; }
	int getID() { return id; }

	void setCoordinateFrame(osg::Matrix* globToLoc, bool deleteObjects=false, bool updateObjects=false);

	CaptureObject* addPlane(osg::Vec3 corner, osg::Vec3 pt1, osg::Vec3 pt2, std::string name);

	CaptureObject* getObject(int id);

	bool removeObject(int id);

	void clearObjects();

	std::map<int, CaptureObject*> getObjects() { return _objects; }

	int getNumberObjects();

	osg::MatrixTransform* getAsGroup();
	void updateObjectsNode();
};



#endif
