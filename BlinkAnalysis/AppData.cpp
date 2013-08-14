/**
 * AppData.cpp
 * Created By: Michael Feist
 */

#include "StdAfx.h"
#include "AppData.h"

#include <stdlib.h>
#include <stdio.h>
#include <sstream>
#include "MainFormController.h"
#include "StreamingManager.h"

AppData* AppData::m_pInstance = NULL; 


AppData::AppData(void)
{
	this->needSaveFlag = false;

	strncpy_s(this->fileName, "Untitled.xml", strlen(this->filePath));
	strncpy_s(this->filePath, "", strlen(this->filePath));
	strncpy_s(this->error, "", strlen(this->error));
}


AppData::~AppData(void)
{
}

bool AppData::openFile(char* filePath) {
	pugi::xml_parse_result result = doc.load_file(filePath);

	if (result.status) {
		sprintf_s(this->error, "Load Project Result: %s.", result.description());
		return false;
	} else {
		if (!this->client) {
			sprintf_s(this->error, "Unable to load project because the client handler was not created.");
			return false;
		}

		// Get Project
		pugi::xml_node project = doc.child("Project");

		if (project) {
			// Get OptiTrack Information
			pugi::xml_node OptiTrack = project.child("OptiTrack");

			if (OptiTrack) {
				pugi::xml_attribute localIP = OptiTrack.attribute("LocalIpAddress");
				pugi::xml_attribute serverIP = OptiTrack.attribute("ServerIpAddress");
				pugi::xml_attribute cmdPort = OptiTrack.attribute("CommandPort");
				pugi::xml_attribute dataPort = OptiTrack.attribute("DataPort");
				pugi::xml_attribute cType = OptiTrack.attribute("ConnectionType");

				if (localIP) {
					this->client->setLocalIpAddress(localIP.value());
				}

				if (serverIP) {
					this->client->setOptiTrackServerIpAddress(serverIP.value());
				}

				if (cmdPort) {
					this->client->setOptiTrackServerCommandPort(cmdPort.as_int());
				}

				if (dataPort) {
					this->client->setOptiTrackServerDataPort(dataPort.as_int());
				}

				if (cType) {
					if (!strncmp(cType.value(), "Multicast", 128)) {
						this->client->setOptiTrackServerConnectionType(ConnectionType_Multicast);
					} else if (!strncmp(cType.value(), "Unicast", 128)) {
						this->client->setOptiTrackServerConnectionType(ConnectionType_Unicast);
					} else {
						this->client->setOptiTrackServerConnectionType(ConnectionType_Multicast);
					}
				}
			}

			// get static info
			pugi::xml_node Static = project.child("StaticData");
			if (Static)
			{
				WorldManager::getInstance()->clearWorlds();
				// find default world to load first
				for (pugi::xml_node witr = Static.child("CaptureWorld"); witr; witr = witr.next_sibling("CaptureWorld"))
				{
					if (!strcmp(witr.attribute("id").value(), "0"))
					{
						WorldManager::getInstance()->addWorld(loadWorld(witr));
						break;
					}
				}
				
				for (pugi::xml_node witr = Static.child("CaptureWorld"); witr; witr = witr.next_sibling("CaptureWorld"))
				{
					if (strcmp(witr.attribute("id").value(), "0"))
						WorldManager::getInstance()->addWorld(loadWorld(witr));
				}
			}

			// get output settings
			pugi::xml_node output = project.child("OutputSetting");
			if (output)
			{
				pugi::xml_attribute outputIP = output.attribute("IPAddress");
				pugi::xml_attribute outputPort = output.attribute("PortNumber");
				pugi::xml_attribute intersectMargin = output.attribute("IntersectionMargin");
				pugi::xml_attribute intersectDepth = output.attribute("IntersectionDepth");
				pugi::xml_attribute folderPath = output.attribute("SaveFolderPath");
				pugi::xml_attribute saveFolder = output.attribute("SaveFolder");

				BlinkAnalysis::StreamingManager* smanager = BlinkAnalysis::StreamingManager::getInstance();
				OutputManager* omanager = OutputManager::getInstance();

				if (outputIP)
					smanager->setIPAddress(outputIP.value());

				if (outputPort)
					smanager->setPortNumber(outputPort.as_int());

				if (intersectMargin)
					omanager->setIntersectionBuffer(intersectMargin.as_float());

				if (intersectDepth)
					omanager->setIntersectionLength(intersectDepth.as_float());

				if (folderPath)
				{
					smanager->setFolderPath(folderPath.value());
					if (saveFolder && !strcmp(saveFolder.value(), "true"))
						smanager->setSaveData(true);
				}
			}
		}

		MainFormController::getInstance()->setInfo();
	}

	strncpy_s(this->filePath, filePath, strlen(filePath));

	this->needSaveFlag = false;

	return true;
}

