#include "StdAfx.h"
#include "DefineCoordinateFrameForm.h"
#include "MainFormController.h"

using namespace BlinkAnalysis;

System::Void DefineCoordinateFrameForm::coordinateSetButton_Click(System::Object^  sender, System::EventArgs^  e) {
			CaptureWorld* world = WorldManager::getInstance()->getWorld(displayWorld);
			if (world)
			{
				world->setCoordinateFrame(CaptureObjectUtil::makeGlobalToLocalMatrix(*posO, *posX, *posY));
				MainFormController::getInstance()->worldUpdateGridView(world->getID());
			}
				 
			this->Close();
		}

System::Void DefineCoordinateFrameForm::coordinateResetButton_Click(System::Object^  sender, System::EventArgs^  e) {
			CaptureWorld* world = WorldManager::getInstance()->getWorld(displayWorld);
			if (world)
			{
				osg::Matrix* m = new osg::Matrix();
				m->makeIdentity();
				world->setCoordinateFrame(m);
				MainFormController::getInstance()->worldUpdateGridView(world->getID());
			}
				 
			this->Close();
		}