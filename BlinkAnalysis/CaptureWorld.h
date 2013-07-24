#ifndef CAPTUREWORLD_H
#define CAPTUREWORLD_H

#include <map>
#include <osg/MatrixTransform>


#include "CaptureObject.h"
#include "CaptureObjectUtil.h"


typedef std::map<int, CaptureObject*>::iterator objects_iterator;

class CaptureWorld 
{
private:
	void initCaptureWorld();

	std::string name;
	int id;
	
	osg::Matrix* _localToGlobal;
	osg::ref_ptr<osg::MatrixTransform> node;
	bool render;
	bool renderMat;
	
	// increments for each new object added
	int _lastObjectID;
	// map of IDs to objects in this world
	std::map<int, CaptureObject*> _objects;
	
public:
	static int _lastWorldID;

	CaptureWorld();
	CaptureWorld(std::string name);
	CaptureWorld(std::string name, osg::Matrix* locToGlob);

	~CaptureWorld()
	{
		delete _localToGlobal;
		clearObjects();
	}
	
	std::string getName() { return name; }
	void setName(std::string name);
	int getID() { return id; }

	// Matrix
	const osg::Matrix getLocalToGlobalMatrix();
	const osg::Matrix getGlobalToLocalMatrix();
	void setCoordinateFrame(osg::Matrix* locToGlob, bool deleteObjects=false);

	// Rendering
	void setRenderMatrix(bool ren);
	bool renderMatrix() { return renderMat; }
	bool renderWorld() { return render; }
	void setRender(bool ren);
	bool toggleRender();
	osg::MatrixTransform* getAsGroup();
	bool hasNode(osg::MatrixTransform* node) { return this->node == node; }
	void updateObjectsNode();

	// Object Management
	int addObject(CaptureObject* obj);
	bool removeObject(int oid);
	void clearObjects();
	int getNumberObjects();
	std::map<int, CaptureObject*> getObjects() { return _objects; }
	CaptureObject* getObject(int oid);
	void setRenderObject(int oid, bool ren);
	bool toggleRenderObject(int oid);
	bool setObjectRigidBody(int oid, int rid, bool offset);

	// Object Creation
	CaptureObject* addPlane(osg::Vec3 corner, osg::Vec3 pt1, osg::Vec3 pt2, std::string name);
	CaptureObject* addPlaneRigid(int rigidID, bool attachRigid, std::string name);

	CaptureObject* addBox(osg::Vec3 baseCentre, osg::Vec3 dimensions, std::string name);
	CaptureObject* addBoxRigid(int rigidID, osg::Vec3 dimensions, bool attachRigid, CentreType ct, std::string name);

	CaptureObject* addCylinder(osg::Vec3 baseCentre, float radius, float height, std::string name);
	CaptureObject* addCylinderRigid(int rigidID, float radius, float height, bool attachRigid, CentreType ct, std::string name);

};



#endif
