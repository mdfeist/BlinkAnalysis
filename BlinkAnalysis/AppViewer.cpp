/**
 * AppViewer.cpp
 * Created By: Michael Feist
 */

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

bool running = false;
bool visible = false;

void AppViewer::stopAppViewer() { running = false; }
void AppViewer::setVisible(bool bVisible) { visible = bVisible; }

void render(void *) {
	// Started Rendering
	running = true;

	// Loop until done
	while( !viewer->done() )
	{
		// If not running stop render loop
		if (!running)
			viewer->setDone(running);

		// Check if view is visible
		if (visible) {
			// Add Geode to store all the marker points
			osg::Geode* node = new osg::Geode(); 

			// Get the current client
			ClientHandler* client = AppData::getInstance()->getClient();

			// Check if the client was created and is not NULL
			if (client) {
			
				// Lock Client so marker data isn't changed
				if (client->lock())
				{
					// Create Points
					// Create geo to store points
					osg::Geometry* geo = new osg::Geometry(); 

					// Create array to hold points
					osg::ref_ptr<osg::Vec3Array> points = new osg::Vec3Array(); 
					osg::Vec4Array* colors = new osg::Vec4Array(); 

					// Get the map of all the Rigid Bodies attached to the client
					std::map<int, RigidBody*>* bodyMap = client->getRigidBodyMap();

					// Set the current marker index to zero
					int markerIndex = 0;

					// Loop Through all the Rigid Bodies attached to the client
					for (std::map<int, RigidBody*>::iterator it_body=bodyMap->begin(); it_body!=bodyMap->end(); ++it_body)
					{
						// Get pointer to Rigid Body
						RigidBody* body = it_body->second;

						// Get the vector of all the Markers attached to the Rigid Body
						std::vector<Marker>* markers = body->getMarkersVector();
				
						// Check if the markers vector is created and not null
						if (markers)
						{
							// Loop through all the markers attached to the Rigid Body
							for (std::vector<Marker>::iterator it_marker=markers->begin(); it_marker!=markers->end(); ++it_marker)
							{
								// Get Pointer to marker
								Marker marker = *it_marker;
								
								// Get current position of marker
								osg::Vec3 pos = marker.getPosition();

								// Add marker to the points array
								points->push_back( pos );
								//points->push_back( pos / 100.f ); 

								// Add colors
								colors->push_back( marker.getColor() );

								// Update the current index
								markerIndex++;
							}
						}

						// Labeled Markers
						std::map<int, Marker*>* markerMap = client->getLabeledMarkerMap();
						for (labeledmarker_iterator it_marker = markerMap->begin(); it_marker != markerMap->end(); ++it_marker)
						{
							// Get Pointer to marker
							Marker* marker = it_marker->second;
							
							// Get current position of marker
							osg::Vec3 pos = marker->getPosition(); 

							// Add marker to the points array
							points->push_back( pos );

							// Add colors
							colors->push_back( marker->getColor() );
						}
					}

					// Unlock Client so marker data can be updated
					client->unlock();

					// Add the points array to the geometry
					geo->setVertexArray( points ); 

					// Render the points geometry as Points
					geo->addPrimitiveSet( new osg::DrawArrays(osg::PrimitiveSet::POINTS, 0, points->size() ) ); 

					// Set Color array to the geometry
					geo->setColorArray(colors); 
					geo->setColorBinding(osg::Geometry::BIND_OVERALL); 

					// Add the geometry to the node
					node->addDrawable( geo );

					// Set the size of the points and turn off lighting
					osg::ref_ptr<osg::StateSet> nodeState = node->getOrCreateStateSet();
					nodeState->setMode(GL_LIGHTING, osg::StateAttribute::OFF);
					nodeState->setMode(GL_BLEND, osg::StateAttribute::ON);
					nodeState->setMode(GL_POINT_SMOOTH, osg::StateAttribute::ON);
					nodeState->setAttribute( new osg::Point( 10.0f ) , osg::StateAttribute::ON );
					nodeState->setRenderingHint( osg::StateSet::TRANSPARENT_BIN );

					// Add Node containing all the points to the scene
					rootNode->addChild( node );
					// End Create Points
				}
			}
			
			// Render frame
			viewer->frame();

			// Remove points from the scene
			rootNode->removeChild( node );
		} else {
			// View not visible so Sleep for 1000 milliseconds
			Sleep(1000);
		}
	}

	// Terminate thread
    _endthread();
}

