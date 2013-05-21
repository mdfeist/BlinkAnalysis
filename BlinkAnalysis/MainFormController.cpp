#include "StdAfx.h"
#include "MainFormController.h"

#include "AppData.h"

MainFormController::MainFormController(void)
{
}

MainFormController::~MainFormController(void)
{
}

void MainFormController::dikablisOutputLog(std::string msg) {
	this->mainForm->dikablisOutputLog(gcnew String(msg.c_str()));
}

void MainFormController::dikablisMessage(Dikablis::journal_struct journal) {
	// Image
	this->mainForm->dikablisSetIndex(journal.index);
	this->mainForm->dikablisSetTimeStamp(journal.timestamp);

	// Calibration
	this->mainForm->dikablisSetEyeRoiHoriz(journal.eyeroihoriz);
	this->mainForm->dikablisSetEyeRoiVert(journal.eyeroivert);
	this->mainForm->dikablisSetEyeRoiZoomX(journal.eyeroizoomx);
	this->mainForm->dikablisSetEyeRoiZoomY(journal.eyeroizoomy);

	// Eye Data
	this->mainForm->dikablisSetEyeX(journal.eye_x);
	this->mainForm->dikablisSetEyeY(journal.eye_y);
	this->mainForm->dikablisSetFieldX(journal.field_x);
	this->mainForm->dikablisSetFieldY(journal.field_y);

	if (journal.eye_valid)
		this->mainForm->dikablisSetEyeValid("Pupil was detected");
	else
		this->mainForm->dikablisSetEyeValid("Pupil was not detected");

		if (journal.olinecalib)
		this->mainForm->dikablisSetOnlineCalibration("Calibration was performed online");
	else
		this->mainForm->dikablisSetOnlineCalibration("No online calibration");
}

void MainFormController::optiTrackOutputLog(std::string msg) {
	this->mainForm->optiTrackOutputLog(gcnew String(msg.c_str()));
}

