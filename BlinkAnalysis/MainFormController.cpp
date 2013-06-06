#include "StdAfx.h"
#include "MainFormController.h"

#include "AppData.h"

void MainFormController::dikablisOutputLog(std::string msg) {
	this->form->dikablisOutputLog(gcnew String(msg.c_str()));
}

void MainFormController::dikablisMessage(Dikablis::journal_struct journal) {
	// Image
	this->form->dikablisSetIndex(journal.index);
	this->form->dikablisSetTimeStamp(journal.timestamp);

	// Calibration
	this->form->dikablisSetEyeRoiHoriz(journal.eyeroihoriz);
	this->form->dikablisSetEyeRoiVert(journal.eyeroivert);
	this->form->dikablisSetEyeRoiZoomX(journal.eyeroizoomx);
	this->form->dikablisSetEyeRoiZoomY(journal.eyeroizoomy);

	// Eye Data
	this->form->dikablisSetEyeX(journal.eye_x);
	this->form->dikablisSetEyeY(journal.eye_y);
	this->form->dikablisSetFieldX(journal.field_x);
	this->form->dikablisSetFieldY(journal.field_y);

	if (journal.eye_valid)
		this->form->dikablisSetEyeValid("Pupil was detected");
	else
		this->form->dikablisSetEyeValid("Pupil was not detected");

		if (journal.olinecalib)
		this->form->dikablisSetOnlineCalibration("Calibration was performed online");
	else
		this->form->dikablisSetOnlineCalibration("No online calibration");
}

void MainFormController::optiTrackOutputLog(std::string msg) {
	this->form->optiTrackOutputLog(gcnew String(msg.c_str()));
}

