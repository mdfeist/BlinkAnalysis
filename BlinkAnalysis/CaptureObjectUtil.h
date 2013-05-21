#ifndef CAPTUREOBJECTUTIL_H
#define CAPTUREOBJECTUTIL_H

#include <vector>
#include <osg/AutoTransform>
#include <osg/Vec3>


#include "NatNetTypes.h"
#include "RigidBody.h" // may have to move Marker class outside to avoid circular inclusion

class CaptureObjectUtil
{
public:
	static bool orthogonalCheckFuzzy(osg::Vec3 v1, osg::Vec3 v2, double epsilon);

	static osg::Vec3* markerToVector(const Marker m);

};



#endif
