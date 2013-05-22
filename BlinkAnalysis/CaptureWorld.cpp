

#include "StdAfx.h"

#include <sstream>

#include "CaptureWorld.h"



CaptureWorld::CaptureWorld(osg::Matrix locToGlob)
{
	_localToGlobal = locToGlob;
	_globalToLocal = osg::Matrix::inverse(locToGlob);
	_lastObjectID = 0;
}

void CaptureWorld::setCoordinateFrame(osg::Matrix locToGlob, bool deleteObjects, bool updateObjects)
{
	_localToGlobal = locToGlob;
	_globalToLocal = osg::Matrix::inverse(locToGlob);

	if (deleteObjects)
	{
		clearObjects();
		return;
	}
	if (updateObjects)
	{
		//TODO
	}
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

	_objects.insert(std::pair<int, CaptureObject*>(_lastObjectID, obj));

	return _lastObjectID++;
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
int CaptureWorld::addPlane(osg::Vec3 corner, osg::Vec3 pt1, osg::Vec3 pt2, std::string name)
{
	CaptureObject* obj = new CaptureObject();
	// if name is empty string, one will be generated in addObject
	obj->setName(name);

	// set up plane vertices
	osg::Vec3 opposite = pt1 + pt2 - corner;
	osg::Vec3Array* vertices = new osg::Vec3Array(4);
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

	return addObject(obj);
}


osg::Node* CaptureWorld::getAsNode()
{
	
	osg::ref_ptr<osg::MatrixTransform> node = new osg::MatrixTransform();
	node->setMatrix(_globalToLocal);

	for (objects_iterator itr = _objects.begin(); itr != _objects.end(); itr++)
	{
		// TODO 
		// is there a way to avoid Geode to Node casting? 
		node->addChild((osg::Node*)itr->second->getAsGeode());
	}

	return node.release();
}



