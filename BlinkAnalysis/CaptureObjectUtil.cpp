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


