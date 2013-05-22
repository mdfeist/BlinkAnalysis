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

	osg::Matrix _localToGlobal;
	osg::Matrix _globalToLocal;
	int _lastObjectID;
	std::map<int, CaptureObject*> _objects;
	
	int addObject(CaptureObject* obj);
	
public:

	CaptureWorld()
	{
		_localToGlobal.set(osg::Matrix::identity());
		_globalToLocal.set(osg::Matrix::identity());
		_lastObjectID = 0;
	}

	~CaptureWorld()
	{
		clearObjects();
	}

	CaptureWorld(osg::Matrix locToGlob);
	
	const osg::Matrix getLocalToGlobalMatrix() 
	{ 
		return _localToGlobal; 
	}

	const osg::Matrix getGlobalToLocalMatrix()
	{
		return _globalToLocal;
	}

	void setCoordinateFrame(osg::Matrix locToGlob, bool deleteObjects, bool updateObjects);

	int addPlane(osg::Vec3 corner, osg::Vec3 pt1, osg::Vec3 pt2, std::string name);

	bool removeObject(int id);

	void clearObjects();

	int getNumberObjects();

	osg::Node* getAsNode();

};



#endif
