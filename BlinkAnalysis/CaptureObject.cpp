

#include "StdAfx.h"
#include <osg/Geometry>
#include <osg/ShapeDrawable>
#include <osgUtil/SmoothingVisitor>

#include <osg/Texture2D>
#include <osgDB/ReadFile>

#include "CaptureObject.h"
#include "AppData.h"


///////////////////////////
// CaptureObject
///////////////////////////

void CaptureObject::setRigidBody(int rid, bool offset)
{
	if (rigidBody == rid)
		return;

	// remove from old rigid body
	if (rigidBody >= 0)
	{
		rigidNode->removeChild(node);
		rigidNode = NULL;
		// remove offset node if it exists
		while (!node->asGeode())
		{
			osg::Group* temp = node->asGroup();
			node = temp->getChild(0);
			temp->removeChild(node);
		}
	}

	// add to new rigid body
	ClientHandler* client = AppData::getInstance()->getClient();
	if (client && rid >= 0)
	{
		RigidBody* rb = client->getRigidBody(rid);
		if (rb)
		{
			rigidNode = rb->getObjectTransform();
			if (offset)
			{
				osg::AutoTransform* temp = new osg::AutoTransform();
				temp->setPosition(-rigidNode->getPosition());
				temp->setRotation(-rigidNode->getRotation());
				temp->addChild(node);
				node = temp;
			}
			rigidNode->addChild(node);
		}
	}
	rigidBody = rid;
}

osg::Node* CaptureObject::setRender(bool ren)
{
	// state unchanged, no need to return node
	if (render == ren)
		return NULL;
	
	render = ren;
	return (rigidNode) ? (osg::Node*) rigidNode : node; 
	// TODO why is it forcing me to cast every time?
}


///////////////////////////
// CaptureObjectCustom
///////////////////////////

osg::Node* CaptureObjectCustom::getAsNode()
{
	osg::Geode* geo;
	// no transformation node
	if (rigidBody < 0 || !node->asGroup() )
	{
		if (!node)
			node = new osg::Geode();
		geo = node->asGeode();
	}
	// has transformation node
	else 
	{
		osg::Group* group = node->asGroup();
		if (group->getNumChildren() <= 0)
		{
			geo = new osg::Geode();
			group->addChild(geo);
		}
		else
		{
			geo = group->getChild(0)->asGeode();
		}
	}

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

	return (rigidNode) ? (osg::Node*) rigidNode : node;
}

osg::Vec3 CaptureObjectCustom::getPosition()
{
	osg::Vec3 trans = CaptureObjectUtil::getWorldCoords(node)->getTrans();
	if (vertices->size() <=0 )
		return osg::Vec3(0,0,0) + trans;

	return vertices->at(0) + trans;
}

osg::Quat CaptureObjectCustom::getRotation()
{
	return CaptureObjectUtil::getWorldCoords(node)->getRotate();
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

osg::Node* CaptureObjectPlane::getAsNode()
{
	osg::Geode* geo;
	// no transformation node
	if (rigidBody < 0 || !node->asGroup() )
	{
		if (!node)
			node = new osg::Geode();
		geo = node->asGeode();
	}
	// has transformation node
	else 
	{
		osg::Group* group = node->asGroup();
		if (group->getNumChildren() <= 0)
		{
			geo = new osg::Geode();
			group->addChild(geo);
		}
		else
		{
			geo = group->getChild(0)->asGeode();
		}
	}

	geo->removeDrawables(0, 1);
	osg::Geometry *geom = new osg::Geometry();
	geom->setVertexArray(vertices.get());

	geom->addPrimitiveSet(face);
	
	osgUtil::SmoothingVisitor::smooth(*geom);
	geo->addDrawable(geom);

	return (rigidNode) ? (osg::Node*) rigidNode : node;
}

osg::Vec3 CaptureObjectPlane::getPosition()
{
	osg::Vec3 trans = CaptureObjectUtil::getWorldCoords(node)->getTrans();
	if (vertices->size() <=0 )
		return osg::Vec3(0,0,0) + trans;

	return vertices->at(0) + trans;
}

osg::Quat CaptureObjectPlane::getRotation()
{
	return CaptureObjectUtil::getWorldCoords(node)->getRotate();
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

osg::Node* CaptureObjectBox::getAsNode()
{
	osg::Geode* geo;
	// no transformation node
	if (rigidBody < 0 || !node->asGroup() )
	{
		if (!node)
			node = new osg::Geode();
		geo = node->asGeode();
	}
	// has transformation node
	else 
	{
		osg::Group* group = node->asGroup();
		if (group->getNumChildren() <= 0)
		{
			geo = new osg::Geode();
			group->addChild(geo);
		}
		else
		{
			geo = group->getChild(0)->asGeode();
		}
	}

	geo->removeDrawables(0, 1);
	if (box)
		geo->addDrawable(new osg::ShapeDrawable(box));

	return (rigidNode) ? (osg::Node*) rigidNode : node;
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

osg::Quat CaptureObjectBox::getRotationBox()
{
	if (box)
		return box->getRotation();
	return osg::Quat(0, 0, 0, 1); // zero rotation
}


osg::Vec3 CaptureObjectBox::getPosition()
{
	osg::Vec3 trans = CaptureObjectUtil::getWorldCoords(node)->getTrans();
	return getCentre() + trans;
}

osg::Quat CaptureObjectBox::getRotation()
{
	return CaptureObjectUtil::getWorldCoords(node)->getRotate() * getRotationBox();
}
