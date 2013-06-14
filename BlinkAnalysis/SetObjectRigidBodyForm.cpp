#include "StdAfx.h"
#include "SetObjectRigidBodyForm.h"
#include "MainFormController.h"

using namespace BlinkAnalysis;

System::Void SetObjectRigidBodyForm::attachButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (rigidID >= 0)
			 {
				 CaptureWorld* world = WorldManager::getInstance()->getWorld(worldID);
				 if (world)
				 {
					 CaptureObject* object = world->getObject(objectID);
					 if (object)
					 {
						 object->setRigidBody(rigidID);
						 MainFormController::getInstance()->objectUpdateGridView(object->getID());
					 }
				 }
			 }
			 this->Close();
		 }
System::Void SetObjectRigidBodyForm::detachButton_Click(System::Object^  sender, System::EventArgs^  e) {
			CaptureWorld* world = WorldManager::getInstance()->getWorld(worldID);
			if (world)
			{
				CaptureObject* object = world->getObject(objectID);
				if (object)
				{
					object->setRigidBody(-1);
					MainFormController::getInstance()->objectUpdateGridView(object->getID());
				}
			}
			this->Close();
		 }
