#ifndef PICKHANDLER_H
#define PICKHANDLER_H

#include <osg/ImageSequence>
#include <osgGA/GUIEventHandler>
#include <osgViewer/Viewer>
#include <osgText/Text>

// class to handle events with a pick
// largely based on the osgpick example here
// http://trac.openscenegraph.org/projects/osg/browser/OpenSceneGraph/trunk/examples/osgpick/osgpick.cpp
class PickHandler : public osgGA::GUIEventHandler {
public: 

    PickHandler(osgText::Text* updateText) :
	_updateText(updateText) { }
        
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
	osg::Node* createHUD(osg::GraphicsContext::Traits* traits);

    virtual void pick(osgViewer::View* view, const osgGA::GUIEventAdapter& ea) = 0;
	virtual void reset() = 0;

protected:
	osg::ref_ptr<osgText::Text>  _updateText;
};

class PickObjectHandler : public PickHandler {
public:
	PickObjectHandler(osgText::Text* updateText) :
		PickHandler(updateText) {
		pickedGeode = NULL;
	}

	void pick(osgViewer::View* view, const osgGA::GUIEventAdapter& ea);
	void reset();

private:
	osg::ref_ptr<osg::Geode> pickedGeode;
};

class PickMarkerHandler : public PickHandler {
public:

	PickMarkerHandler(osgText::Text* updateText) :
		PickHandler(updateText) {
		pickedMarker = -1;
	}

	void pick(osgViewer::View* view, const osgGA::GUIEventAdapter& ea);
	void reset();

private:
	int pickedMarker;
};



#endif