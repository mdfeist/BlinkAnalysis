
#include "StdAfx.h"
#include "CaptureObjectUtil.h"

bool CaptureObjectUtil::orthogonalCheckFuzzy(osg::Vec3 v1, osg::Vec3 v2, double epsilon) 
{
	return (abs(v1*v2) <= abs(epsilon));
}

// based on MATLAB function MakeCoordSystem by J. Lanovaz
osg::Matrix* CaptureObjectUtil::makeLocalToGlobalMatrix(
	osg::Vec3 origin, osg::Vec3 x, osg::Vec3 y)
{
	// form axis vectors
	osg::Vec3 vec_x = x - origin;
	osg::Vec3 vec_y = y - origin;
	
	// normalize
	vec_x.normalize();
	vec_y.normalize();

	// z-axis
	osg::Vec3 vec_z = vec_x ^ vec_y;
	vec_z.normalize();

	//y-axis
	vec_y = vec_z ^ vec_x;
	vec_y.normalize();

	// global to local coordinates
	osg::Matrix* mat = new osg::Matrix(	vec_x.x(), vec_x.y(), vec_x.z(), 0,
										vec_y.x(), vec_y.y(), vec_y.z(), 0,
										vec_z.x(), vec_z.y(), vec_z.z(), 0,
										origin.x(), origin.y(), origin.z(), 1);

	return mat;
}


