/**
 * EyeCalibrationWizardFormController.h
 * Created By: Michael Feist
 */
#pragma once
#include "stdafx.h"
#include <string>

#include "EyeCalibrationWizardForm.h"

using namespace System;

public ref class EyeCalibrationWizardFormController sealed
{
public:
	static EyeCalibrationWizardFormController^ getInstance() {
		if(!m_pInstance) m_pInstance = gcnew EyeCalibrationWizardFormController();
		return m_pInstance;
	}

	// Create a instance of the EyeCalibrationWizardForm if 
	// it doesn't already exist and show it
	void Show() { 
		if (!form || form->IsDisposed)
			 form = gcnew BlinkAnalysis::EyeCalibrationWizardForm();
		form->Show();
		form->BringToFront();
	}

	// Prints to the Output window in the Calculating Window
	void calibrationOutputLog(std::string msg) {
		if (form && !form->IsDisposed)
			this->form->calibrationOutputLog(gcnew String(msg.c_str()));
	}
protected:
	EyeCalibrationWizardFormController() {};
	~EyeCalibrationWizardFormController() {};
private:
	static EyeCalibrationWizardFormController^ volatile m_pInstance;

	BlinkAnalysis::EyeCalibrationWizardForm ^form;
};

