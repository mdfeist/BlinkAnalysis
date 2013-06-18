/**
 * AppViewer.h
 * Created By: Michael Feist
 *
 * Handles the OSG 3D rendering view.
 */

#pragma once
#include "stdafx.h"
#include <Windows.h>
#include <osg/Node>

namespace AppViewer {
	// Creates a new OSG view in the given windows view
	void initAppViewer(HWND hwnd);
	// Stop the rendering and quit the thread
	void stopAppViewer();
	// Pause rendering when not visible
	void setVisible(bool bVisible);
	// Add/remove nodes from scene
	bool addNodeToViewer(osg::Node* node);
	bool removeNodeFromViewer(osg::Node* node);
	// The Scale of the Viewers Scenes
	void setScale(int scale);
};