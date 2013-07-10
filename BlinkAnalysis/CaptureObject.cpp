

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

void CaptureObject::setRigidBody(RigidBody* rb, bool offset)
{
	// remove from old rigid body
	if (rigidBody >= 0)
	{
		rigidNode->removeChild(node);
		if ( rigidNode->getNumChildren() == 0 &&
			 (!rb || rigidBody != rb->getID()) ) // no more children attached
		{
			ClientHandler *client = AppData::getInstance()->getClient();
			if (client)
			{
				RigidBody *oldRB = client->getRigidBody(rigidBody);
				oldRB->setWorldID(-1);
			}
		}
		setTransformation(rigidNode);
		rigidNode = NULL;
	}

	// detaching rigid body only
	if (!rb)
	{
		rigidBody = -1;
		return;
	}

	// add to new rigid body
	rigidNode = rb->getTransform();
	if (offset)
	{
		setTransformationInverse(rigidNode);
	}
	else
	{
		// zero transformation
		setTransformation(NULL);
	}
	rigidNode->addChild(node);
	rigidBody = rb->getID();
}

// returns node to be added/removed from world
osg::Node* CaptureObject::setRender(bool ren)
{
	// state unchanged, no need to return node
	if (render == ren)
		return NULL;
	
	render = ren;

	// no rigid body attached
	if (rigidBody < 0)
		return node;

	// if attached to rigid body, just remove from transformation
	// don't remove transformation node from world
	if (render)
		rigidNode->addChild(node);
	else
		rigidNode->removeChild(node);
	return NULL;
}


///////////////////////////
// CaptureObjectCustom
///////////////////////////

osg::Node* CaptureObjectCustom::getAsNode(int wid)
{
	if (!node)
	{
		node = new osg::Geode();
		std::stringstream sstr;
		sstr << "OBJ ";
		sstr << wid;
		sstr << ",";
		sstr << this->id;
		node->setName(sstr.str());
	}
	osg::Geode*	geo = node->asGeode();

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
	osg::Vec3 trans;
	if (!rigidNode || rigidNode->containsNode(node))
		trans = CaptureObjectUtil::getWorldCoords(node)->getTrans();
	else
		trans = ( *CaptureObjectUtil::getWorldCoords(rigidNode) *
				  *CaptureObjectUtil::getWorldCoords(node) ).getTrans();

	if (vertices->size() <=0 )
		return osg::Vec3(0,0,0) + trans;

	return vertices->at(0) + trans;
}

osg::Quat CaptureObjectCustom::getRotation()
{
	if (!rigidNode || rigidNode->containsNode(node))
		return CaptureObjectUtil::getWorldCoords(node)->getRotate();
	else 
		return ( *CaptureObjectUtil::getWorldCoords(rigidNode) *
				 *CaptureObjectUtil::getWorldCoords(node) ).getRotate();
}

// TODO: custom data does not have position and orientation data
// so there's no real definition for "reset transformation"
void CaptureObjectCustom::setTransformation(osg::AutoTransform* transformNode)
{
	// apply transformation to all vertices
	if (transformNode != NULL)
	{
		for (osg::Vec3Array::iterator itr = vertices->begin(); itr != vertices->end(); itr++)
		{
			*itr += transformNode->getPosition();
			*itr = transformNode->getRotation() * *itr;
		}
	}
}

void CaptureObjectCustom::setTransformationInverse(osg::AutoTransform* transformNode)
{
	// apply transformation to all vertices
	if (transformNode != NULL)
	{
		// inverse transformation
		osg::Matrixd* matrix = CaptureObjectUtil::createInverseMatrix(transformNode);

		for (osg::Vec3Array::iterator itr = vertices->begin(); itr != vertices->end(); itr++)
		{
			*itr += matrix->getTrans();
			*itr = matrix->getRotate() * *itr;
		}
		delete matrix;
	}
}


///////////////////////////
// CaptureObjectPlane
///////////////////////////

