
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

// based on http://www.euclideanspace.com/maths/geometry/rotations/conversions/quaternionToEuler/index.htm
osg::Vec3 CaptureObjectUtil::quaternionToEuler(osg::Quat q)
{
	double qx = q.x();
	double qy = q.y();
	double qz = q.z();
	double qw = q.w();

	if (qx*qy + qz*qw == 0.5) // north pole
		return osg::Vec3(2*atan2(qx,qw), asin(2*qx*qy + 2*qz*qw), 0);
	if (qx*qy + qz*qw == -0.5) // south pole
		return osg::Vec3(-2*atan2(qx,qw), asin(2*qx*qy + 2*qz*qw), 0);

	double x = atan2(2*qy*qw-2*qx*qz , 1 - 2*pow(qy,2) - 2*pow(qz,2));
	double y = asin(2*qx*qy + 2*qz*qw);
	double z = atan2(2*qx*qw-2*qy*qz , 1 - 2*pow(qx,2) - 2*pow(qz,2));

	return osg::Vec3(x, y, z);
}

////////////////////////////////////////
// The following method is from https://www.movesinstitute.org/Sullivan/OSGTutorials/osgGetWorldCoords.htm
////////////////////////////////////////

// Given a valid node placed in a scene under a transform, return the
// world coordinates in an osg::Matrix.
// Creates a visitor that will update a matrix representing world coordinates
// of the node, return this matrix.
// (This could be a class member for something derived from node also.

osg::Matrixd* CaptureObjectUtil::getWorldCoords( osg::Node* node) 
{
   getWorldCoordOfNodeVisitor* ncv = new getWorldCoordOfNodeVisitor();
   if (node && ncv)
   {
      node->accept(*ncv);
      return ncv->giveUpDaMat();
   }
   else
   {
      return NULL;
   }
} 
////////////////////////////////////////
