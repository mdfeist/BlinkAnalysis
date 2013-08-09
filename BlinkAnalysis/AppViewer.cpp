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
#include <osg/LineWidth>
#include <osgDB/ReadFile>
#include <osgViewer/Viewer>
#include <osgViewer/GraphicsWindow>
#include <osgViewer/api/win32/GraphicsWindowWin32>
#include <osgGA/TrackballManipulator>

#include "Objects.h"
#include "AppData.h"
#include "Dikablis.h"
#include "WorldManager.h"
#include "PickHandler.h"

osgViewer::Viewer* viewer;
osg::Group* rootNode;
osg::AutoTransform* sceneNode;
HANDLE g_hMutex;

osg::Vec3 lastRay;

bool running = false;
bool visible = false;

bool localMarkers = false;

float VIEWER_SCALE = 1.f;

osg::ref_ptr<osgGA::GUIEventHandler> pickMarkerHandler;
osg::ref_ptr<osgGA::GUIEventHandler> pickObjectHandler;

void AppViewer::stopAppViewer() { running = false; }
void AppViewer::setVisible(bool bVisible) { visible = bVisible; }

void AppViewer::setScale(int scale) {
	VIEWER_SCALE = scale;

	if (sceneNode)
		sceneNode->setScale(VIEWER_SCALE);
}

float AppViewer::getScale() {
	return VIEWER_SCALE;
}

void renderEyeVector(osg::Geode* node) {
	// Get the current client
	ClientHandler* client = AppData::getInstance()->getClient();

	// Check if the client was created and is not NULL
	if (client) {
		// Create Points
		// Create geo to store ray
		osg::Geometry* geo = new osg::Geometry(); 

		// Create array to hold ray
		osg::ref_ptr<osg::Vec3Array> points = new osg::Vec3Array(); 
		osg::ref_ptr<osg::Vec4Array> colors = new osg::Vec4Array();

		// Lock Client so marker data isn't changed
		if (client->lock())
		{
			// Get current position of head
			RigidBody* head = client->getHead();

			if (head != NULL) {
				osg::Vec3 pos = head->getPosition();

				// Add to the points array
				points->push_back( pos );
				colors->push_back(osg::Vec4(1, 0, 0, 1));

				osg::Matrixf headMatrix;
				headMatrix.makeIdentity();
				//headMatrix.makeTranslate(head->getPosition());
				float qx = -head->getRotation().x();
				float qy = -head->getRotation().y();
				float qz = -head->getRotation().z();
				float qw = head->getRotation().w();
				headMatrix.makeRotate(osg::Quat(qx, qy, qz, qw));

				Dikablis::journal_struct journal = Dikablis::getJournal();

				int x = journal.field_x;
				int y = journal.field_y;

				/*
				static int x = 0;
				static int y = 250;
				static float animation = 0.0f;

				animation += 0.01f;

				x = sinf(animation)*(250) + 250;
				*/

				osg::Vec3 ray = client->getRay(x, y);

				ray = headMatrix * ray;

				ray = (ray - lastRay)/4.f + lastRay;

				lastRay = ray;

				points->push_back( (ray + pos) );
				colors->push_back(osg::Vec4(1, 0, 0, 1));
			}
		}

		// Unlock Client so marker data can be updated
		client->unlock();

		// Add the points array to the geometry
		geo->setVertexArray( points ); 

		// Render the points geometry as Points
		geo->addPrimitiveSet( new osg::DrawArrays(osg::PrimitiveSet::LINES, 0, points->size() ) ); 

		// Set Color array to the geometry
		geo->setColorArray(colors); 
		geo->setColorBinding(osg::Geometry::BIND_PER_VERTEX); 

		// Add the geometry to the node
		node->addDrawable( geo );

		// Set the size of the points and turn off lighting
		osg::ref_ptr<osg::StateSet> nodeState = node->getOrCreateStateSet();
		nodeState->setMode(GL_LIGHTING, osg::StateAttribute::OFF);
		nodeState->setAttribute( new osg::LineWidth( 3.0f ) , osg::StateAttribute::ON );
	}
}

