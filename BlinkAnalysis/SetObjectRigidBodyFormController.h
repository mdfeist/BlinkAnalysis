#pragma once
#include "stdafx.h"
#include <string>

#include "SetObjectRigidBodyForm.h"
#include "FormController.h"

using namespace System;

public ref class SetObjectRigidBodyFormController sealed : 
	public FormController<SetObjectRigidBodyFormController^ volatile, BlinkAnalysis::SetObjectRigidBodyForm^>
{
public:
	
	void setRigidBodyVector(std::vector<RigidBody*>* vector)
	{
		if (form && !form->IsDisposed)
			form->setRigidBodyVector(vector);
	}

	void setWorldAndObject(int world, int object)
	{
		if (form && !form->IsDisposed)
			form->setWorldAndObject(world, object);
	}

	void setHasRigidBody(bool rb)
	{
		if (form && !form->IsDisposed)
			form->setHasRigidBody(rb);
	}
};

