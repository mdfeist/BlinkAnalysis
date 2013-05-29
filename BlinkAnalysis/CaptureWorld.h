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
	// matrix transforming from local to global coordinates
	osg::Matrix* _localToGlobal;
	// increments for each new object added
	int _lastObjectID;
	// map of IDs to objects in this world
	std::map<int, CaptureObject*> _objects;
	
	int addObject(CaptureObject* obj);
	osg::ref_ptr<osg::MatrixTransform> node;
	
public:

	CaptureWorld()
	{
		_localToGlobal = new osg::Matrix();
		_localToGlobal->makeIdentity();
		_lastObjectID = 0;
	}

	~CaptureWorld()
	{
		delete _localToGlobal;
		clearObjects();
	}

	CaptureWorld(osg::Matrix* locToGlob);
	
	const osg::Matrix getLocalToGlobalMatrix() 
	{ 
		return *_localToGlobal; 
	}

	const osg::Matrix getGlobalToLocalMatrix()
	{
		return osg::Matrix::inverse(*_localToGlobal);
	}
	// setting a new transformation matrix
	// choose to delete objects with change, or update them w.r.t. new transformation
	void setCoordinateFrame(osg::Matrix* locToGlob, bool deleteObjects=false, bool updateObjects=false);

	int addPlane(osg::Vec3 corner, osg::Vec3 pt1, osg::Vec3 pt2, std::string name);

	bool removeObject(int id);

	void clearObjects();

	std::map<int, CaptureObject*> getObjects() { return _objects; }

	int getNumberObjects();

	osg::Group* getAsGroup();

};



#endif
