#ifndef CAPTUREOBJECT_H
#define CAPTUREOBJECT_H

#include <vector>
#include <osg/AutoTransform>

#include "NatNetTypes.h"
#include "RigidBody.h" // may have to move Marker class outside to avoid circular inclusion

#define EPSILON 0.000001

// for streaming to MATLAB
struct Vector3D
{
	int x;
	int y;
	int z;
};

struct CaptureFace
{
	Vector3D *vertices;
	Vector3D normal;
};


class CaptureObject
{
private:
	// -1 if static object
	int rigidBody;
	
	osg::Geode *geo;
	
	unsigned int numVertices;

public:

	CaptureObject()
	{
	}
	
	~CaptureObject()
	{
	}

};

class CaptureCube : public CaptureObject 
{
private:
	

public:

	CaptureCube(osg::Vec3 corner, osg::Vec3 pt1, osg::Vec3 pt2, osg::Vec3 pt3);

	bool intersectsVector(osg::Vec3 position, osg::Vec3 direction);
};

class CoordinatePlane : public CaptureObject 
{
private:
	osg::Matrix coordTransform;

public:
	
	//float vs int for unit definition?
	CoordinatePlane(osg::Vec3 origin, osg::Vec3 x, osg::Vec3 y, unsigned int xUnit, unsigned int yUnit);


};

class CaptureUtil
{
public:
	static bool orthogonalCheckFuzzy(osg::Vec3 v1, osg::Vec3 v2, double epsilon);

	static osg::Vec3* CaptureUtil::markerToVector(const Marker m);

};
 

#endif
