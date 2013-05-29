
#include "stdafx.h"

#include <osg/Geode>
#include <osg/ShapeDrawable>
#include <osg/Node>

#include "LabeledMarker.h"


LabeledMarker::LabeledMarker() 
	: Marker()
{
	marker = NULL;
	//geo = NULL;
	node = NULL;
	toggled = false;
}

LabeledMarker::LabeledMarker(int id, float x, float y, float z, float size)
	: Marker(id, x, y, z, size)
{
	marker = NULL;
	//geo = NULL;
	node = NULL;
	toggled = false;
}

void LabeledMarker::setPosition(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
		
	if (node)
	{
		node->setMatrix(osg::Matrix::translate(x, y, z));
	}
}

void LabeledMarker::setSize(float size)
{
	this->size = size;

	if (marker)
	{
		marker->setRadius(size/2);
	}
}

void LabeledMarker::toggleMarkerColour()
{
	if (!node)
		return;
	
	// TODO
	osg::ShapeDrawable* draw = dynamic_cast<osg::ShapeDrawable*>(node->getChild(0)->asGeode()->getDrawable(0));

	if (toggled)
		draw->setColor(osg::Vec4(0.0f, 0.0f, 1.0f, 1.0f)); // blue
	else
		draw->setColor(osg::Vec4(0.0f, 1.0f, 0.0f, 1.0f)); // green
	
	toggled = !toggled;
}

osg::Node* LabeledMarker::getAsNode()
{
	if (!node)
	{
		node = new osg::MatrixTransform(osg::Matrix::translate(x, y, z));
		marker = new osg::Sphere(osg::Vec3(x, y, z), size);
		osg::ref_ptr<osg::ShapeDrawable> draw = new osg::ShapeDrawable();

		geo = new osg::Geode();
		draw->setShape(marker.get());
		draw->setColor(osg::Vec4(0.0f, 0.0f, 1.0f, 1.0f)); // blue by default
		geo->addDrawable(draw.get());
		node->addChild(geo.get());
	}

	return node;
}