void renderMarkers(osg::Geode* node) {
	// Get the current client
	ClientHandler* client = AppData::getInstance()->getClient();

	// Check if the client was created and is not NULL
	if (client) {
		// Lock Client so marker data isn't changed
		if (client->lock())
		{
			// Create Points
			// Create geo to store rigid body points
			osg::Geometry* geo = new osg::Geometry(); 

			// Create array to hold points
			osg::ref_ptr<osg::Vec3Array> points = new osg::Vec3Array(); 
			osg::ref_ptr<osg::Vec4Array> colors = new osg::Vec4Array(); 

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
						points->push_back( pos  );

						// Add colors
						colors->push_back( marker.getColor() );

						// Update the current index
						markerIndex++;
					}
				}
			}

			if (localMarkers) {
				// Labeled Markers
				std::map<int, Marker*>* markerMap = client->getLabeledMarkerMap();
				for (labeledmarker_iterator it_marker = markerMap->begin(); it_marker != markerMap->end(); ++it_marker)
				{
					// Get Pointer to marker
					Marker* marker = it_marker->second;

					// Get current position of marker
					osg::Vec3 pos = marker->getPosition(); 

					// Add marker to the point array
					osg::Vec3Array* point = new osg::Vec3Array();
					point->push_back(pos);

					// Add color
					osg::Vec4Array* colour = new osg::Vec4Array();
					if (marker->isSelected())
						colour->push_back(osg::Vec4(0, 1, 0, 1));
					else
						colour->push_back(osg::Vec4(0, 0, 1, 1));

					osg::Geometry* geom = new osg::Geometry();
					geom->setVertexArray(point);
					geom->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::POINTS, 0, 1));
					geom->setColorArray(colour);
					geom->setColorBinding(osg::Geometry::BIND_PER_VERTEX);

					std::stringstream sstr;
					sstr << "LM ";
					sstr << marker->getID();
					geom->setName(sstr.str());
					node->addDrawable(geom);
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
			geo->setColorBinding(osg::Geometry::BIND_PER_VERTEX); 

			// Add the geometry to the node
			node->addDrawable( geo );

			// Set the size of the points and turn off lighting
			osg::ref_ptr<osg::StateSet> nodeState = node->getOrCreateStateSet();
			nodeState->setMode(GL_LIGHTING, osg::StateAttribute::OFF);
			nodeState->setMode(GL_BLEND, osg::StateAttribute::ON);
			nodeState->setMode(GL_POINT_SMOOTH, osg::StateAttribute::ON);
			nodeState->setAttribute( new osg::Point( 5.0f ) , osg::StateAttribute::ON );
			nodeState->setRenderingHint( osg::StateSet::TRANSPARENT_BIN );
			// End Create Points
		}
	}	
}

