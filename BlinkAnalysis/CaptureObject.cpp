

#include "StdAfx.h"
#include <osg/Geometry>
#include <osg/Geode>
#include <osgUtil/SmoothingVisitor>

#include <osg/Texture2D>
#include <osgDB/ReadFile>

#include "CaptureObject.h"

osg::Geode* CaptureObject::getAsGeode()
{
	osg::ref_ptr<osg::Geometry> geom = new osg::Geometry();
	geom->setVertexArray(vertices.get());

	for (faces_iterator itr = faces.begin(); itr != faces.end(); itr++)
	{
		geom->addPrimitiveSet(itr->get());
	}

	osgUtil::SmoothingVisitor::smooth(*geom);
	/*
	// DEBUG for normal vectors
	osg::Vec3Array* narray = dynamic_cast<osg::Vec3Array*>(geom->getNormalArray());
	double x, y, z;
	for (osg::Vec3Array::iterator itr = narray->begin(); itr != narray->end(); itr++)
	{
		x = itr->x();
		y = itr->y();
		z = itr->z();
	}
	*/
	osg::Geode* geo = new osg::Geode();
	geo->addDrawable(geom.get());

	return geo;
}


