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
	// matrix transforming from global to local coordinates
	osg::Matrix* _globalToLocal;
	// increments for each new object added
	int _lastObjectID;
	// map of IDs to objects in this world
	std::map<int, CaptureObject*> _objects;
	
	int addObject(CaptureObject* obj);
	osg::ref_ptr<osg::MatrixTransform> node;
	
public:
	static double VIEWER_SCALE;	// scales the size of objects and points in the viewer.
								// attach to a sliding scale for control later?

	CaptureWorld()
	{
		_globalToLocal = new osg::Matrix();
		_globalToLocal->makeIdentity();
		_lastObjectID = 0;
	}

	~CaptureWorld()
	{
		delete _globalToLocal;
		clearObjects();
	}

	CaptureWorld(osg::Matrix* globToLoc);
	
	const osg::Matrix getLocalToGlobalMatrix() 
	{ 
		return osg::Matrix::inverse(*_globalToLocal);
	}

	const osg::Matrix getGlobalToLocalMatrix()
	{
		return *_globalToLocal; 
	}
	// setting a new transformation matrix
	// choose to delete objects with change, or update them w.r.t. new transformation
	void setCoordinateFrame(osg::Matrix* globToLoc, bool deleteObjects=false, bool updateObjects=false);

	CaptureObject* addPlane(osg::Vec3 corner, osg::Vec3 pt1, osg::Vec3 pt2, std::string name);

	bool removeObject(int id);

	void clearObjects();

	std::map<int, CaptureObject*> getObjects() { return _objects; }

	int getNumberObjects();

	osg::MatrixTransform* getAsGroup();

};



#endif
