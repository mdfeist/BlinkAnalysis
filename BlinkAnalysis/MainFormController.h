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
#include "FormController.h"

using namespace System;

public ref class MainFormController sealed :
	public FormController<MainFormController^ volatile, BlinkAnalysis::MainForm^>
{
public:
	// Saving
	void updateFormTitle() { this->form->updateTitle(); }
	void setInfo() { this->form->setInformation(); }
	void getInfo() { this->form->getInformation(); }

	// Prints to the Output window in the Dikablis Tab of the MainForm
	void dikablisOutputLog(std::string msg);
	// Send Dikablis Journal information to the Dikablis Tab of the MainForm
	void dikablisMessage(Dikablis::journal_struct journal);

	// Prints to the Output window in the OptiTrack Tab of the MainForm
	void optiTrackOutputLog(std::string msg);
	// Indicate that there was a change to the OptiTrack data
	void optiTrackUpdateData() { this->form->optiTrackUpdateData(); }
	// Initiate the OptiTrack view
	void optiTrackInitDataView() { this->form->optiTrackInitDataView(); }
	// Update world list
	void worldUpdateList() { this->form->worldUpdateList(); }
	void worldUpdateGridView(int id) { this->form->worldUpdateGridView(id); }
	void objectUpdateList() { this->form->objectComboBox_updateList(); }
	void objectUpdateGridView(int id) { this->form->objectUpdateGridView(id); }
};

