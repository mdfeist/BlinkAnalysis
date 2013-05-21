#ifndef CAPTUREWORLD_H
#define CAPTUREWORLD_H

#include <hash_map>
#include <osg/Node>
#include <osg/Matrix>
#include <osg/MatrixTransform>


#include "CaptureObject.h"
#include "CaptureObjectUtil.h"


class CaptureWorld 
{
private:

	osg::Matrix coordFrame;
	static int _lastObjectID;
	std::map<int, CaptureObject> objects;

public:

	CaptureWorld()
	{
		coordFrame.set(osg::Matrix::identity());
	}

	~CaptureWorld()
	{
	}

	CaptureWorld(osg::Matrix mat);
	
	const osg::Matrix getCoordinateFrame() 
	{ 
		return coordFrame; 
	}

	void setCoordinateFrame(osg::Matrix mat, bool deleteObjects, bool updateObjects);

	bool addObject(CaptureObject obj);
	
	bool removeObject(int id);

	void clearObjects();

	int getNumberObjects();

	osg::Node* getAsNode();

};



#endif
