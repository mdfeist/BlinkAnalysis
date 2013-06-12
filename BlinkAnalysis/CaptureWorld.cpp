

#include "StdAfx.h"

#include <sstream>
#include <osg/Geode>
#include <osg/MatrixTransform>

#include "MainFormController.h"
#include "CaptureWorld.h"


int CaptureWorld::_lastWorldID = 0;

CaptureWorld::CaptureWorld()
{
	_lastObjectID = 0;
	id = _lastWorldID++;

	std::stringstream sstr;
	sstr << "World";
	sstr << id;
	name = sstr.str();

	_globalToLocal = new osg::Matrix();
	_globalToLocal->makeIdentity();

	node = NULL;
}

CaptureWorld::CaptureWorld(std::string name)
{
	_lastObjectID = 0;
	id = _lastWorldID++;

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

	_globalToLocal = new osg::Matrix();
	_globalToLocal->makeIdentity();

	node = NULL;
}

CaptureWorld::CaptureWorld(std::string name, osg::Matrix* globToLoc)
{
	_lastObjectID = 0;
	id = _lastWorldID++;

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

	_globalToLocal = globToLoc;

	node = NULL;
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

void CaptureWorld::setCoordinateFrame(osg::Matrix* globToLoc, bool deleteObjects, bool updateObjects)
{
	delete _globalToLocal;
	_globalToLocal = globToLoc;

	if (deleteObjects)
	{
		clearObjects();
		return;
	}
	if (updateObjects)
	{
		//TODO
	}

	if (node)
		node->setMatrix(getLocalToGlobalMatrix());
}

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
		MainFormController::getInstance()->objectUpdateList();
		return _lastObjectID++;
	}
	return -1;
}

	
bool CaptureWorld::removeObject(int id)
{
	objects_iterator itr = _objects.find(id);
	
	if (itr == _objects.end())
		return false;

	delete itr->second;
	_objects.erase(id);
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

CaptureObject* CaptureWorld::getObject(int id)
{
	objects_iterator itr = _objects.find(id);
	
	if (itr == _objects.end())
		return NULL;

	return itr->second;
}

// TODO: assumed static for now
CaptureObject* CaptureWorld::addPlane(osg::Vec3 corner, osg::Vec3 pt1, osg::Vec3 pt2, std::string name)
{
	CaptureObject* obj = new CaptureObject();
	// if name is empty string, one will be generated in addObject
	obj->setName(name);

	// set up plane vertices
	osg::Vec3 opposite = pt1 + pt2 - corner;
	osg::Vec3Array* vertices = new osg::Vec3Array();
	vertices->push_back(corner);
	vertices->push_back(pt1);
	vertices->push_back(opposite);
	vertices->push_back(pt2);
	obj->setVertices(vertices);

	// set up face
	osg::DrawElementsUInt* face = new osg::DrawElementsUInt(osg::PrimitiveSet::TRIANGLE_FAN, 5);
	face->push_back(0);
	face->push_back(1);
	face->push_back(2);
	face->push_back(2);
	face->push_back(3);
	obj->addFace(face);

	if (addObject(obj) < 0)
	{
		delete obj;
		obj = NULL;
	}

	return obj;
}


osg::MatrixTransform* CaptureWorld::getAsGroup(bool renderMatrix)
{
	if (!node)
		node = new osg::MatrixTransform();

	if (renderMatrix)
		node->setMatrix(getGlobalToLocalMatrix());
	else
		node->setMatrix(osg::Matrix::identity());

	node->removeChild(0, node->getNumChildren());
	for (objects_iterator itr = _objects.begin(); itr != _objects.end(); itr++)
	{
		// TODO 
		node->addChild(itr->second->getAsGeode());
	}

	return node;
}

void CaptureWorld::updateObjectsNode()
{
	if (node)
	{
		node->removeChild(0, node->getNumChildren());
		for (objects_iterator itr = _objects.begin(); itr != _objects.end(); itr++)
		{
			// TODO 
			node->addChild(itr->second->getAsGeode());
		}
	}
}



