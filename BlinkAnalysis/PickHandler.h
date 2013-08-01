#ifndef PICKHANDLER_H
#define PICKHANDLER_H

#include <osg/ImageSequence>
#include <osgGA/GUIEventHandler>
#include <osgViewer/Viewer>
#include <osgText/Text>

/**
 * abstract class to handle events with a pick \n
 * largely based on the osgpick example here \n
 * http://trac.openscenegraph.org/projects/osg/browser/OpenSceneGraph/trunk/examples/osgpick/osgpick.cpp
 */
class PickHandler : public osgGA::GUIEventHandler {
public: 

    PickHandler(int width, int height) {
		winWidth = width;
		winHeight = height;
		_updateText = new osgText::Text();
	}
        
    ~PickHandler() {}
    
	void setLabel(const std::string& name)
    {
        if (_updateText.get()) _updateText->setText(name);
    }

	void setPosition(float x, float y)
	{
		if (_updateText.get()) _updateText->setPosition(osg::Vec3(x, y, 0));
	}

    bool handle(const osgGA::GUIEventAdapter& ea,osgGA::GUIActionAdapter& aa);
	// camera for projecting text onto viewer
	osg::Node* getOrCreateHUD();

	// handling clicked geodes
    virtual void pick(osgViewer::View* view, const osgGA::GUIEventAdapter& ea) = 0;
	// clear text associated with handler
	virtual void reset() = 0;

protected:
	int winWidth;
	int winHeight;
	osg::ref_ptr<osgText::Text>  _updateText;
	osg::ref_ptr<osg::Camera> hudCamera;
};

/**
 * For picking CaptureObjects in a scene
 */
class PickObjectHandler : public PickHandler {
public:
	PickObjectHandler(int width, int height) :
		PickHandler(width, height) {
		pickedGeode = NULL;
	}

	void pick(osgViewer::View* view, const osgGA::GUIEventAdapter& ea);
	void reset();

private:
	// geode currently selected
	osg::ref_ptr<osg::Geode> pickedGeode;
};

/**
 * For picking LabeledMarkers in a scene
 */
class PickMarkerHandler : public PickHandler {
public:

	PickMarkerHandler(int width, int height) :
		PickHandler(width, height) {
		pickedMarker = -1;
	}

	void pick(osgViewer::View* view, const osgGA::GUIEventAdapter& ea);
	void reset();

private:
	// ID of marker currently selected
	int pickedMarker;
};



#endif