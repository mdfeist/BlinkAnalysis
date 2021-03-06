

#include "StdAfx.h"

#include <sstream>
#include <osg/Geode>
#include <osg/Matrix>
#include <osg/MatrixTransform>

#include "MainFormController.h"


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
		WorldManager::getInstance()->addWorldNode(getAsGroup());
	else
		WorldManager::getInstance()->removeWorldNode(node);
}

bool CaptureWorld::toggleRender()
{
	render = !render;
	if (render)
		WorldManager::getInstance()->addWorldNode(getAsGroup());
	else
		WorldManager::getInstance()->removeWorldNode(node);
	return render;
}

osg::MatrixTransform* CaptureWorld::getAsGroup()
{
	if (!node)
	{
		node = new osg::MatrixTransform();
		node->setName("CaptureWorld node");
	}

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
				osg::Node* objNode = itr->second->getAsNode(this->id);
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

CaptureObject* CaptureWorld::addBox(osg::Vec3 baseCentre, osg::Vec3 dimensions, CentreType ct, std::string name)
{
	// divide dimensions to get half lengths
	osg::Vec3 hl = dimensions * 0.5;
	// transform base from global to local coordinates
	osg::Vec3 centre = baseCentre * getGlobalToLocalMatrix();
	// add z to get centre of box
	if (ct == CENTRE_BASE)
		centre += osg::Vec3(0, 0, hl.z());
	else if (ct == CENTRE_TOP)
		centre += osg::Vec3(0, 0, -hl.z());
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

CaptureObject* CaptureWorld::addCylinder(osg::Vec3 baseCentre, float radius, float height, CentreType ct, std::string name)
{
	// transform base from global to local coordinates
	osg::Vec3 centre = baseCentre * getGlobalToLocalMatrix();
	// add half of height to get centre of box
	if (ct == CENTRE_BASE)
		centre += osg::Vec3(0, 0, height/2);
	else if (ct == CENTRE_TOP)
		centre += osg::Vec3(0, 0, -height/2);
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

CaptureObject* CaptureWorld::addTemplate(osg::Vec3 centre, osg::Quat rotation, const char* filename, std::string name)
{
	// get XML file node
	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file(filename);

	if (result.status)
		return NULL;

	pugi::xml_node tempObject = doc.child("TemplateObject");
	CaptureObject* object = NULL;
	if (tempObject) {
		const char* type = tempObject.attribute("type").value();
		// plane will completely ignore centre and rotation input
		if (!strcmp(type, "plane"))
		{
			double x0, y0, z0;
			double x1, y1, z1;
			double x2, y2, z2;
			for (pugi::xml_node vert = tempObject.child("vertex"); vert; vert = vert.next_sibling("vertex"))
			{
				if (!strcmp(vert.attribute("id").value(), "0"))
				{
					x0 = atof(vert.attribute("x").value());
					y0 = atof(vert.attribute("y").value());
					z0 = atof(vert.attribute("z").value());
				}
				else if (!strcmp(vert.attribute("id").value(), "1"))
				{
					x1 = atof(vert.attribute("x").value());
					y1 = atof(vert.attribute("y").value());
					z1 = atof(vert.attribute("z").value());
				}
				else if (!strcmp(vert.attribute("id").value(), "3"))
				{
					x2 = atof(vert.attribute("x").value());
					y2 = atof(vert.attribute("y").value());
					z2 = atof(vert.attribute("z").value());
				}
			}

			object = new CaptureObjectPlane(osg::Vec3(x0, y0, z0), osg::Vec3(x1, y1, z1), osg::Vec3(x2, y2, z2));
		}
		else if (!strcmp(type, "box"))
		{
			osg::Vec3 dim;
			for (pugi::xml_node attr = tempObject.first_child(); attr; attr = attr.next_sibling())
			{
				if (!strcmp(attr.name(), "dimension"))
				{
					dim = osg::Vec3( atof(attr.attribute("x").value()),
										atof(attr.attribute("y").value()),
										atof(attr.attribute("z").value()) );
					dim /= 2;
				}
			}

			object = new CaptureObjectBox(centre, dim, rotation);
		}
		else if (!strcmp(type, "cylinder"))
		{
			float radius;
			float height;
			for (pugi::xml_node attr = tempObject.first_child(); attr; attr = attr.next_sibling())
			{
				if (!strcmp(attr.name(), "dimension"))
				{
					radius = atof(attr.attribute("radius").value());
					height = atof(attr.attribute("height").value());
				}
			}

			object = new CaptureObjectCylinder(centre, radius, height, rotation);
		}
		else
			return NULL;

		if (object)
		{
			object->setName(name);
			if (addObject(object) < 0)
			{
				delete object;
				object = NULL;
			}
		}
	}

	return object;
}

CaptureObject* CaptureWorld::addTemplateRigid(int rigidID, bool attachRigid, const char* filename, std::string name)
{
	ClientHandler* client = AppData::getInstance()->getClient();
	CaptureObject* object = NULL;
	if (client)
	{
		RigidBody* rb = client->getRigidBody(rigidID);
		// if attempting to attach to rigid body, make sure it belongs to the world
		if (rb && (!attachRigid || (rb->getWorldID() < 0 || rb->getWorldID() == this->id) )) 
		{
			osg::Vec3 pos = rb->getPosition();
			osg::Quat rot = rb->getRotation();

			object = addTemplate(pos, rot, filename, name);
			if (object && attachRigid)
			{
				if (rb->getWorldID() < 0)
					rb->setWorldID(this->id);

				// use relative transformation w.r.t. rigid body
				// so when rigid body detached, will keep initial position
				object->setRigidBody(rb, true);
				updateObjectsNode();
			}
		}
	}
	return object;
}

void CaptureWorld::saveTemplate(int oid, const char* filename)
{
	CaptureObject* object = getObject(oid);
	if (!object) return;

	// get XML file node
	pugi::xml_document doc;
	pugi::xml_node tempObject = doc.child("TemplateObject");

	if (!tempObject) {
		tempObject = doc.append_child();
		tempObject.set_name("TemplateObject");
	}
	else {
		while (tempObject.first_child()) tempObject.remove_child(tempObject.first_child());
	}

	char buf[128];
	ObjectType objType = object->getType();
	pugi::xml_attribute type = tempObject.attribute("type");

	if (!type)
		type = tempObject.append_attribute("type");
	
	type.set_value(CaptureObjectUtil::objectTypeToString(objType));

	// specific shape info
	if (objType == OBJ_PLANE)
	{
		CaptureObjectPlane* plane = dynamic_cast<CaptureObjectPlane*>(object);
		if (plane)
		{
			const osg::Vec3Array* vertices = plane->getVertices();
			int i = 0;
			for (osg::Vec3Array::const_iterator itr = vertices->begin(); itr != vertices->end(); itr++)
			{
				pugi::xml_node vert = tempObject.append_child("vertex");
				_itoa_s(i, buf, 10);
				vert.append_attribute("id").set_value(buf);
				vert.append_attribute("x").set_value(CaptureObjectUtil::floatToString(itr->x())->c_str());
				vert.append_attribute("y").set_value(CaptureObjectUtil::floatToString(itr->y())->c_str());
				vert.append_attribute("z").set_value(CaptureObjectUtil::floatToString(itr->z())->c_str());
				i++;
			}
		}
	}
	else if (objType == OBJ_BOX)
	{
		CaptureObjectBox* box = dynamic_cast<CaptureObjectBox*>(object);
		if (box)
		{
			osg::Vec3 vec = box->getHalfLengths();
			pugi::xml_node dim = tempObject.append_child("dimension");
			dim.append_attribute("x").set_value(CaptureObjectUtil::floatToString(vec.x()*2)->c_str());
			dim.append_attribute("y").set_value(CaptureObjectUtil::floatToString(vec.y()*2)->c_str());
			dim.append_attribute("z").set_value(CaptureObjectUtil::floatToString(vec.z()*2)->c_str());
		}
	}
	else if (objType == OBJ_CYLINDER)
	{
		CaptureObjectCylinder* cylinder = dynamic_cast<CaptureObjectCylinder*>(object);
		if (cylinder) 
		{
			pugi::xml_node dim = tempObject.append_child("dimension");
			dim.append_attribute("radius").set_value(CaptureObjectUtil::floatToString(cylinder->getRadius())->c_str());
			dim.append_attribute("height").set_value(CaptureObjectUtil::floatToString(cylinder->getHeight())->c_str());
		}
	}
	else if (objType == OBJ_CUSTOM)
	{
		CaptureObjectCustom* custom = dynamic_cast<CaptureObjectCustom*>(object);
		if (custom)
		{
			const osg::Vec3Array* vertices = custom->getVertices();
			int i = 0;
			for (osg::Vec3Array::const_iterator itr = vertices->begin(); itr != vertices->end(); itr++)
			{
				pugi::xml_node vert = tempObject.append_child("vertex");
				_itoa_s(i, buf, 10);
				vert.append_attribute("id").set_value(buf);
				vert.append_attribute("x").set_value(CaptureObjectUtil::floatToString(itr->x())->c_str());
				vert.append_attribute("y").set_value(CaptureObjectUtil::floatToString(itr->y())->c_str());
				vert.append_attribute("z").set_value(CaptureObjectUtil::floatToString(itr->z())->c_str());
				i++;
			}
		}
	}
	
	doc.save_file(filename);
}

