

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

	// DEBUG: add some image texture to identify front and back
	osg::ref_ptr<osg::Vec2Array> texcoords = new osg::Vec2Array();
	texcoords->push_back(osg::Vec2(0, 0));
	texcoords->push_back(osg::Vec2(0, 1));
	texcoords->push_back(osg::Vec2(1, 1));
	texcoords->push_back(osg::Vec2(1, 0));
	geom->setTexCoordArray(0, texcoords.get());

	for (faces_iterator itr = faces.begin(); itr != faces.end(); itr++)
	{
		geom->addPrimitiveSet(itr->get());
	}

	osgUtil::SmoothingVisitor::smooth(*geom);
	osg::Geode* geo = new osg::Geode();
	geo->addDrawable(geom.get());

	// DEBUG: add some image texture to identify front and back
	osg::ref_ptr<osg::Texture2D> texture = new osg::Texture2D();
	osg::ref_ptr<osg::Image> image = osgDB::readImageFile("Images/blueFlowers.png");
	texture->setImage(image.get());
	geo->getOrCreateStateSet()->setTextureAttributeAndModes(0, texture.get());

	return geo;
}


