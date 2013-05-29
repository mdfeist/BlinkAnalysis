#ifndef CAPTUREOBJECTUTIL_H
#define CAPTUREOBJECTUTIL_H

#include <osg/Vec3>
#include <osg/Matrix>

#include "Marker.h"

#define EPSILON 0.00001

class CaptureObjectUtil
{
public:
	static bool orthogonalCheckFuzzy(osg::Vec3 v1, osg::Vec3 v2, double epsilon);

	static osg::Matrix* makeLocalToGlobalMatrix(osg::Vec3 origin, osg::Vec3 x, osg::Vec3 y);

};



#endif
