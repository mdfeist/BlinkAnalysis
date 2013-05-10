#include "StdAfx.h"
#include "AppViewer.h"

#include <Windows.h>
#include <process.h>

#include <stdio.h>
#include <vector>

#include <osg/AutoTransform>
#include <osg/Geode>
#include <osg/Geometry>
#include <osg/Point>
#include <osgDB/ReadFile>
#include <osgViewer/Viewer>
#include <osgViewer/GraphicsWindow>
#include <osgViewer/api/win32/GraphicsWindowWin32>
#include <osgGA/TrackballManipulator>

#include "Objects.h"
#include "AppData.h"

osgViewer::Viewer* viewer;
osg::Group* rootNode;
osg::ref_ptr<osg::DrawElementsUInt> draw; 
osg::ref_ptr<osg::Vec3Array> points;

void render(void *) {
	while( !viewer->done() )
	{
		osg::Geode* node = new osg::Geode(); 

		ClientHandler* client = AppData::getInstance()->getClient();
		if (client) {
			
			if (client->lock())
			{
				// Create Points
				osg::Geometry* geo = new osg::Geometry(); 
				draw = new osg::DrawElementsUInt(osg::PrimitiveSet::POINTS, 0); 

				points = new osg::Vec3Array(); 

				std::map<int, RigidBody*>* bodyMap = client->getRigidBodyMap();
				int markerIndex = 0;

				for (std::map<int, RigidBody*>::iterator it_body=bodyMap->begin(); it_body!=bodyMap->end(); ++it_body)
				{
					RigidBody* body = it_body->second;

					osg::Matrix matrix;
					matrix.setTrans(body->getPosition());
					matrix.setRotate(body->getRotation());

					std::vector<Marker>* markers = body->getMarkersVector();
				
					if (markers)
					{
						for (std::vector<Marker>::iterator it_marker=markers->begin(); it_marker!=markers->end(); ++it_marker)
						{
							Marker m = *it_marker;
							
							points->push_back( matrix * osg::Vec3( m.x, m.y, m.z ) ); 
							markerIndex++;
						}
					}
				}

				geo->setVertexArray( points ); 
				geo->addPrimitiveSet( new osg::DrawArrays(osg::PrimitiveSet::POINTS, 0, points->size() ) ); 

				node->addDrawable( geo );
	
				osg::Vec4Array* colors = new osg::Vec4Array(); 
				colors->push_back(osg::Vec4(1.0f, 0.0f, 0.0f, 1.0f) ); 

				geo->setColorArray(colors); 
				geo->setColorBinding(osg::Geometry::BIND_OVERALL); 

				osg::ref_ptr<osg::StateSet> nodeState = node->getOrCreateStateSet();
				nodeState->setMode(GL_LIGHTING, osg::StateAttribute::OFF);
				nodeState->setAttribute( new osg::Point( 7.5f ), osg::StateAttribute::ON );

				rootNode->addChild( node );
				//142.244.154.254
				// End Create Points

				client->unlock();
			}
		}
		
		viewer->frame();

		rootNode->removeChild( node );
	}
}

void AppViewer::initAppViewer(HWND hwnd)
{
	if (!viewer)
		viewer = new osgViewer::Viewer();

	if (!rootNode)
		rootNode = new osg::Group();

	osg::ref_ptr<osg::GraphicsContext::Traits> traits = new osg::GraphicsContext::Traits();
	traits->inheritedWindowData = new osgViewer::GraphicsWindowWin32::WindowData( hwnd );
	traits->setInheritedWindowPixelFormat = true;
	traits->doubleBuffer = true;
	traits->windowDecoration = false;
	traits->sharedContext = NULL;
	traits->supportsResize = false;

	RECT rect;
	::GetWindowRect( hwnd, &rect );
	traits->x = 0;
	traits->y = 0;
	traits->width = rect.right - rect.left;
	traits->height = rect.bottom - rect.top;

	osg::ref_ptr<osg::GraphicsContext> gc = osg::GraphicsContext::createGraphicsContext( traits.get() );
	viewer->getCamera()->setGraphicsContext( gc.get() );
	viewer->getCamera()->setViewport( new osg::Viewport( 0, 0, traits->width, traits->height ) );
	viewer->getCamera()->setProjectionMatrixAsPerspective(30.0f, static_cast<double>(traits->width)/static_cast<double>(traits->height), 1.0f, 10000.0f);

	/*
	osg::AutoTransform* modelTransform = new osg::AutoTransform();
	osg::Node *model = osgDB::readNodeFile("cow.osg");
	modelTransform->addChild(model);
	modelTransform->setPosition(osg::Vec3(0, 0, 3.2f));
	rootNode->addChild(modelTransform);
	*/

	osg::Geode* planeNode = Objects::createPlane();
	osg::ref_ptr<osg::StateSet> planeNodeState = planeNode->getOrCreateStateSet();
	planeNodeState->setMode(GL_LIGHTING, osg::StateAttribute::OFF);
	rootNode->addChild(planeNode);

	viewer->setSceneData(rootNode);

	viewer->getCamera()->setClearColor(osg::Vec4(0.2f,0.2f,0.2f,0.0f));

	viewer->setCameraManipulator( new osgGA::TrackballManipulator );
	viewer->getCameraManipulator()->setHomePosition(
		osg::Vec3(25.f, -25.f, 15.f),
		osg::Vec3(0.f, 0.f, 0.f),
		osg::Vec3(0.f, 0.f, 1.f));

	viewer->home();

	viewer->realize();

	_beginthread( render, 0, NULL );
}