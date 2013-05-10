/**
 * RigidBody.h
 * Created By: Michael Feist
 */

#pragma once
#include <string>
#include <vector>
#include <osg/AutoTransform>

#include "NatNetTypes.h"

class Marker {
public:
	int id;
	float x, y, z;
	float size;

	Marker() {
		this->id = 0;
		this->x = 0; 
		this->y = 0; 
		this->z = 0; 
		this->size = 0;}

	Marker(int id, float x, float y, float z, float size = 0) {
		this->id = id;
		this->x = x;
		this->y = y;
		this->z = z;
		this->size = size;
	}
};

/*
 * The RigidBody class handles transformation data
 * of a single rigid body.
 */
class RigidBody
{
private:
	int id;									// RigidBody identifier
	char name[MAX_NAMELENGTH];				// RigidBody name

	osg::Vec3 position;
	osg::Quat rotation;

	osg::AutoTransform *transform;

	std::vector<Marker> markers; 

    float MeanError;                        // Mean measure-to-solve deviation

public:
	RigidBody(void);
	~RigidBody(void);

	// Markers
	void clearMarkers() { this->markers.clear(); }
	void addMarker(Marker marker) {
		this->markers.push_back(marker);
	}

	std::vector<Marker>* getMarkersVector() { return &this->markers; }

	// Getter/Setters for the ID of the Rigid Body.
	void setID(int id) { this->id = id; }
	int getID() { return this->id; }

	// Getter/Setters for the name of the Rigid Body.
	void setName(char* name) { strncpy_s(this->name, name, strlen(name)); }
	char* getName() { return this->name; }

	// Set the auto transform of the Rigid Body.
	void setTransform(osg::AutoTransform* transform) { this->transform = transform; }
	osg::AutoTransform* getTransform() { return this->transform; }
	osg::Vec3 getPosition() { return this->position; }
	osg::Quat getRotation() { return this->rotation; }
	// Update the transformation of the Rigid Body
	void addFrame(osg::Vec3 position, osg::Vec4 rotation);
};