void render(void *) {
	// Started Rendering
	running = true;

	// Loop until done
	while( !viewer->done() )
	{
		// If not running stop render loop
		if (!running)
			viewer->setDone(!running);

		// Check if view is visible
		if (visible) {
			// Add Group to store all the marker points
			osg::Geode* markerNode = new osg::Geode(); 
			markerNode->setName("Markers");

			// Render the OptiTrack Markers
			renderMarkers(markerNode);

			// Render Eye Vector
			renderEyeVector(markerNode);

			// Add Node containing all the points to the scene
			if (AppViewer::lock())
			{
				sceneNode->addChild( markerNode );
			
				// Render frame
				viewer->frame();

				// Remove points from the scene
				sceneNode->removeChild( markerNode );

				AppViewer::unlock();
			}
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

	if (!g_hMutex)
	g_hMutex = CreateMutex(
		NULL,
		//(LPSECURITY_ATTRIBUTES)SYNCHRONIZE, 
		FALSE, 
		NULL);

	// Create new viewer if one doesn't exist
	if (!viewer)
		viewer = new osgViewer::Viewer();

	// Create new root node if one doesn't exist
	if (!rootNode)
	{
		rootNode = new osg::Group();
		rootNode->setName("AppViewer rootNode");
	}

	if (!sceneNode)
	{
		sceneNode = new osg::AutoTransform();
		sceneNode->setName("AppViewer sceneNode");
	}

	sceneNode->setScale(VIEWER_SCALE);
	rootNode->addChild(sceneNode);

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

	// Add the ground plane
	osg::Geode* planeNode = Objects::createPlane();
	planeNode->setName("Grid Plane");
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

	// For object picking
	pickMarkerHandler = new PickMarkerHandler(traits->width, traits->height);
	pickObjectHandler = new PickObjectHandler(traits->width, traits->height);
	rootNode->addChild(((PickMarkerHandler*)pickMarkerHandler.get())->getOrCreateHUD());
	rootNode->addChild(((PickObjectHandler*)pickObjectHandler.get())->getOrCreateHUD());

	// Begin rendering on new thread
	_beginthread( render, 0, NULL );
}

bool AppViewer::addNodeToViewer(osg::Node* node) {
	if (!sceneNode || !lock()) return false;
	bool result = sceneNode->addChild(node);
	unlock();
	return result;
}

bool AppViewer::removeNodeFromViewer(osg::Node* node) {
	if (!sceneNode || !lock()) return false;
	bool result = sceneNode->removeChild(node);
	unlock();
	return result;
}

void AppViewer::useMarkerPickHandler() {
	if (!viewer) return;

	if (pickObjectHandler.valid())
		((PickObjectHandler*)pickObjectHandler.get())->reset();
	viewer->removeEventHandler(pickObjectHandler);
	viewer->addEventHandler(pickMarkerHandler);
}

void AppViewer::useObjectPickHandler() {
	if (!viewer) return;
	
	if (pickMarkerHandler.valid())
		((PickMarkerHandler*)pickMarkerHandler.get())->reset();
	viewer->removeEventHandler(pickMarkerHandler);
	viewer->addEventHandler(pickObjectHandler);
}

void AppViewer::setDisplayLabeledMarkers(bool display)
{
	localMarkers = display;
	if (!display && pickMarkerHandler.valid())
		((PickMarkerHandler*)pickMarkerHandler.get())->reset();
}

void AppViewer::setDisplayCaptureObjects(bool display)
{
	osg::Node* worldNode = WorldManager::getInstance()->getWorldNode();
	if (display && !sceneNode->containsNode(worldNode))
	{
		if (!lock()) return;
		sceneNode->addChild(worldNode);
		unlock();
	}
	else if (!display)
	{
		if (pickObjectHandler.valid())
			((PickObjectHandler*)pickObjectHandler.get())->reset();

		if (!lock()) return;
		sceneNode->removeChild(worldNode);
		unlock();
	}
}

bool AppViewer::lock() {
	// Request ownership of mutex
	DWORD  dwWaitResult;
	while(true)
	{
		// Wait for Mutex to be free
		dwWaitResult = WaitForSingleObject(g_hMutex, INFINITE);
		switch (dwWaitResult) 
		{
			// The thread got ownership of the mutex
		case WAIT_OBJECT_0: 
			return true;
			break; 

			// The thread got ownership of an abandoned mutex
			// The database is in an indeterminate state
		case WAIT_ABANDONED: 
			return false; 
			break;
		}
	}

	return false;
}

void AppViewer::unlock() { ReleaseMutex(g_hMutex); }

std::string AppViewer::getIntersectionData(osg::Vec3 start, osg::Vec3 end, float buffer, float length)
{
	if (!viewer) return "";

	osg::Vec3 normal = end - start;

	osg::Matrix transformMat;
	osg::Quat rot;
	rot.makeRotate(osg::Vec3(0, 0, 1), normal);
	transformMat.setRotate(rot);
	transformMat.setTrans(start);
	transformMat *= osg::Matrix::scale(VIEWER_SCALE, VIEWER_SCALE, VIEWER_SCALE);

	// form box with bottom at origin
	// length and width buffer*2
	osg::Polytope::PlaneList pl;
	pl.push_back(osg::Plane(-1, 0, 0, buffer));
	pl.push_back(osg::Plane(0, -1, 0, buffer));
	pl.push_back(osg::Plane(1, 0, 0, buffer));
	pl.push_back(osg::Plane(0, 1, 0, buffer));
	pl.push_back(osg::Plane(0, 0, 1, 0));
	pl.push_back(osg::Plane(0, 0, -1, length));

	osg::Polytope poly;
	poly.set(pl);
	poly.transform(transformMat);

	osg::ref_ptr<osgUtil::PolytopeIntersector> intersect = new osgUtil::PolytopeIntersector(
								osgUtil::PolytopeIntersector::MODEL, poly);
	intersect->setDimensionMask(osgUtil::PolytopeIntersector::DimTwo);    // only pick objects

	osgUtil::PolytopeIntersector::Intersections intersections;
	std::set<std::string> hits;	// may have multiple intersections per object
	std::stringstream sstream;
	
	osgUtil::IntersectionVisitor iv( intersect );
	if (lock())
		viewer->getCamera()->accept( iv );  
	else
		return "";
	unlock();
	if (intersect->containsIntersections())
	{
		intersections = intersect->getIntersections();
		for (osgUtil::PolytopeIntersector::Intersections::iterator hitr = intersections.begin();
				hitr != intersections.end(); hitr++)
		{

			if (!hitr->nodePath.empty())
			{
				std::string name = hitr->nodePath.back()->getName();
				// geode containing captured object has the following name format
				// OBJ wid,oid
				if (!name.substr(0, 3).compare("OBJ"))
				{
					hits.insert(name.substr(4, name.length()-4));
				}
			}
		}
	}

	for (std::set<std::string>::iterator itr = hits.begin(); itr != hits.end(); itr++)
	{
		std::istringstream oss(*itr);
		std::string num;
		getline(oss, num, ',');
		int wid = atoi(num.c_str());
		getline(oss, num, ',');
		int oid = atoi(num.c_str());

		sstream << "<Intersection ";
		sstream << "world=\"" << wid << "\" ";
		sstream << "object=\"" << oid << "\" ";
		sstream << "/>\n";
	}
	return sstream.str();
}


int teapotIdx = -1;
void AppViewer::addTeapot()
{
		osg::AutoTransform* modelTransform = NULL;
	if (teapotIdx >= 0)
	{
		modelTransform = dynamic_cast<osg::AutoTransform*>(sceneNode->getChild(teapotIdx));
	}
	else if (!modelTransform)
	{
		modelTransform = new osg::AutoTransform();
		modelTransform->addChild(osgDB::readNodeFile("teapot.osg"));
		addNodeToViewer(modelTransform);
		teapotIdx = sceneNode->getChildIndex(modelTransform);
	}

	ClientHandler* client = AppData::getInstance()->getClient();
	if (client)
	{
		RigidBody* rb = client->getRigidBody(client->getRigidBodyTool());
		if (rb)
		{
			modelTransform->setPosition(rb->getPosition());
			modelTransform->setRotation(rb->getRotation());
			return;
		}
	}
	modelTransform->setPosition(osg::Vec3(0, 0, 0));
	modelTransform->setRotation(osg::Quat(0, 0, 0, 1));
}

void AppViewer::removeTeapot()
{
	removeNodeFromViewer(sceneNode->getChild(teapotIdx));
	teapotIdx = -1;
}
