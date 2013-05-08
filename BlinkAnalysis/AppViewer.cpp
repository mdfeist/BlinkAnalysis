#include "StdAfx.h"
#include "AppViewer.h"

#include <Windows.h>
#include <process.h>

#include <osgDB/ReadFile>
#include <osgViewer/Viewer>
#include <osgViewer/GraphicsWindow>
#include <osgViewer/api/win32/GraphicsWindowWin32>
#include <osgGA/TrackballManipulator>

osgViewer::Viewer* viewer;

void render(void *) {
	while( !viewer->done() )
	{
		// dispatch the new frame, this wraps up the follow Viewer operations:
		//   advance() to the new frame
		//   eventTraversal() that collects events and passes them on to the event handlers and event callbacks
		//   updateTraversal() to calls the update callbacks
		//   renderingTraversals() that runs syncronizes all the rendering threads (if any) and dispatch cull, draw and swap buffers
		viewer->frame();
	}
}

void AppViewer::initAppViewer(HWND hwnd)
{
	if (!viewer)
		viewer = new osgViewer::Viewer();

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

	osg::Group* rootNode = new osg::Group();
	osg::Node *model = osgDB::readNodeFile("cow.osg");
	rootNode->addChild(model);
	viewer->setSceneData(rootNode);

	viewer->getCamera()->setClearColor(osg::Vec4(1.0f,0.0f,0.0f,0.0f));
	viewer->setCameraManipulator( new osgGA::TrackballManipulator );

	viewer->realize();

	_beginthread( render, 0, NULL );
}