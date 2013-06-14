

#include "StdAfx.h"
#include <osg/Geometry>
#include <osgUtil/SmoothingVisitor>

#include <osg/Texture2D>
#include <osgDB/ReadFile>

#include "CaptureObject.h"


int CaptureObject::getNumVertices() 
{ 
	return vertices->size(); 
}

void CaptureObject::setVertices(osg::Vec3Array* vertices) { 
	this->vertices = vertices; 
}

void CaptureObject::addFace(osg::DrawElementsUInt* face) { 
	faces.push_back(face); 
}

void CaptureObject::removeFaces() { 
	faces.clear(); 
}

osg::Geode* CaptureObject::getAsGeode()
{
	if (!node)
		node = new osg::Geode();

	osg::Geode* geo = node->asGeode();
	geo->removeDrawables(0, geo->getNumDrawables());
	osg::Geometry *geom = new osg::Geometry();
	geom->setVertexArray(vertices.get());

	for (faces_iterator itr = faces.begin(); itr != faces.end(); itr++)
	{
		geom->addPrimitiveSet(itr->get());
	}
	osgUtil::SmoothingVisitor::smooth(*geom);
	geo->addDrawable(geom);

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

	return geo;
}

osg::Node* CaptureObject::setRender(bool ren)
{
	// state unchanged, no need to return node
	if (render == ren)
		return NULL;
	
	render = ren;
	return node;
}


