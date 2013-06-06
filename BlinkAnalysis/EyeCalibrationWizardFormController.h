/**
 * EyeCalibrationWizardFormController.h
 * Created By: Michael Feist
 */
#pragma once
#include "stdafx.h"
#include <string>

#include "EyeCalibrationWizardForm.h"
#include "FormController.h"

using namespace System;

public ref class EyeCalibrationWizardFormController sealed : 
	public FormController<EyeCalibrationWizardFormController^ volatile, BlinkAnalysis::EyeCalibrationWizardForm^>
{
public:
	// Prints to the Output window in the Calculating Window
	void calibrationOutputLog(std::string msg) {
		if (form && !form->IsDisposed)
			this->form->calibrationOutputLog(gcnew String(msg.c_str()));
	}
};

