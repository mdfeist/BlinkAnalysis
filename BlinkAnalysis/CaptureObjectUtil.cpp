
#include "StdAfx.h"
#include "CaptureObjectUtil.h"

bool CaptureObjectUtil::orthogonalCheckFuzzy(osg::Vec3 v1, osg::Vec3 v2, double epsilon) 
{
	return (abs(v1*v2) <= abs(epsilon));
}

osg::Vec3* CaptureObjectUtil::markerToVector(const Marker m)
{
	return new osg::Vec3(m.x, m.y, m.z);
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

	// local to global coordinates
	osg::Matrix* mat = new osg::Matrix(	vec_x.x(), vec_y.x(), vec_z.x(), origin.x(),
										vec_x.y(), vec_y.y(), vec_z.y(), origin.y(),
										vec_x.z(), vec_y.z(), vec_z.z(), origin.z(),
										0, 0, 0, 1);

	*mat *= osg::Matrix::translate(osg::Vec3(origin.x(), origin.y(), origin.z()));

	return mat;
}


