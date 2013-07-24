
#include "StdAfx.h"
#include "WorldManager.h"

#include <sstream>
#include "MainFormController.h"



WorldManager* WorldManager::m_pInstance = NULL; 

WorldManager::WorldManager(void)
{
	worldNode = new osg::Group();
	worldNode->setName("WorldManager worldNode");
}

WorldManager::~WorldManager(void)
{
}

bool WorldManager::addWorld(CaptureWorld *world)
{
	int id = world->getID();

	std::pair<worlds_iterator, bool> ret;
	ret = worlds.insert(std::pair<int, CaptureWorld*>(id, world));

	if (ret.second) // added successfully
	{
		world->setRender(true);
		MainFormController::getInstance()->worldUpdateList();
		return true;
	}
	return false;
}

CaptureWorld* WorldManager::getWorld(int id)
{
	worlds_iterator itr = worlds.find(id);
	
	if (itr == worlds.end())
		return NULL;

	return itr->second;
}

int WorldManager::getNumberWorlds()
{
	return worlds.size();
}

std::map<int, CaptureWorld*> WorldManager::getWorlds()
{
	return worlds;
}

bool WorldManager::removeWorld(int id)
{
	worlds_iterator itr = worlds.find(id);
	
	if (itr == worlds.end())
		return false;

	itr->second->setRender(false);

	delete itr->second;
	worlds.erase(id);
	return true;
}

void WorldManager::clearWorlds(bool stopRender)
{
	for (worlds_iterator itr = worlds.begin(); itr != worlds.end(); itr++)
	{
		if (stopRender)
			itr->second->setRender(false);
		delete itr->second;
	}
	worlds.clear();
}

bool WorldManager::addWorldNode(osg::Node* wNode)
{
	if (!worldNode.valid()) return false;
	return worldNode->addChild(wNode);
}

bool WorldManager::removeWorldNode(osg::Node* wNode)
{
	if (!worldNode.valid()) return false;
	return worldNode->removeChild(wNode);
}

osg::Node* WorldManager::getWorldNode()
{
	return worldNode.get();
}

std::string WorldManager::getWorldStaticData()
{
	std::ostringstream sstream;
	std::map<int, CaptureWorld*> worlds = WorldManager::getInstance()->getWorlds();
	for (worlds_iterator witr = worlds.begin(); witr != worlds.end(); witr++)
	{
		streamWorld(witr->second, sstream);
	}
	return sstream.str();
}


