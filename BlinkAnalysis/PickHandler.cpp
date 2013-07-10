#include "stdafx.h"

#include <osg/Texture2D>
#include <osgDB/ReadFile>

#include "PickHandler.h"
#include "MainFormController.h"
#include "AppData.h"

bool PickHandler::handle(const osgGA::GUIEventAdapter& ea,osgGA::GUIActionAdapter& aa)
{
	if ( ea.getEventType() == osgGA::GUIEventAdapter::DOUBLECLICK && 
		ea.getButtonMask() == osgGA::GUIEventAdapter::LEFT_MOUSE_BUTTON ) 
	{
		osgViewer::View* view = dynamic_cast<osgViewer::View*>(&aa);
		reset();
        if (view) pick(view,ea);
		return true;
	}
	return false;
}

osg::Node* PickHandler::getOrCreateHUD()
{
	if (hudCamera.valid())
		return hudCamera;

    hudCamera = new osg::Camera;
	hudCamera->setReferenceFrame(osg::Transform::ABSOLUTE_RF);
	hudCamera->setProjectionMatrixAsOrtho2D(0,winWidth,0,winHeight);
    hudCamera->setViewMatrix(osg::Matrix::identity());
    hudCamera->setRenderOrder(osg::Camera::POST_RENDER);
    hudCamera->setClearMask(GL_DEPTH_BUFFER_BIT);
    
    // turn lighting off for the text and disable depth test to ensure it's always on top.
	osg::Vec3 position(3.0f,20.0f,0.0f);
	osg::Vec4 colour(1.0f,1.0f,1.0f,1.0f);	// white
   
    {
        osg::Geode* geode = new osg::Geode();
        osg::StateSet* stateset = geode->getOrCreateStateSet();
        stateset->setMode(GL_LIGHTING,osg::StateAttribute::OFF);
        stateset->setMode(GL_DEPTH_TEST,osg::StateAttribute::OFF);
        geode->addDrawable( _updateText );
        hudCamera->addChild(geode);
        
		// draw box around text
		_updateText->setDrawMode(osgText::Text::TEXT | osgText::Text::BOUNDINGBOX);
		_updateText->setBoundingBoxColor(colour);
		_updateText->setBoundingBoxMargin(2);
        _updateText->setCharacterSize(20.0f);
		// internally scales text to have consistent size
		_updateText->setCharacterSizeMode(osgText::Text::SCREEN_COORDS);
        _updateText->setColor(colour);
        _updateText->setText("");
		_updateText->setFont("fonts/arial.ttf");
        _updateText->setPosition(position);
        _updateText->setDataVariance(osg::Object::DYNAMIC);
    }    
    
    return hudCamera;

}


////////////////////////////

void PickObjectHandler::pick(osgViewer::View* view, const osgGA::GUIEventAdapter& ea)
{
	osgUtil::LineSegmentIntersector::Intersections intersections;

	float x = ea.getX();
	float y = ea.getY();
	if (view->computeIntersections(x,y,intersections))
	{
		for (osgUtil::LineSegmentIntersector::Intersections::iterator hitr = intersections.begin();
				hitr != intersections.end(); hitr++)
		{
			if (!hitr->nodePath.empty())
			{
				osg::Geode* geo = hitr->nodePath.back()->asGeode();
				std::string name = geo->getName();
				// geode containing captured object has the following name format
				// OBJ wid,oid
				if (!name.substr(0, 3).compare("OBJ"))
				{
					geo->getOrCreateStateSet()->setMode(GL_LIGHTING, osg::StateAttribute::OFF);
					pickedGeode = geo;

					std::istringstream oss(name.substr(4, name.length()-4));
					std::string num;
					getline(oss, num, ',');
					int wid = atoi(num.c_str());
					getline(oss, num, ',');
					int oid = atoi(num.c_str());

					std::stringstream sstream;
					sstream << "Object ID ";
					sstream << oid;
					sstream << "\nWorld ID ";
					sstream << wid;
					setLabel(sstream.str());
					break;
				}
			}
		}
	}
}

void PickObjectHandler::reset()
{
	if (pickedGeode.valid())
	{
		pickedGeode->getOrCreateStateSet()->setMode(GL_LIGHTING, osg::StateAttribute::ON);
		pickedGeode = NULL;
		setLabel("");
	}
}

////////////////////////////


void PickMarkerHandler::pick(osgViewer::View* view, const osgGA::GUIEventAdapter& ea)
{
	// since points have no area to pick, must use bounding box intersection
	osgUtil::PolytopeIntersector::Intersections intersections;

	float x = ea.getX();
	float y = ea.getY();
	float range = 3;
	osg::ref_ptr<osgUtil::PolytopeIntersector> polyIntersect = new
			osgUtil::PolytopeIntersector(osgUtil::Intersector::WINDOW, x-range , y-range, x+range, y+range);
	polyIntersect->setDimensionMask(osgUtil::PolytopeIntersector::DimZero);    // only pick points

    osgUtil::IntersectionVisitor iv( polyIntersect );
    view->getCamera()->accept( iv );  
	if (polyIntersect->containsIntersections())
	{
		intersections = polyIntersect->getIntersections();
		for (osgUtil::PolytopeIntersector::Intersections::iterator hitr = intersections.begin();
				hitr != intersections.end(); hitr++)
		{
			if (hitr->drawable.valid())
			{
				osg::Geometry* geom = hitr->drawable->asGeometry();
				std::string name = geom->getName();
				// drawable containing labeled marker has the following name format
				// LM #
				if (geom && !name.substr(0, 2).compare("LM"))
				{
					pickedMarker = atoi(name.substr(3, name.length()-3).c_str());
					ClientHandler* client = AppData::getInstance()->getClient();
					if (client && client->lock())
					{
						Marker* marker = client->getLabeledMarker(pickedMarker);
						if (marker)
						{
							marker->select();
							osg::Vec3 pos = marker->getPosition();
							std::ostringstream sstream;
							sstream.precision(5);
							sstream << "Marker ID ";
							sstream << marker->getID();
							sstream << "\nPosition (";
							sstream << pos.x();
							sstream << ", ";
							sstream << pos.y();
							sstream << ", ";
							sstream << pos.z();
							sstream << ")";
							setLabel(sstream.str());
						}
						client->unlock();
						break;
					}
				}
			}
		}
	}
}

void PickMarkerHandler::reset()
{
	if (pickedMarker >= 0)
	{
		ClientHandler* client = AppData::getInstance()->getClient();
		if (client)
		{
			Marker* marker = client->getLabeledMarker(pickedMarker);
			if (marker) marker->deselect();
			setLabel("");
		}
		pickedMarker = -1;
	}
}