void AppViewer::initAppViewer(HWND hwnd)
{
	// If already running don't create new view
	if (running)
		return;

	// Create new viewer if one doesn't exist
	if (!viewer)
		viewer = new osgViewer::Viewer();

	// Create new root node if one doesn't exist
	if (!rootNode)
		rootNode = new osg::Group();

	// Set the traits for the rendering view
	osg::ref_ptr<osg::GraphicsContext::Traits> traits = new osg::GraphicsContext::Traits();
	traits->inheritedWindowData = new osgViewer::GraphicsWindowWin32::WindowData( hwnd );
	traits->setInheritedWindowPixelFormat = true;
	traits->doubleBuffer = true;
	traits->windowDecoration = false;
	traits->sharedContext = NULL;
	traits->supportsResize = false;

	// Set the size of the rendering view
	RECT rect;
	::GetWindowRect( hwnd, &rect );
	traits->x = 0;
	traits->y = 0;
	traits->width = rect.right - rect.left;
	traits->height = rect.bottom - rect.top;

	// Apply the traits to the viewer and update the perspective
	osg::ref_ptr<osg::GraphicsContext> gc = osg::GraphicsContext::createGraphicsContext( traits.get() );
	viewer->getCamera()->setGraphicsContext( gc.get() );
	viewer->getCamera()->setViewport( new osg::Viewport( 0, 0, traits->width, traits->height ) );
	viewer->getCamera()->setProjectionMatrixAsPerspective(30.0f, static_cast<double>(traits->width)/static_cast<double>(traits->height), 1.0f, 10000.0f);

	/*
	// Add a model to the scene for testing
	osg::AutoTransform* modelTransform = new osg::AutoTransform();
	osg::Node *model = osgDB::readNodeFile("cow.osg");
	modelTransform->addChild(model);
	modelTransform->setPosition(osg::Vec3(0, 0, 3.2f));
	rootNode->addChild(modelTransform);
	*/

	// TESTING for CaptureWorld
	rootNode->addChild(AppData::getInstance()->getWorld()->getAsNode());
	
	// Add the ground plane
	osg::Geode* planeNode = Objects::createPlane();
	Objects::applyTexture("Images/PlaneGrid.png", planeNode);
	osg::ref_ptr<osg::StateSet> planeNodeState = planeNode->getOrCreateStateSet();
	planeNodeState->setMode( GL_LIGHTING, osg::StateAttribute::OFF );
	planeNodeState->setMode( GL_BLEND, osg::StateAttribute::ON );
	planeNodeState->setRenderingHint( osg::StateSet::TRANSPARENT_BIN );
	rootNode->addChild(planeNode);

	rootNode->getOrCreateStateSet()->setMode( GL_ALPHA_TEST, osg::StateAttribute::ON ); 

	// Add the root node to the scene
	viewer->setSceneData(rootNode);

	// Set the background color
	viewer->getCamera()->setClearColor(osg::Vec4(0.2f,0.2f,0.2f,0.0f));

	// Allow users to manipulated the camera with their mouse
	// and keyboard.
	viewer->setCameraManipulator( new osgGA::TrackballManipulator );

	// Set the starting position of the camera
	viewer->getCameraManipulator()->setHomePosition(
		osg::Vec3(25.f, -35.f, 15.f),
		osg::Vec3(0.f, 0.f, 0.f),
		osg::Vec3(0.f, 0.f, 1.f));
	
	// Go to the cameras starting position
	viewer->home();

	// Set the max frame rate to 60 frames per second
	viewer->setRunMaxFrameRate(60.f);
	viewer->realize();

	// Begin rendering on new thread
	_beginthread( render, 0, NULL );
}