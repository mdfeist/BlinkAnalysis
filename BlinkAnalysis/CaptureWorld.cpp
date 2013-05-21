

#include "StdAfx.h"
#include "CaptureWorld.h"



CaptureWorld::CaptureWorld(osg::Matrix* mat)
{
	coordFrame = mat;

}

void CaptureWorld::setCoordinateFrame(osg::Matrix* mat, bool deleteObjects, bool updateObjects)
{
	delete coordFrame;
	coordFrame = mat;

	if (deleteObjects)
	{
		objects.clear();
		return;
	}
	if (updateObjects)
	{
		//TODO
	}
}

//TODO
bool CaptureWorld::addObject(CaptureObject obj)
{
	return true;
}
	
bool CaptureWorld::removeObject(int id)
{
	return (objects.erase(id) ? true : false);
}

void CaptureWorld::clearObjects()
{
	objects.clear();
}

int CaptureWorld::getNumberObjects()
{
	return objects.size();
}

osg::Node* CaptureWorld::getAsNode()
{
	
	osg::ref_ptr<osg::MatrixTransform> node = new osg::MatrixTransform();
	node->setMatrix(*coordFrame);

	std::map<int, CaptureObject>::iterator iter;
	for (iter = objects.begin(); iter != objects.end(); ++iter)
	{
		// TODO 
	}

	return node.release();
}



