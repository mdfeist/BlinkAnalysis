

#include "StdAfx.h"

#include <sstream>
#include <osg/Geode>
#include <osg/Matrix>
#include <osg/MatrixTransform>

#include "MainFormController.h"
#include "CaptureWorld.h"


int CaptureWorld::_lastWorldID = 0;

void CaptureWorld::initCaptureWorld()
{
	_lastObjectID = 0;
	id = _lastWorldID++;

	std::stringstream sstr;
	sstr << "World";
	sstr << id;
	name = sstr.str();

	_localToGlobal = new osg::Matrix();
	_localToGlobal->makeIdentity();

	node = NULL;
	render = false;
	renderMat = false;
}

CaptureWorld::CaptureWorld()
{
	initCaptureWorld();
}

CaptureWorld::CaptureWorld(std::string name)
{
	initCaptureWorld();

	if (!name.empty())
		this->name = name;
}

CaptureWorld::CaptureWorld(std::string name, osg::Matrix* locToGlob)
{
	initCaptureWorld();

	if (!name.empty())
		this->name = name;

	_localToGlobal = locToGlob;
}

void CaptureWorld::setName(std::string name)
{
	if (!name.empty())
	{
		this->name = name;
	}
	else
	{
		std::stringstream sstr;
		sstr << "World";
		sstr << id;
		this->name = sstr.str();
	}
}

///////////////////////
// Matrix
const osg::Matrix CaptureWorld::getLocalToGlobalMatrix()
{
	return *_localToGlobal;
}

const osg::Matrix CaptureWorld::getGlobalToLocalMatrix()
{
	return osg::Matrix::inverse(*_localToGlobal);
}

void CaptureWorld::setCoordinateFrame(osg::Matrix* locToGlob, bool deleteObjects)
{
	delete _localToGlobal;
	_localToGlobal = locToGlob;

	if (deleteObjects)
	{
		clearObjects();
		return;
	}

	if (render && renderMat && node)
		node->setMatrix(getGlobalToLocalMatrix());
}

///////////////////////
// Rendering

void CaptureWorld::setRenderMatrix(bool ren)
{
	if (renderMat == ren)
		return;

	renderMat = ren;
	if (render && renderMat && node)
		node->setMatrix(getGlobalToLocalMatrix());
	else if (!renderMat && node)
		node->setMatrix(osg::Matrix::identity());
}

void CaptureWorld::setRender(bool ren)
{
	// rendering status unchanged, exit
	if (ren == render)
		return;

	render = ren;
	if (render)
		AppViewer::addNodeToViewer(getAsGroup());
	else
		AppViewer::removeNodeFromViewer(node);
}

bool CaptureWorld::toggleRender()
{
	render = !render;
	if (render)
		AppViewer::addNodeToViewer(getAsGroup());
	else
		AppViewer::removeNodeFromViewer(node);
	return render;
}

osg::MatrixTransform* CaptureWorld::getAsGroup()
{
	if (!node)
		node = new osg::MatrixTransform();

	if (renderMat)
		node->setMatrix(getGlobalToLocalMatrix());
	else
		node->setMatrix(osg::Matrix::identity());

	updateObjectsNode();
	return node;
}

void CaptureWorld::updateObjectsNode()
{
	if (node)
	{
		node->removeChild(0, node->getNumChildren());
		for (objects_iterator itr = _objects.begin(); itr != _objects.end(); itr++)
		{
			if (itr->second->renderObject())
			{
				osg::Node* objNode = itr->second->getAsNode();
				if (!node->containsNode(objNode))
					node->addChild(objNode);
			}
		}
	}
}

///////////////////////
// Object Management

int CaptureWorld::addObject(CaptureObject* obj)
{
	obj->setID(_lastObjectID);

	if (obj->getName().empty())
	{
		std::stringstream sstr;
		sstr << "Object";
		sstr << _lastObjectID;
		obj->setName(sstr.str());
	}

	std::pair<objects_iterator, bool> ret;
	ret = _objects.insert(std::pair<int, CaptureObject*>(_lastObjectID, obj));

	if (ret.second)
	{
		updateObjectsNode();
		MainFormController::getInstance()->objectUpdateList();
		// in case world displayed is the one being modified
		MainFormController::getInstance()->worldUpdateGridView(id); 
		return _lastObjectID++;
	}
	return -1;
}