CaptureWorld* AppData::loadWorld(pugi::xml_node& worldNode)
{
	const char* name = worldNode.attribute("name").value();

	osg::Matrix* mat = new osg::Matrixd();
	pugi::xml_node matrix = worldNode.child("TransformationMatrix");
	int i, j;
	double val;
	for (pugi::xml_node matVal = matrix.first_child(); matVal; matVal = matVal.next_sibling())
	{
		i = atoi(matVal.attribute("row").value());
		j = atoi(matVal.attribute("col").value());
		val = atof(matVal.attribute("value").value());
		(*mat)(j, i) = val;
	}
	if (strcmp(matrix.attribute("type").value(), "localToGlobal"))
		*mat = osg::Matrix::inverse(*mat);

	CaptureWorld* world = new CaptureWorld(std::string(name), mat);

	for (pugi::xml_node object = worldNode.child("CaptureObject"); object; object = object.next_sibling("CaptureObject"))
	{
		world->addObject(loadObject(object));
	}

	return world;
}

CaptureObject* AppData::loadObject(pugi::xml_node& objectNode)
{
	const char* type = objectNode.attribute("type").value();
	CaptureObject* object = NULL;

	if (!strcmp(type, "plane"))
	{
		double x0, y0, z0;
		double x1, y1, z1;
		double x2, y2, z2;
		for (pugi::xml_node vert = objectNode.child("vertex"); vert; vert = vert.next_sibling("vertex"))
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
		osg::Vec3 cen, dim;
		osg::Quat rot;
		for (pugi::xml_node attr = objectNode.first_child(); attr; attr = attr.next_sibling())
		{
			if (!strcmp(attr.name(), "centre"))
			{
				cen = osg::Vec3( atof(attr.attribute("x").value()),
								 atof(attr.attribute("y").value()),
								 atof(attr.attribute("z").value()) );
			}
			else if (!strcmp(attr.name(), "dimension"))
			{
				dim = osg::Vec3( atof(attr.attribute("x").value()),
								 atof(attr.attribute("y").value()),
								 atof(attr.attribute("z").value()) );
				dim /= 2;
			}
			else if (!strcmp(attr.name(), "rotation"))
			{
				rot = osg::Quat( atof(attr.attribute("x").value()),
								 atof(attr.attribute("y").value()),
								 atof(attr.attribute("z").value()),
								 atof(attr.attribute("w").value()) );
			}
		}

		object = new CaptureObjectBox(cen, dim, rot);
	}
	else if (!strcmp(type, "cylinder"))
	{
		osg::Vec3 cen;
		float radius;
		float height;
		osg::Quat rot;
		for (pugi::xml_node attr = objectNode.first_child(); attr; attr = attr.next_sibling())
		{
			if (!strcmp(attr.name(), "centre"))
			{
				cen = osg::Vec3( atof(attr.attribute("x").value()),
								 atof(attr.attribute("y").value()),
								 atof(attr.attribute("z").value()) );
			}
			else if (!strcmp(attr.name(), "dimension"))
			{
				radius = atof(attr.attribute("radius").value());
				height = atof(attr.attribute("height").value());
			}
			else if (!strcmp(attr.name(), "rotation"))
			{
				rot = osg::Quat( atof(attr.attribute("x").value()),
								 atof(attr.attribute("y").value()),
								 atof(attr.attribute("z").value()),
								 atof(attr.attribute("w").value()) );
			}
		}

		object = new CaptureObjectCylinder(cen, radius, height, rot);
	}
	else
		return NULL;

	const char* name = objectNode.attribute("name").value();
	object->setName(name);

	return object;
}

const char* managedStringToChar(String^ str) {
	return (const char*) (Runtime::InteropServices::Marshal::StringToHGlobalAnsi(str)).ToPointer();
}

