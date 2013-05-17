#include "StdAfx.h"
#include "CaptureObject.h"

// util fcns
// TODO: move to separate file later
bool CaptureUtil::orthogonalCheckFuzzy(osg::Vec3 v1, osg::Vec3 v2, double epsilon) 
{
	return (abs(v1*v2) <= abs(epsilon));
}

osg::Vec3* CaptureUtil::markerToVector(const Marker m)
{
	return new osg::Vec3(m.x, m.y, m.z);
}




// assume vectors orthogonal?
CaptureCube::CaptureCube(osg::Vec3 corner, osg::Vec3 pt1, osg::Vec3 pt2, osg::Vec3 pt3) 
{

	// check segments orthogonal
	// though this should be checked earlier in code
	osg::Vec3 s1 = pt1 - corner;
	osg::Vec3 s2 = pt2 - corner;
	osg::Vec3 s3 = pt3 - corner;

	if (!CaptureUtil::orthogonalCheckFuzzy(s1, s2, EPSILON) || 
		!CaptureUtil::orthogonalCheckFuzzy(s1, s3, EPSILON) ||
		!CaptureUtil::orthogonalCheckFuzzy(s2, s3, EPSILON))
	{
		// TODO: output error
		return;
	}




}

bool CaptureCube::intersectsVector(osg::Vec3 position, osg::Vec3 direction)
{
	return false;
}



