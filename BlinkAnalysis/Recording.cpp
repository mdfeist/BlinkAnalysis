#include "StdAfx.h"
#include "Recording.h"

#include "AppData.h"
#include "RecordingManager.h"

typedef std::map<int, RigidBody*>::iterator RigidBody_iterator;

Recording::Recording(void)
{
	this->readyForRecording = false;
	this->id = RecordingManager::getInstance()->getNewID();

	this->recording = AppData::getInstance()->getNewRecording();
}


Recording::~Recording(void)
{
	this->rigidBodies.clear();
}

bool Recording::loadRecording(pugi::xml_node recording) {
	// Clear previous frames
	frames.clear();

	// Get the name of the recording
	pugi::xml_attribute recording_name = recording.attribute("name");

	if (recording_name) {
		this->name = recording_name.value();
	}

	// Get Static Objects
	pugi::xml_node static_objects = recording.child("Static");

	for (pugi::xml_node rigidBody = static_objects.child("RigidBody"); rigidBody; rigidBody = static_objects.next_sibling("RigidBody")) {
		pugi::xml_attribute id = rigidBody.attribute("id");
		pugi::xml_attribute name = rigidBody.attribute("name");

		RigidBody* rb = new RigidBody();
		rb->setID(id.as_int());
		rb->setName((char*)name.value());

		// Add the Rigid Body
		this->rigidBodies.insert ( std::pair<int, RigidBody*>(id.as_int(), rb) );
	}

	return true;
}

void Recording::initializeRecording() {

	ClientHandler* client = AppData::getInstance()->getClient();

	if (client) {
		recording.set_name("Recording");

		pugi::xml_node static_objects = recording.child("Static");

		if (!static_objects) {
			static_objects = recording.append_child();
			static_objects.set_name("Static");
		}

		for (pugi::xml_node rigidBody = static_objects.child("RigidBody"); rigidBody; rigidBody = static_objects.next_sibling("RigidBody")) {
			static_objects.remove_child(rigidBody);
		}

		std::map<int, RigidBody*>* rigidBodies = client->getRigidBodyMap();

		for (RigidBody_iterator it = rigidBodies->begin(); it != rigidBodies->end(); ++it) {
			pugi::xml_node rigidBody = static_objects.append_child(); 
			rigidBody.set_name("RigidBody");
			rigidBody.append_attribute("id") = it->second->getID();
			rigidBody.append_attribute("name") = it->second->getName();
		}
	}

	this->readyForRecording = true;
}

void Recording:: addFrame() {
	if (!this->readyForRecording)
		initializeRecording();

	ClientHandler* client = AppData::getInstance()->getClient();

	if (client) {
		pugi::xml_node frame = recording.append_child();
		frame.set_name("Frame");

		std::map<int, RigidBody*>* rigidBodies = client->getRigidBodyMap();

		for (RigidBody_iterator it = rigidBodies->begin(); it != rigidBodies->end(); ++it) {
			pugi::xml_node rigidBody = frame.append_child(); 
			rigidBody.set_name("RigidBody");
			
			rigidBody.append_attribute("id") = it->second->getID();
			
			rigidBody.append_attribute("x") = it->second->getPosition().x();
			rigidBody.append_attribute("y") = it->second->getPosition().y();
			rigidBody.append_attribute("z") = it->second->getPosition().z();

			rigidBody.append_attribute("qx") = it->second->getRotation().x();
			rigidBody.append_attribute("qy") = it->second->getRotation().y();
			rigidBody.append_attribute("qz") = it->second->getRotation().z();
			rigidBody.append_attribute("qw") = it->second->getRotation().w();
		}
	}
}