bool AppData::saveFile() {
	MainFormController::getInstance()->getInfo();

	// Get Project
	pugi::xml_node project = doc.child("Project");

	// If no Project create new Project node
	if (!project) {
		project = doc.append_child();
		project.set_name("Project");
	}

	char buf[128];

	// Save OptiTrack Information
	{
		pugi::xml_node OptiTrack = project.child("OptiTrack");

		if (!OptiTrack) {
			OptiTrack = project.append_child();
			OptiTrack.set_name("OptiTrack");
		}

		// Get Attributes
		pugi::xml_attribute localIP = OptiTrack.attribute("LocalIpAddress");
		pugi::xml_attribute serverIP = OptiTrack.attribute("ServerIpAddress");
		pugi::xml_attribute cmdPort = OptiTrack.attribute("CommandPort");
		pugi::xml_attribute dataPort = OptiTrack.attribute("DataPort");
		pugi::xml_attribute cType = OptiTrack.attribute("ConnectionType");

		// Create missing Attributes
		if (!localIP) {
			localIP = OptiTrack.append_attribute("LocalIpAddress");
		}

		if (!serverIP) {
			serverIP = OptiTrack.append_attribute("ServerIpAddress");
		}

		if (!cmdPort) {
			cmdPort = OptiTrack.append_attribute("CommandPort");
		}

		if (!dataPort) {
			dataPort = OptiTrack.append_attribute("DataPort");
		}

		if (!cType) {
			cType = OptiTrack.append_attribute("ConnectionType");
		}

		// Save Local IP Address
		this->client->getLocalIpAddress(buf);
		localIP.set_value(buf);

		// Save Server IP Address
		this->client->getOptiTrackServerIpAddress(buf);
		serverIP.set_value(buf);

		// Save Command Port
		cmdPort.set_value(this->client->getOptiTrackServerCommandPort());

		// Save Data Port
		dataPort.set_value(this->client->getOptiTrackServerDataPort());

		// Save Connection Type
		int iConnectionType = this->client->getOptiTrackServerConnectionType();
		if (iConnectionType == ConnectionType_Multicast)
			cType.set_value("Multicast");
		else if (iConnectionType == ConnectionType_Unicast)
			cType.set_value("Unicast");
		else
			cType.set_value("Multicast");
	}

	// Save Capture Object info
	{
		pugi::xml_node Static = project.child("StaticData");

		if (!Static) {
			Static = project.append_child();
			Static.set_name("StaticData");
		}
		else {
			while (Static.first_child()) Static.remove_child(Static.first_child());
		}

		std::map<int, CaptureWorld*> worlds = WorldManager::getInstance()->getWorlds();
		for (worlds_iterator witr = worlds.begin(); witr != worlds.end(); witr++)
		{
			saveWorld(witr->second, Static.append_child());
		}
	}

	{
		pugi::xml_node output = project.child("OutputSetting");

		if (!output) {
			output = project.append_child();
			output.set_name("OutputSetting");
		}
		
		// Get Attributes
		pugi::xml_attribute outputIP = output.attribute("IPAddress");
		pugi::xml_attribute outputPort = output.attribute("PortNumber");
		pugi::xml_attribute intersectMargin = output.attribute("IntersectionMargin");
		pugi::xml_attribute intersectDepth = output.attribute("IntersectionDepth");
		pugi::xml_attribute folderPath = output.attribute("SaveFolderPath");
		pugi::xml_attribute saveFolder = output.attribute("SaveFolder");

		if (!outputIP)
			outputIP = output.append_attribute("IPAddress");

		if (!outputPort)
			outputPort = output.append_attribute("PortNumber");

		if (!intersectMargin)
			intersectMargin = output.append_attribute("IntersectionMargin");

		if (!intersectDepth)
			intersectDepth = output.append_attribute("IntersectionDepth");

		if (!folderPath)
			folderPath = output.append_attribute("SaveFolderPath");

		if (!saveFolder)
			saveFolder = output.append_attribute("SaveFolder");

		BlinkAnalysis::StreamingManager* smanager = BlinkAnalysis::StreamingManager::getInstance();
		OutputManager* omanager = OutputManager::getInstance();

		outputIP.set_value(managedStringToChar(smanager->getIPAddress()));
		outputPort.set_value(smanager->getPortNumber());
		intersectMargin.set_value(omanager->getIntersectionBuffer());
		intersectDepth.set_value(omanager->getIntersectionLength());
		folderPath.set_value(smanager->getFolderPath().c_str());
		saveFolder.set_value( (smanager->getSaveData() ? "true" : "false") );
	}

	doc.save_file(this->filePath);

	this->needSaveFlag = false;
	MainFormController::getInstance()->updateFormTitle();

	return true;
}

void AppData::saveWorld(CaptureWorld* world, pugi::xml_node& node)
{
	char buf[128];

	node.set_name("CaptureWorld");
	_itoa_s(world->getID(), buf, 10);
	node.append_attribute("id").set_value(buf);
	node.append_attribute("name").set_value(world->getName().c_str());

	pugi::xml_node matrix = node.append_child("TransformationMatrix");
	matrix.append_attribute("type").set_value("localToGlobal");
	osg::Matrix mat = world->getLocalToGlobalMatrix();
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			pugi::xml_node matVal = matrix.append_child("matrixValue");
			_itoa_s(i, buf, 10);
			matVal.append_attribute("row").set_value(buf);
			_itoa_s(j, buf, 10);
			matVal.append_attribute("col").set_value(buf);
			matVal.append_attribute("value").set_value(CaptureObjectUtil::floatToString(mat(j, i))->c_str());
		}
	}

	// objects info
	std::map<int, CaptureObject*> objects = world->getObjects();
	for (objects_iterator oitr = objects.begin(); oitr != objects.end(); oitr++)
	{
		saveObject(oitr->second, node.append_child());
	}

}

