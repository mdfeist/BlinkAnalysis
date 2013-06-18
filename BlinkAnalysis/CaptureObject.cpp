

#include "StdAfx.h"
#include <osg/Geometry>
#include <osg/ShapeDrawable>
#include <osgUtil/SmoothingVisitor>

#include <osg/Texture2D>
#include <osgDB/ReadFile>

#include "CaptureObject.h"


///////////////////////////
// CaptureObject
///////////////////////////

osg::Node* CaptureObject::setRender(bool ren)
{
	// state unchanged, no need to return node
	if (render == ren)
		return NULL;
	
	render = ren;
	return node;
}


///////////////////////////
// CaptureObjectCustom
///////////////////////////

osg::Geode* CaptureObjectCustom::getAsGeode()
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



///////////////////////////
// CaptureObjectPlane
///////////////////////////

CaptureObjectPlane::CaptureObjectPlane(osg::Vec3 corner, osg::Vec3 pt1, osg::Vec3 pt2)
	: CaptureObject()
{
	setType(PLANE);
	setVertices(corner, pt1, pt2);
}

void CaptureObjectPlane::setVertices(osg::Vec3 corner, osg::Vec3 pt1, osg::Vec3 pt2)
{
	// set up plane vertices
	if (!vertices)
		vertices = new osg::Vec3Array();
	else
		vertices->clear();

	osg::Vec3 opposite = pt1 + pt2 - corner;
	vertices->push_back(corner);
	vertices->push_back(pt1);
	vertices->push_back(opposite);
	vertices->push_back(pt2);

	// set up face
	if (!face)
		face = new osg::DrawElementsUInt(osg::PrimitiveSet::TRIANGLE_FAN);
	else
		face->clear();

	face->push_back(0);
	face->push_back(1);
	face->push_back(2);
	face->push_back(2);
	face->push_back(3);
}

osg::Geode* CaptureObjectPlane::getAsGeode()
{
	if (!node)
		node = new osg::Geode();

	osg::Geode* geo = node->asGeode();
	geo->removeDrawables(0, 1);
	osg::Geometry *geom = new osg::Geometry();
	geom->setVertexArray(vertices.get());

	geom->addPrimitiveSet(face);
	
	osgUtil::SmoothingVisitor::smooth(*geom);
	geo->addDrawable(geom);

	return geo;
}


///////////////////////////
// CaptureObjectBox
///////////////////////////

CaptureObjectBox::CaptureObjectBox(osg::Vec3 centre, osg::Vec3 halfLen, osg::Quat rot)
{
	box = new osg::Box();
	box->set(centre, halfLen);
	box->setRotation(rot);
}

osg::Geode* CaptureObjectBox::getAsGeode()
{
	if (!node)
		node = new osg::Geode();

	osg::Geode* geo = node->asGeode();
	geo->removeDrawables(0, 1);
	if (box)
		geo->addDrawable(new osg::ShapeDrawable(box));

	return geo;
}

void CaptureObjectBox::setCentre(osg::Vec3 centre)
{
	if (!box)
		box = new osg::Box();
	box->setCenter(centre);
}

osg::Vec3 CaptureObjectBox::getCentre()
{
	if (box)
		return box->getCenter();
	return osg::Vec3(0, 0, 0); 
}

void CaptureObjectBox::setHalfLengths(osg::Vec3 halfLen)
{
	if (!box)
		box = new osg::Box();
	box->setHalfLengths(halfLen);
}

osg::Vec3 CaptureObjectBox::getHalfLengths()
{
	if (box)
		return box->getHalfLengths();
	return osg::Vec3(0, 0, 0); 
}

void CaptureObjectBox::setRotation(osg::Quat rot)
{
	if (!box)
		box = new osg::Box();
	box->setRotation(rot);
}

osg::Quat CaptureObjectBox::getRotation()
{
	if (box)
		return box->getRotation();
	return osg::Quat(0, 0, 0, 1); // zero rotation
}

