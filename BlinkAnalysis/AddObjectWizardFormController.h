#pragma once
#include "stdafx.h"
#include <string>

#include "AddObjectWizardForm.h"
#include "FormController.h"

using namespace System;

public ref class AddObjectWizardFormController sealed : 
	public FormController<AddObjectWizardFormController^ volatile, BlinkAnalysis::AddObjectWizardForm^>
{
public:
	
	void setDisplayWorld(int id)
	{
		if (form && !form->IsDisposed)
			form->selectWorld(id);
	}

	int getDisplayWorld()
	{
		if (form && !form->IsDisposed)
			return form->getDisplayWorld();
		return -1;
	}

	void setRigidBodyVector(std::vector<RigidBody*>* vector)
	{
		if (form && !form->IsDisposed)
			form->setRigidBodyVector(vector);
	}
};