void AppData::saveObject(CaptureObject* object, pugi::xml_node& node)
{
	char buf[128];
	ObjectType type = object->getType();

	node.set_name("CaptureObject");
	_itoa_s(object->getID(), buf, 10);
	node.append_attribute("id").set_value(buf);
	node.append_attribute("name").set_value(object->getName().c_str());
	node.append_attribute("type").set_value(CaptureObjectUtil::objectTypeToString(type));

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
				pugi::xml_node vert = node.append_child("vertex");
				_itoa_s(i, buf, 10);
				vert.append_attribute("id").set_value(buf);
				vert.append_attribute("x").set_value(CaptureObjectUtil::floatToString(itr->x())->c_str());
				vert.append_attribute("y").set_value(CaptureObjectUtil::floatToString(itr->y())->c_str());
				vert.append_attribute("z").set_value(CaptureObjectUtil::floatToString(itr->z())->c_str());
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
			pugi::xml_node cen = node.append_child("centre");
			cen.append_attribute("x").set_value(CaptureObjectUtil::floatToString(vec.x())->c_str());
			cen.append_attribute("y").set_value(CaptureObjectUtil::floatToString(vec.y())->c_str());
			cen.append_attribute("z").set_value(CaptureObjectUtil::floatToString(vec.z())->c_str());

			vec = box->getHalfLengths();
			pugi::xml_node dim = node.append_child("dimension");
			dim.append_attribute("x").set_value(CaptureObjectUtil::floatToString(vec.x()*2)->c_str());
			dim.append_attribute("y").set_value(CaptureObjectUtil::floatToString(vec.y()*2)->c_str());
			dim.append_attribute("z").set_value(CaptureObjectUtil::floatToString(vec.z()*2)->c_str());

			osg::Quat quat = box->getRotationBox();
			pugi::xml_node rot = node.append_child("rotation");
			rot.append_attribute("x").set_value(CaptureObjectUtil::floatToString(quat.x())->c_str());
			rot.append_attribute("y").set_value(CaptureObjectUtil::floatToString(quat.y())->c_str());
			rot.append_attribute("z").set_value(CaptureObjectUtil::floatToString(quat.z())->c_str());
			rot.append_attribute("w").set_value(CaptureObjectUtil::floatToString(quat.w())->c_str());
		}
	}
	else if (type == OBJ_CYLINDER)
	{
		CaptureObjectCylinder* cylinder = dynamic_cast<CaptureObjectCylinder*>(object);
		if (cylinder) 
		{
			osg::Vec3 vec = cylinder->getCentre();
			pugi::xml_node cen = node.append_child("centre");
			cen.append_attribute("x").set_value(CaptureObjectUtil::floatToString(vec.x())->c_str());
			cen.append_attribute("y").set_value(CaptureObjectUtil::floatToString(vec.y())->c_str());
			cen.append_attribute("z").set_value(CaptureObjectUtil::floatToString(vec.z())->c_str());

			pugi::xml_node dim = node.append_child("dimension");
			dim.append_attribute("radius").set_value(CaptureObjectUtil::floatToString(cylinder->getRadius())->c_str());
			dim.append_attribute("height").set_value(CaptureObjectUtil::floatToString(cylinder->getHeight())->c_str());

			osg::Quat quat = cylinder->getRotationCylinder();
			pugi::xml_node rot = node.append_child("rotation");
			rot.append_attribute("x").set_value(CaptureObjectUtil::floatToString(quat.x())->c_str());
			rot.append_attribute("y").set_value(CaptureObjectUtil::floatToString(quat.y())->c_str());
			rot.append_attribute("z").set_value(CaptureObjectUtil::floatToString(quat.z())->c_str());
			rot.append_attribute("w").set_value(CaptureObjectUtil::floatToString(quat.w())->c_str());
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
				pugi::xml_node vert = node.append_child("vertex");
				_itoa_s(i, buf, 10);
				vert.append_attribute("id").set_value(buf);
				vert.append_attribute("x").set_value(CaptureObjectUtil::floatToString(itr->x())->c_str());
				vert.append_attribute("y").set_value(CaptureObjectUtil::floatToString(itr->y())->c_str());
				vert.append_attribute("z").set_value(CaptureObjectUtil::floatToString(itr->z())->c_str());
				i++;
			}
		}
	}
}

std::string AppData::getRigidBodyStaticData()
{
	std::stringstream sstream;

	std::map<int, RigidBody*>* rigidBodies = client->getRigidBodyMap();

	for (RigidBody_iterator it = rigidBodies->begin(); it != rigidBodies->end(); ++it) {
		sstream << "<RigidBody ";
		sstream << "id=\"" << it->second->getID() << "\" ";
		sstream << "name=\"" << it->second->getName() << "\" ";
		sstream << "/>\n";
	}

	return sstream.str();
}


