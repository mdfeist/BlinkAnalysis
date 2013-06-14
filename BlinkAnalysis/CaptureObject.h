#ifndef CAPTUREOBJECT_H
#define CAPTUREOBJECT_H

#include <vector>
#include <string>
#include <osg/PrimitiveSet>
#include <osg/Node>

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
	osg::ref_ptr<osg::Node> node;
	bool render;

public:

	CaptureObject()
	{
		id = -1;
		rigidBody = -1;
		render = true;
	}

	~CaptureObject() { 
		faces.clear(); 
		node = NULL;
	}

	void setID(int id) { this->id = id; }
	int getID() { return id; }
	
	int getNumVertices();
	void setVertices(osg::Vec3Array* vertices);

	int getNumFaces() { return faces.size(); }
	void addFace(osg::DrawElementsUInt* face);
	void removeFaces();

	void setRigidBody(int rid) { rigidBody = rid; }
	int getRigidBody() { return rigidBody; }

	void setName(std::string name) { this->name = name; }
	std::string getName() { return name; }

	// returns a Geode representing this object
	osg::Geode* getAsGeode();
	bool renderObject() { return render; }
	osg::Node* setRender(bool ren); // returns geode so world can remove it from node
};

#endif
