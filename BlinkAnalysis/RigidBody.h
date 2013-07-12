/**
 * RigidBody.h
 * Created By: Michael Feist
 */

#pragma once
#include <string>
#include <vector>
#include <osg/AutoTransform>

#include "NatNetTypes.h"
#include "Marker.h"

/*
 * The RigidBody class handles transformation data
 * of a single rigid body.
 */
class RigidBody
{
private:
	int id;									// RigidBody identifier
	char name[MAX_NAMELENGTH];				// RigidBody name

	osg::Vec3 position;						// RigidBody Position
	osg::Quat rotation;;					// RigidBody Rotation

	osg::ref_ptr<osg::AutoTransform> transform;			// RigidBody Matrix Transformation
	int worldID;											// world to which transformation belongs

	std::vector<Marker> markers;			// Vector of all the markers
    float MeanError;                        // Mean measure-to-solve deviation

public:
	RigidBody(void);
	~RigidBody(void);

	// Markers
	// Delete all markers
	void clearMarkers() { this->markers.clear(); }
	// Add a marker
	void addMarker(Marker marker) { this->markers.push_back(marker); }
	// Get all the markers in a vector
	std::vector<Marker>* getMarkersVector() { return &this->markers; }

	// Getter/Setters for the ID of the Rigid Body.
	void setID(int id) { this->id = id; }
	int getID() { return this->id; }

	// Getter/Setters for the name of the Rigid Body.
	void setName(char* name) { strncpy_s(this->name, name, strlen(name)); }
	char* getName() { return this->name; }

	// Getter/Setter for ID of world it is attached to
	void setWorldID(int wid) { this->worldID = wid; }
	int getWorldID() { return this->worldID; }

	// Getter/Setters for the auto transform of the Rigid Body.
	void setTransform(osg::AutoTransform* transform) { this->transform = transform; }
	osg::AutoTransform* getTransform() { 
		this->transform->setName("RigidBody Transform");
		return this->transform; 
	}
	osg::Vec3 getPosition() { return this->position; }
	osg::Quat getRotation() { return this->rotation; }
	// Update the transformation of the Rigid Body
	void addFrame(osg::Vec3 position, osg::Vec4 rotation);
};