CaptureObjectPlane::CaptureObjectPlane(osg::Vec3 corner, osg::Vec3 pt1, osg::Vec3 pt2)
	: CaptureObject()
{
	setType(OBJ_PLANE);
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

osg::Node* CaptureObjectPlane::getAsNode(int wid)
{
	if (!node)
	{
		node = new osg::Geode();
		std::stringstream sstr;
		sstr << "OBJ ";
		sstr << wid;
		sstr << ",";
		sstr << this->id;
		node->setName(sstr.str());
	}
	osg::Geode*	geo = node->asGeode();

	geo->removeDrawables(0, 1);
	osg::Geometry *geom = new osg::Geometry();
	geom->setVertexArray(vertices.get());

	geom->addPrimitiveSet(face);
	
	osgUtil::SmoothingVisitor::smooth(*geom);
	geo->addDrawable(geom);

	return (rigidNode) ? (osg::Node*) rigidNode : node;
	// TODO why is it forcing me to cast every time?
}

osg::Vec3 CaptureObjectPlane::getPosition()
{
	osg::Vec3 trans;
	if (!rigidNode || rigidNode->containsNode(node))
		trans = CaptureObjectUtil::getWorldCoords(node)->getTrans();
	else
		trans = ( *CaptureObjectUtil::getWorldCoords(rigidNode) *
				  *CaptureObjectUtil::getWorldCoords(node) ).getTrans();

	if (vertices->size() <=0 )
		return osg::Vec3(0,0,0) + trans;

	return vertices->at(0) + trans;
}

osg::Quat CaptureObjectPlane::getRotation()
{
	if (!rigidNode || rigidNode->containsNode(node))
		return CaptureObjectUtil::getWorldCoords(node)->getRotate();
	else 
		return ( *CaptureObjectUtil::getWorldCoords(rigidNode) *
				 *CaptureObjectUtil::getWorldCoords(node) ).getRotate();
}

// TODO: plane does not have position and orientation data
// so there's no real definition for "reset transformation"
void CaptureObjectPlane::setTransformation(osg::AutoTransform* transformNode)
{
	// apply transformation to all vertices
	if (transformNode != NULL)
	{
		for (osg::Vec3Array::iterator itr = vertices->begin(); itr != vertices->end(); itr++)
		{
			*itr += transformNode->getPosition();
			*itr = transformNode->getRotation() * *itr;
		}
	}
}

void CaptureObjectPlane::setTransformationInverse(osg::AutoTransform* transformNode)
{
	// apply transformation to all vertices
	if (transformNode != NULL)
	{
		// inverse transformation
		osg::Matrixd* matrix = CaptureObjectUtil::createInverseMatrix(transformNode);

		for (osg::Vec3Array::iterator itr = vertices->begin(); itr != vertices->end(); itr++)
		{
			*itr += matrix->getTrans();
			*itr = matrix->getRotate() * *itr;
		}
		delete matrix;
	}
}


///////////////////////////
// CaptureObjectBox
///////////////////////////

CaptureObjectBox::CaptureObjectBox(osg::Vec3 centre, osg::Vec3 halfLen, osg::Quat rot)
{
	type = OBJ_BOX;
	box = new osg::Box();
	box->set(centre, halfLen);
	box->setRotation(rot);
}

osg::Node* CaptureObjectBox::getAsNode(int wid)
{
	if (!node)
	{
		node = new osg::Geode();
		std::stringstream sstr;
		sstr << "OBJ ";
		sstr << wid;
		sstr << ",";
		sstr << this->id;
		node->setName(sstr.str());
	}
	osg::Geode*	geo = node->asGeode();

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
	osg::Vec3 trans;
	if (!rigidNode || rigidNode->containsNode(node))
		trans = CaptureObjectUtil::getWorldCoords(node)->getTrans();
	else
		trans = ( *CaptureObjectUtil::getWorldCoords(rigidNode) *
				  *CaptureObjectUtil::getWorldCoords(node) ).getTrans();

	return getCentre() + trans;
}

osg::Quat CaptureObjectBox::getRotation()
{
	if (!rigidNode || rigidNode->containsNode(node))
		return CaptureObjectUtil::getWorldCoords(node)->getRotate() * getRotationBox();
	else 
		return ( *CaptureObjectUtil::getWorldCoords(rigidNode) *
				 *CaptureObjectUtil::getWorldCoords(node) ).getRotate() * getRotationBox();
}

void CaptureObjectBox::setTransformation(osg::AutoTransform* transformNode)
{
	if (!box) return;

	if (transformNode)
	{
		box->setCenter(transformNode->getPosition() + getCentre());
		box->setRotation(transformNode->getRotation() * getRotationBox());
	}
	// reset
	else
	{
		box->setCenter(osg::Vec3(0, 0, 0));
		box->setRotation(osg::Quat(0, 0, 0, 1));
	}
}

void CaptureObjectBox::setTransformationInverse(osg::AutoTransform* transformNode)
{
	if (!box || !transformNode) return;

	osg::Matrixd* matrix = CaptureObjectUtil::createInverseMatrix(transformNode);
	box->setCenter(matrix->getTrans() + getCentre());
	box->setRotation(matrix->getRotate() * getRotationBox());
	delete matrix;
}


///////////////////////////
// CaptureObjectCylinder
///////////////////////////

CaptureObjectCylinder::CaptureObjectCylinder(osg::Vec3 centre, float radius, float height, osg::Quat rot)
{
	type = OBJ_CYLINDER;
	cylinder = new osg::Cylinder();
	cylinder->set(centre, radius, height);
	cylinder->setRotation(rot);
}

osg::Node* CaptureObjectCylinder::getAsNode(int wid)
{
	if (!node)
	{
		node = new osg::Geode();
		std::stringstream sstr;
		sstr << "OBJ ";
		sstr << wid;
		sstr << ",";
		sstr << this->id;
		node->setName(sstr.str());
	}
	osg::Geode*	geo = node->asGeode();

	geo->removeDrawables(0, 1);
	if (cylinder)
		geo->addDrawable(new osg::ShapeDrawable(cylinder));

	return (rigidNode) ? (osg::Node*) rigidNode : node;
}

void CaptureObjectCylinder::setCentre(osg::Vec3 centre)
{
	if (!cylinder)
		cylinder = new osg::Cylinder();
	cylinder->setCenter(centre);
}

osg::Vec3 CaptureObjectCylinder::getCentre()
{
	if (cylinder)
		return cylinder->getCenter();
	return osg::Vec3(0, 0, 0); 
}


void CaptureObjectCylinder::setRotation(osg::Quat rot)
{
	if (!cylinder)
		cylinder = new osg::Cylinder();
	cylinder->setRotation(rot);
}

osg::Quat CaptureObjectCylinder::getRotationCylinder()
{
	if (cylinder)
		return cylinder->getRotation();
	return osg::Quat(0, 0, 0, 1); // zero rotation
}

void CaptureObjectCylinder::setRadius(float radius)
{
	if (!cylinder)
		cylinder = new osg::Cylinder();
	cylinder->setRadius(radius);
}

float CaptureObjectCylinder::getRadius()
{
	if (cylinder)
		return cylinder->getRadius();
	return -1; 
}

void CaptureObjectCylinder::setHeight(float height)
{
	if (!cylinder)
		cylinder = new osg::Cylinder();
	cylinder->setHeight(height);
}

float CaptureObjectCylinder::getHeight()
{
	if (cylinder)
		return cylinder->getHeight();
	return -1; 
}

osg::Vec3 CaptureObjectCylinder::getPosition()
{
	osg::Vec3 trans;
	if (!rigidNode || rigidNode->containsNode(node))
		trans = CaptureObjectUtil::getWorldCoords(node)->getTrans();
	else
		trans = ( *CaptureObjectUtil::getWorldCoords(rigidNode) *
				  *CaptureObjectUtil::getWorldCoords(node) ).getTrans();

	return getCentre() + trans;
}

osg::Quat CaptureObjectCylinder::getRotation()
{
	if (!rigidNode || rigidNode->containsNode(node))
		return CaptureObjectUtil::getWorldCoords(node)->getRotate() * getRotationCylinder();
	else 
		return ( *CaptureObjectUtil::getWorldCoords(rigidNode) *
				 *CaptureObjectUtil::getWorldCoords(node) ).getRotate() * getRotationCylinder();
}

void CaptureObjectCylinder::setTransformation(osg::AutoTransform* transformNode)
{
	if (!cylinder) return;

	if (transformNode)
	{
		cylinder->setCenter(transformNode->getPosition() + getCentre());
		cylinder->setRotation(transformNode->getRotation() * getRotationCylinder());
	}
	// reset
	else
	{
		cylinder->setCenter(osg::Vec3(0, 0, 0));
		cylinder->setRotation(osg::Quat(0, 0, 0, 1));
	}
}

void CaptureObjectCylinder::setTransformationInverse(osg::AutoTransform* transformNode)
{
	if (!cylinder || !transformNode) return;

	osg::Matrixd* matrix = CaptureObjectUtil::createInverseMatrix(transformNode);
	cylinder->setCenter(matrix->getTrans() + getCentre());
	cylinder->setRotation(matrix->getRotate() * getRotationCylinder());
	delete matrix;
}
