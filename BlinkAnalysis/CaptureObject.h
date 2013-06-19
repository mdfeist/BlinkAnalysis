#ifndef CAPTUREOBJECT_H
#define CAPTUREOBJECT_H

#include <vector>
#include <string>
#include <osg/PrimitiveSet>
#include <osg/AutoTransform>
#include <osg/Shape>

#include "CaptureObjectUtil.h"


enum ObjectType {
	CUSTOM,
	BOX,
	CYLINDER,
	PLANE
};


typedef std::vector<osg::ref_ptr<osg::DrawElementsUInt>>::iterator faces_iterator;

///////////////////////////

// TODO: eventually support texture?
class CaptureObject
{
protected:
	// for tracking object with a rigid body
	int rigidBody;	// -1 if static object
	// identifier for this object (generated)
	int id;
	std::string name;

	osg::ref_ptr<osg::Node> node;
	osg::ref_ptr<osg::AutoTransform> rigidNode;
	bool render;
	ObjectType type;

public:

	CaptureObject()
	{
		id = -1;
		rigidBody = -1;
		render = true;
		type = CUSTOM;
	}

	~CaptureObject() { 
	}

	void setID(int id) { this->id = id; }
	int getID() { return id; }

	void setType(ObjectType t) { type = t; }
	ObjectType getType() { return type; }
	
	void setRigidBody(int rid, bool offset);
	int getRigidBody() { return rigidBody; }

	void setName(std::string name) { this->name = name; }
	std::string getName() { return name; }

	bool renderObject() { return render; }
	osg::Node* setRender(bool ren); // returns geode so world can remove it from node

	// virtual functions
	// returns a Geode representing this object
	virtual osg::Node* getAsNode() = 0;
	virtual int getNumVertices() = 0;
	virtual int getNumFaces() = 0;

};


///////////////////////////

class CaptureObjectCustom : public CaptureObject
{
private:
	osg::ref_ptr<osg::Vec3Array> vertices;
	std::vector<osg::ref_ptr<osg::DrawElementsUInt>> faces;

public:

	int getNumVertices() { return vertices->size(); }
	void setVertices(osg::Vec3Array* vertices) {
		this->vertices = vertices; 
	}
	
	int getNumFaces() { return faces.size(); }
	void addFace(osg::DrawElementsUInt* face) {
		faces.push_back(face); 
	}
	void removeFaces() {
		faces.clear(); 
	}

	osg::Node* getAsNode();
};


///////////////////////////

class CaptureObjectPlane : public CaptureObject
{
private: 
	osg::ref_ptr<osg::Vec3Array> vertices;
	osg::ref_ptr<osg::DrawElementsUInt> face;

public:
	CaptureObjectPlane()
		: CaptureObject()
	{
		type = PLANE;
		vertices = NULL;
		face = NULL;
	}

	CaptureObjectPlane(osg::Vec3 corner, osg::Vec3 pt1, osg::Vec3 pt2);

	int getNumVertices() { return 4; }
	void setVertices(osg::Vec3 corner, osg::Vec3 pt1, osg::Vec3 pt2);

	int getNumFaces() { return 1; }

	osg::Node* getAsNode();

};


///////////////////////////

class CaptureObjectBox : public CaptureObject
{
private:
	osg::ref_ptr<osg::Box> box;

public:
	CaptureObjectBox()
		: CaptureObject()
	{
		type = BOX;
		box = NULL;
	}

	CaptureObjectBox(osg::Vec3 centre, osg::Vec3 halfLen, osg::Quat rot);

	int getNumVertices() { return 8; }
	int getNumFaces() { return 6; }
	osg::Node* getAsNode();

	void setCentre(osg::Vec3 centre);
	osg::Vec3 getCentre();

	void setHalfLengths(osg::Vec3 halfLen);
	osg::Vec3 getHalfLengths();

	void setRotation(osg::Quat rot);
	osg::Quat getRotation();
};

#endif
