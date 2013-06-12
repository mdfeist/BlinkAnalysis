#ifndef CAPTUREOBJECT_H
#define CAPTUREOBJECT_H

#include <vector>
#include <string>
#include <osg/PrimitiveSet>

#include "CaptureObjectUtil.h"


typedef std::vector<osg::ref_ptr<osg::DrawElementsUInt>>::iterator faces_iterator;

// TODO: eventually support texture?
// TODO: check for NULL
class CaptureObject
{
private:
	// for tracking object with a rigid body
	int rigidBody;	// -1 if static object
	// identifier for this object (generated)
	int id;
	std::string name;
	osg::ref_ptr<osg::Vec3Array> vertices;
	std::vector<osg::ref_ptr<osg::DrawElementsUInt>> faces;

public:

	CaptureObject()
	{
		id = -1;
		rigidBody = -1;
	}

	~CaptureObject() { faces.clear(); }

	void setID(int id) { this->id = id; }
	int getID() { return id; }
	
	void setVertices(osg::Vec3Array* vertices) { this->vertices = vertices; }
	int getNumVertices() { return vertices->size(); }

	void addFace(osg::DrawElementsUInt* face) { faces.push_back(face); }
	int getNumFaces() { return faces.size(); }
	void removeFaces() { faces.clear(); }

	void setRigidBody(int rid) { rigidBody = rid; }
	int getRigidBody() { return rigidBody; }

	void setName(std::string name) { this->name = name; }
	std::string getName() { return name; }

	// returns a Geode representing this object
	osg::Geode* getAsGeode();
};

#endif
