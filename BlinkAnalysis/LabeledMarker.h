#ifndef LABELEDMARKER_H
#define LABELEDMARKER_H

#include <osg/MatrixTransform>
//#include <osg/ShapeDrawable> // TODO problem with including this for some reason
//#include <osg/PrimitiveSet>
//#include <osg/Geode>
#include <osg/Shape>

#include "Marker.h"

class LabeledMarker : public Marker
{
private:
	osg::ref_ptr<osg::Sphere> marker;
	//osg::ref_ptr<osg::ShapeDrawable> draw;
	//osg::ref_ptr<osg::Geode> geo;
	osg::ref_ptr<osg::MatrixTransform> node;
	bool toggled;

public:
	
	LabeledMarker();

	LabeledMarker(int id, float x, float y, float z, float size = 0);

	void setPosition(float x, float y, float z);

	void setSize(float size);

	void toggleMarkerColour();
	
	osg::Node* getAsNode();

};

#endif
