#ifndef CAPTUREWORLD_H
#define CAPTUREWORLD_H

#include <hash_map>
#include <osg/MatrixTransform>


#include "CaptureObject.h"
#include "CaptureObjectUtil.h"


typedef std::map<int, CaptureObject*>::iterator objects_iterator;

class CaptureWorld 
{
private:
	void initCaptureWorld();
	static int _lastWorldID;

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
	int addObject(CaptureObject* obj);
	
public:
	CaptureWorld();
	CaptureWorld(std::string name);
	CaptureWorld(std::string name, osg::Matrix* locToGlob);

	~CaptureWorld()
	{
		delete _localToGlobal;
		clearObjects();
	}

	const osg::Matrix getLocalToGlobalMatrix();
	const osg::Matrix getGlobalToLocalMatrix();

	std::string getName() { return name; }
	void setName(std::string name);
	int getID() { return id; }
	bool renderWorld() { return render; }
	void setRenderMatrix(bool ren);
	bool renderMatrix() { return renderMat; }

	void setRender(bool ren);
	bool toggleRender();

	void setRenderObject(int oid, bool ren);
	bool toggleRenderObject(int oid);

	void setCoordinateFrame(osg::Matrix* locToGlob, bool deleteObjects=false, bool updateObjects=false);

	CaptureObject* addPlane(osg::Vec3 corner, osg::Vec3 pt1, osg::Vec3 pt2, std::string name);
	CaptureObject* addBox(osg::Vec3 baseCentre, osg::Vec3 dimensions, std::string name);

	CaptureObject* getObject(int oid);

	bool removeObject(int oid);

	void clearObjects();

	std::map<int, CaptureObject*> getObjects() { return _objects; }

	int getNumberObjects();

	osg::MatrixTransform* getAsGroup();

	bool hasNode(osg::MatrixTransform* node) { return this->node == node; }

	void updateObjectsNode();
};



#endif
