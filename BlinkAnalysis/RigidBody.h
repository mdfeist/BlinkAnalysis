/**
 * RigidBody.h
 * Created By: Michael Feist
 */

#pragma once
#include <string>
#include <osg/AutoTransform>

#include "NatNetTypes.h"

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

	int nMarkers;                           // Number of markers associated with this rigid body
	MarkerData* Markers;                    // Array of marker data ( [nMarkers][3] )
    int* MarkerIDs;                         // Array of marker IDs
    float* MarkerSizes;                     // Array of marker sizes
    float MeanError;                        // Mean measure-to-solve deviation

public:
	RigidBody(void);
	~RigidBody(void);

	// Getter/Setters for the ID of the Rigid Body.
	void setID(int id) { this->id = id; }
	int getID() { return this->id; }

	// Getter/Setters for the name of the Rigid Body.
	void setName(char* name) { strncpy_s(this->name, name, strlen(name)); }
	char* getName() { return this->name; }

	// Set the auto transform of the Rigid Body.
	void setTransform(osg::AutoTransform* transform) { this->transform = transform; }
	osg::Vec3 getPosition() { return this->position; }
	osg::Quat getRotation() { return this->rotation; }
	// Update the transformation of the Rigid Body
	void addFrame(osg::Vec3 position, osg::Vec4 rotation);
};

