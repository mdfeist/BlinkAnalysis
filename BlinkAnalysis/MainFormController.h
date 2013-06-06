/**
 * MainFormController.h
 * Created By: Michael Feist
 *
 * This a controller class to help bridge the model/data
 * with the GUI in the MainForm.
 */
#pragma once
#include "stdafx.h"
#include <string>

#include "Dikablis.h"
#include "MainForm.h"

using namespace System;

public ref class MainFormController sealed
{
public:
	static MainFormController^ getInstance() {
		if(!m_pInstance) m_pInstance = gcnew MainFormController();
		return m_pInstance;
	}

	// Saving
	void updateFormTitle() { this->mainForm->updateTitle(); }
	void setInfo() { this->mainForm->setInformation(); }
	void getInfo() { this->mainForm->getInformation(); }

	// Prints to the Output window in the Dikablis Tab of the MainForm
	void dikablisOutputLog(std::string msg);
	// Send Dikablis Journal information to the Dikablis Tab of the MainForm
	void dikablisMessage(Dikablis::journal_struct journal);

	// Prints to the Output window in the OptiTrack Tab of the MainForm
	void optiTrackOutputLog(std::string msg);
	// Indicate that there was a change to the OptiTrack data
	void optiTrackUpdateData() { this->mainForm->optiTrackUpdateData(); }
	// Initiate the OptiTrack view
	void optiTrackInitDataView() { this->mainForm->optiTrackInitDataView(); }

	// Update world list
	void worldUpdateData() { this->mainForm->worldUpdateData(); }

	// Attach a instance of the MainForm to the controller
	void attachMainForm(BlinkAnalysis::MainForm ^form) { this->mainForm = form; }
protected:
	MainFormController();
	~MainFormController();
private:
	static MainFormController^ volatile m_pInstance;

	BlinkAnalysis::MainForm ^mainForm;
};

