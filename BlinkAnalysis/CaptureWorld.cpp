

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

	_globalToLocal = new osg::Matrix();
	_globalToLocal->makeIdentity();

	node = NULL;
	render = true;
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

CaptureWorld::CaptureWorld(std::string name, osg::Matrix* globToLoc)
{
	initCaptureWorld();

	if (!name.empty())
		this->name = name;

	_globalToLocal = globToLoc;
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

const osg::Matrix CaptureWorld::getLocalToGlobalMatrix()
{
	return osg::Matrix::inverse(*_globalToLocal);
}

const osg::Matrix CaptureWorld::getGlobalToLocalMatrix()
{
	return *_globalToLocal;
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

void CaptureWorld::setRenderObject(int oid, bool ren)
{
	CaptureObject* obj = getObject(oid);
	// add object to currently rendering world
	osg::Node* objNode = obj->setRender(ren);
	if (ren && obj && node && render)
	{
		node->addChild(objNode);
	}
	// remove object from currently rendering world
	else if (!ren && obj && node && render)
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

// TODO: assumed static for now
CaptureObject* CaptureWorld::addPlane(osg::Vec3 corner, osg::Vec3 pt1, osg::Vec3 pt2, std::string name)
{
	CaptureObject* obj = new CaptureObject();
	// if name is empty string, one will be generated in addObject
	obj->setName(name);

	// set up plane vertices
	osg::Vec3 opposite = pt1 + pt2 - corner;
	osg::ref_ptr<osg::Vec3Array> vertices = new osg::Vec3Array();
	vertices->push_back(corner);
	vertices->push_back(pt1);
	vertices->push_back(opposite);
	vertices->push_back(pt2);
	obj->setVertices(vertices);

	// set up face
	osg::ref_ptr<osg::DrawElementsUInt> face = new osg::DrawElementsUInt(osg::PrimitiveSet::TRIANGLE_FAN);
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
		if (itr->second->renderObject())
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
			if (itr->second->renderObject())
				node->addChild(itr->second->getAsGeode());
		}
	}
}