bool CaptureWorld::removeObject(int oid)
{
	objects_iterator itr = _objects.find(oid);
	
	if (itr == _objects.end())
		return false;

	// remove object from currently rendering world
	osg::Node* objNode = itr->second->setRender(false);
	if (node && render)
		node->removeChild(objNode);

	delete itr->second;
	_objects.erase(itr);
	return true;
}

void CaptureWorld::clearObjects()
{
	for (objects_iterator itr = _objects.begin(); itr != _objects.end(); itr++)
	{
		delete itr->second;
	}
	_objects.clear();
	_lastObjectID = 0;
}

int CaptureWorld::getNumberObjects()
{
	return _objects.size();
}

CaptureObject* CaptureWorld::getObject(int oid)
{
	objects_iterator itr = _objects.find(oid);
	
	if (itr == _objects.end())
		return NULL;

	return itr->second;
}

void CaptureWorld::setRenderObject(int oid, bool ren)
{
	CaptureObject* obj = getObject(oid);
	if (!obj) return;
	osg::Node* objNode = obj->setRender(ren);

	// add object to currently rendering world
	if (objNode && ren && node && render && !node->containsNode(objNode))
	{
		node->addChild(objNode);
	}
	// remove object from currently rendering world
	else if (objNode && !ren && node && render)
	{
		node->removeChild(objNode);
	}
}

bool CaptureWorld::toggleRenderObject(int oid)
{
	CaptureObject* obj = getObject(oid);
	bool ren = !obj->renderObject();
	setRenderObject(oid, ren);
	return ren;
}

bool CaptureWorld::setObjectRigidBody(int oid, int rid, bool offset)
{
	ClientHandler* client = AppData::getInstance()->getClient();
	if (!client) return false;

	RigidBody* rb;
	// detach object
	if (rid < 0)
	{
		rb = NULL;
	}
	else 
	{
		// check if has ownership of rigid body transformation
		rb = client->getRigidBody(rid);
		if (!rb || 
			rb->getWorldID() >=0 && rb->getWorldID() != this->id) 
			return false;

		rb->setWorldID(this->id);
	}

	CaptureObject* object = getObject(oid);
	object->setRigidBody(rb, offset);
	updateObjectsNode();
	MainFormController::getInstance()->objectUpdateGridView(oid);
	return true;
}

///////////////////////
// Object Creation
CaptureObject* CaptureWorld::addPlane(osg::Vec3 corner, osg::Vec3 pt1, osg::Vec3 pt2, std::string name)
{
	CaptureObjectPlane* plane = new CaptureObjectPlane(corner, pt1, pt2);
	// if name is empty string, one will be generated in addObject
	plane->setName(name);

	if (addObject(plane) < 0)
	{
		delete plane;
		plane = NULL;
	}

	return plane;
}

CaptureObject* CaptureWorld::addPlaneRigid(int rigidID, bool attachRigid, std::string name)
{
	ClientHandler* client = AppData::getInstance()->getClient();
	if (client)
	{
		RigidBody* rb = client->getRigidBody(rigidID);
		// if attempting to attach to rigid body, make sure it belongs to the world
		if (rb && (!attachRigid || (rb->getWorldID() < 0 || rb->getWorldID() == this->id) )) 
		{
			std::vector<Marker>* markers = rb->getMarkersVector();
			if (markers)
			{
				osg::Vec3 corner = markers->at(0).getPosition();
				osg::Vec3 pt1 = markers->at(1).getPosition();
				osg::Vec3 pt2 = markers->at(2).getPosition();
				CaptureObjectPlane* plane = new CaptureObjectPlane(corner, pt1, pt2);
				
				// if name is empty string, one will be generated in addObject
				plane->setName(name);
				int oid = addObject(plane);
				if (oid < 0)
				{
					delete plane;
					plane = NULL;
				}
				else if (attachRigid)
				{
					if (rb->getWorldID() < 0)
						rb->setWorldID(this->id);

					// use relative transformation w.r.t. rigid body
					// so when rigid body detached, will keep initial position
					plane->setRigidBody(rb, true);
					updateObjectsNode();
				}
				return plane;
			}
		}
	}
	return NULL;
}

