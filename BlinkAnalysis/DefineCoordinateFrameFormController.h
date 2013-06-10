#pragma once
#include "stdafx.h"
#include <string>

#include "DefineCoordinateFrameForm.h"
#include "FormController.h"

using namespace System;

public ref class DefineCoordinateFrameFormController sealed : 
	public FormController<DefineCoordinateFrameFormController^ volatile, BlinkAnalysis::DefineCoordinateFrameForm^>
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
	/*
	void updateWorldViewHandler(System::EventHandler^ handler)
	{
		if (form && !form->IsDisposed)
			form->UpdateWorldView += handler;		
	}*/

};

