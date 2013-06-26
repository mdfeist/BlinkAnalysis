#include "StdAfx.h"
#include "SetObjectRigidBodyForm.h"
#include "MainFormController.h"

using namespace BlinkAnalysis;

System::Void SetObjectRigidBodyForm::attachButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 bool result = true;
			 if (rigidID >= 0)
			 {
				 CaptureWorld* world = WorldManager::getInstance()->getWorld(worldID);
				 if (world)
				 {
					 result = world->setObjectRigidBody(objectID, rigidID, this->offsetCheckBox->Checked);
					 if (!result)
					 {
						 String^ message = "Could not attach object (ID " + objectID.ToString() + ") to rigid body (ID " + 
							 rigidID.ToString() + "). \nIs the rigid body already attached to an object in a different world?";
						 MessageBox::Show(message, "Could not attach rigid body", MessageBoxButtons::OK, MessageBoxIcon::Warning);
					 }
				 }
			 }
			 if (result)
				this->Close();
		 }
System::Void SetObjectRigidBodyForm::detachButton_Click(System::Object^  sender, System::EventArgs^  e) {
			CaptureWorld* world = WorldManager::getInstance()->getWorld(worldID);
			if (world)
			{
				 world->setObjectRigidBody(objectID, -1, this->offsetCheckBox->Checked);
			}
			this->Close();
		 }
