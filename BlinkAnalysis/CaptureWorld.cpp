

#include "StdAfx.h"

#include <sstream>
#include <osg/Geode>
#include <osg/MatrixTransform>

#include "CaptureWorld.h"


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

	return (ret.second == false) ? -1 : _lastObjectID++;
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


osg::Group* CaptureWorld::getAsGroup()
{
	if (!node)
		node = new osg::Group();

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