void WorldManager::streamObject(CaptureObject* object, std::ostringstream& sstream) {
	if (!object) return;

	ObjectType type = object->getType();
	sstream << "<CaptureObject ";
	sstream << "id=\"" << object->getID() << "\" ";
	sstream << "name=\"" << object->getName() << "\" ";
	sstream << "type=\"" << CaptureObjectUtil::objectTypeToString(type) << "\" ";
	sstream << "rigidID=\"" << object->getRigidBody() << "\" ";
	sstream << "rigidOffset=\"" << (object->hasRigidOffset() ? "true" : "false") << "\" ";
	sstream << ">\n";

	// rigid body offset matrix
	if (object->hasRigidOffset())
	{
		//TODO
		const osg::Matrix* mat = object->getOffsetMatrix();
		if (mat)
		{
			sstream << "<TransformationMatrix ";
			sstream << "type=\"rigidOffset\" ";
			sstream << ">\n";
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					sstream << "<matrixValue ";
					sstream << "index=\"" << i << j << "\" ";
					sstream << "value=\"" << (*mat)(i, j) << "\" ";
					sstream << "/>\n";
				}
			}
			sstream << "</TransformationMatrix>\n";
		}
	}

	// specific shape info
	if (type == OBJ_PLANE)
	{
		CaptureObjectPlane* plane = dynamic_cast<CaptureObjectPlane*>(object);
		if (plane)
		{
			const osg::Vec3Array* vertices = plane->getVertices();
			int i = 0;
			for (osg::Vec3Array::const_iterator itr = vertices->begin(); itr != vertices->end(); itr++)
			{
				sstream << "<vertex ";
				sstream << "id=\"" << i << "\" ";
				sstream << "x=\"" << itr->x() << "\" ";
				sstream << "y=\"" << itr->y() << "\" ";
				sstream << "z=\"" << itr->z() << "\" ";
				sstream << "/>\n";
				i++;
			}
		}
	}
	else if (type == OBJ_BOX)
	{
		CaptureObjectBox* box = dynamic_cast<CaptureObjectBox*>(object);
		if (box)
		{
			osg::Vec3 vec = box->getCentre();
			sstream << "<centre ";
			sstream << "x=\"" << vec.x() << "\" ";
			sstream << "y=\"" << vec.y() << "\" ";
			sstream << "z=\"" << vec.z() << "\" ";
			sstream << "/>\n";

			vec = box->getHalfLengths();
			sstream << "<dimension ";
			sstream << "width=\"" << vec.x()*2 << "\" ";
			sstream << "length=\"" << vec.y()*2 << "\" ";
			sstream << "height=\"" << vec.z()*2 << "\" ";
			sstream << "/>\n";

			osg::Quat quat = box->getRotationBox();
			sstream << "<rotation ";
			sstream << "x=\"" << quat.x() << "\" ";
			sstream << "y=\"" << quat.y() << "\" ";
			sstream << "z=\"" << quat.z() << "\" ";
			sstream << "w=\"" << quat.w() << "\" ";
			sstream << "/>\n";
		}
	}
	else if (type == OBJ_CYLINDER)
	{
		CaptureObjectCylinder* cylinder = dynamic_cast<CaptureObjectCylinder*>(object);
		if (cylinder) 
		{
			osg::Vec3 vec = cylinder->getCentre();
			sstream << "<centre ";
			sstream << "x=\"" << vec.x() << "\" ";
			sstream << "y=\"" << vec.y() << "\" ";
			sstream << "z=\"" << vec.z() << "\" ";
			sstream << "/>\n";

			sstream << "<dimension ";
			sstream << "radius=\"" << cylinder->getRadius() << "\" ";
			sstream << "height=\"" << cylinder->getHeight() << "\" ";
			sstream << "/>\n";

			osg::Quat quat = cylinder->getRotationCylinder();
			sstream << "<rotation ";
			sstream << "x=\"" << quat.x() << "\" ";
			sstream << "y=\"" << quat.y() << "\" ";
			sstream << "z=\"" << quat.z() << "\" ";
			sstream << "w=\"" << quat.w() << "\" ";
			sstream << "/>\n";
		}
	}
	else if (type == OBJ_CUSTOM)
	{
		CaptureObjectCustom* custom = dynamic_cast<CaptureObjectCustom*>(object);
		if (custom)
		{
			const osg::Vec3Array* vertices = custom->getVertices();
			int i = 0;
			for (osg::Vec3Array::const_iterator itr = vertices->begin(); itr != vertices->end(); itr++)
			{
				sstream << "<Vertex ";
				sstream << "id=\"" << i << "\" ";
				sstream << "x=\"" << itr->x() << "\" ";
				sstream << "y=\"" << itr->y() << "\" ";
				sstream << "z=\"" << itr->z() << "\" ";
				sstream << "/>\n";
				i++;
			}
		}
	}

	sstream << "</CaptureObject>\n";
}

void WorldManager::streamWorld(CaptureWorld* world, std::ostringstream& sstream) {
	if (!world) return;

	sstream << "<CaptureWorld ";
	sstream << "id=\"" << world->getID() << "\" ";
	sstream << "name=\"" << world->getName() << "\" ";
	sstream << ">\n";

	// matrix info
	osg::Matrix mat = world->getLocalToGlobalMatrix();
	sstream << "<TransformationMatrix ";
	sstream << "type=\"localToGlobal\" ";
	sstream << ">\n";
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			sstream << "<matrixValue ";
			sstream << "index=\"" << i << j << "\" ";
			sstream << "value=\"" << mat(i, j) << "\" ";
			sstream << "/>\n";
		}
	}
	sstream << "</TransformationMatrix>\n";

	// objects info
	std::map<int, CaptureObject*> objects = world->getObjects();
	for (objects_iterator oitr = objects.begin(); oitr != objects.end(); oitr++)
	{
		streamObject(oitr->second, sstream);
	}

	sstream << "</CaptureWorld>\n";
}
