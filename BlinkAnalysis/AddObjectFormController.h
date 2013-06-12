#pragma once
#include "stdafx.h"
#include <string>

#include "AddObjectForm.h"
#include "FormController.h"

using namespace System;

public ref class AddObjectFormController sealed : 
	public FormController<AddObjectFormController^ volatile, BlinkAnalysis::AddObjectForm^>
{
public:
	
	void setDisplayWorld(int id)
	{
		if (form && !form->IsDisposed)
			form->setDisplayWorld(id);
	}

	int getDisplayWorld()
	{
		if (form && !form->IsDisposed)
			return form->getDisplayWorld();
		return -1;
	}

};