CaptureObject* CaptureWorld::addBox(osg::Vec3 baseCentre, osg::Vec3 dimensions, std::string name)
{
	// divide dimensions to get half lengths
	osg::Vec3 hl = dimensions * 0.5;
	// transform base from global to local coordinates
	osg::Vec3 centre = baseCentre * getGlobalToLocalMatrix();
	// add z to get centre of box
	centre += osg::Vec3(0, 0, hl.z());
	// transform back to global coordinates
	centre = centre * getLocalToGlobalMatrix();

	CaptureObjectBox* box = new CaptureObjectBox(centre, hl, getLocalToGlobalMatrix().getRotate());
	// if name is empty string, one will be generated in addObject
	box->setName(name);
	
	if (addObject(box) < 0)
	{
		delete box;
		box = NULL;
	}

	return box;
}
	
CaptureObject* CaptureWorld::addBoxRigid(int rigidID, osg::Vec3 dimensions, bool attachRigid, CentreType ct, std::string name)
{
	ClientHandler* client = AppData::getInstance()->getClient();
	if (client)
	{
		RigidBody* rb = client->getRigidBody(rigidID);
		// if attempting to attach to rigid body, make sure it belongs to the world
		if (rb && (!attachRigid || (rb->getWorldID() < 0 || rb->getWorldID() == this->id) )) 
		{
			// divide dimensions to get half lengths
			osg::Vec3 hl = dimensions * 0.5;

			osg::Vec3 pos = rb->getPosition();
			osg::Quat rot = rb->getRotation();
			// add rotated z to get centre of box
			if (ct == CENTRE_BASE)
				pos += rot * osg::Vec3(0, 0, hl.z());
			else if (ct == CENTRE_TOP)
				pos += rot * osg::Vec3(0, 0, -hl.z());

			CaptureObjectBox* box = new CaptureObjectBox(pos, hl, rot);
			// if name is empty string, one will be generated in addObject
			box->setName(name);
			int oid = addObject(box);
			if (oid < 0)
			{
				delete box;
				box = NULL;
			}
			else if (attachRigid)
			{
				if (rb->getWorldID() < 0)
					rb->setWorldID(this->id);

				// use relative transformation w.r.t. rigid body
				// so when rigid body detached, will keep initial position
				box->setRigidBody(rb, true);
				updateObjectsNode();
			}
			return box;
		}
	}
	return NULL;
}

CaptureObject* CaptureWorld::addCylinder(osg::Vec3 baseCentre, float radius, float height, std::string name)
{
	// transform base from global to local coordinates
	osg::Vec3 centre = baseCentre * getGlobalToLocalMatrix();
	// add half of height to get centre of box
	centre += osg::Vec3(0, 0, height/2);
	// transform back to global coordinates
	centre = centre * getLocalToGlobalMatrix();

	CaptureObjectCylinder* cylinder = new CaptureObjectCylinder(centre, radius, height, getLocalToGlobalMatrix().getRotate());
	// if name is empty string, one will be generated in addObject
	cylinder->setName(name);
	
	if (addObject(cylinder) < 0)
	{
		delete cylinder;
		cylinder = NULL;
	}

	return cylinder;
}

CaptureObject* CaptureWorld::addCylinderRigid(int rigidID, float radius, float height, bool attachRigid, CentreType ct, std::string name)
{
	ClientHandler* client = AppData::getInstance()->getClient();
	if (client)
	{
		RigidBody* rb = client->getRigidBody(rigidID);
		// if attempting to attach to rigid body, make sure it belongs to the world
		if (rb && (!attachRigid || (rb->getWorldID() < 0 || rb->getWorldID() == this->id) )) 
		{
			osg::Vec3 pos = rb->getPosition();
			osg::Quat rot = rb->getRotation();
			// add rotated z to get centre of box
			if (ct == CENTRE_BASE)
				pos += rot * osg::Vec3(0, 0, height/2);
			else if (ct == CENTRE_TOP)
				pos += rot * osg::Vec3(0, 0, -height/2);

			CaptureObjectCylinder* cylinder = new CaptureObjectCylinder(pos, radius, height, rot);
			// if name is empty string, one will be generated in addObject
			cylinder->setName(name);
			int oid = addObject(cylinder);
			if (oid < 0)
			{
				delete cylinder;
				cylinder = NULL;
			}
			else if (attachRigid)
			{
				if (rb->getWorldID() < 0)
					rb->setWorldID(this->id);

				// use relative transformation w.r.t. rigid body
				// so when rigid body detached, will keep initial position
				cylinder->setRigidBody(rb, true);
				updateObjectsNode();
			}
			return cylinder;
		}
	}
	return NULL;
}



