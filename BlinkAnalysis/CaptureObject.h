#ifndef CAPTUREOBJECT_H
#define CAPTUREOBJECT_H

#include <vector>
#include <string>

#include "CaptureObjectUtil.h"

#define EPSILON 0.00001


class CaptureObject
{
private:
	// -1 if static object
	int rigidBody;

	int id;
	
	//bool triangleFace;

	std::string name;

	std::vector<osg::Vec3Array*> faces;


public:

	CaptureObject()
	{
		//triangleFace = true;
		id = -1;
		rigidBody = -1;
	}

	CaptureObject(int id);

	~CaptureObject()
	{
	}
	
	void addFace(osg::Vec3Array* face)
	{
		faces.push_back(face);
	}

	int getNumFaces()
	{
		return faces.size();
	}

	void removeFaces()
	{
		faces.clear();
	}

	void setRigidBody(int rid)
	{
		id = rid;
	}

	int getRigidBody()
	{
		return id;
	}

	void setName(std::string name)
	{
		this->name = name;
	}

	std::string getName()
	{
		return name;
	}




};

#endif
