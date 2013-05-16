#include "StdAfx.h"
#include "MainFormController.h"

#include "AppData.h"

MainFormController::MainFormController(void)
{
}

MainFormController::~MainFormController(void)
{
}

void MainFormController::updateInfo() {
	mainForm->updateInformation();
}

void MainFormController::dikablisOutputLog(std::string msg) {
	mainForm->dikablisOutputLog(gcnew String(msg.c_str()));
}

void MainFormController::dikablisMessage(Dikablis::journal_struct journal) {
	// Image
	mainForm->dikablisSetIndex(journal.index);
	mainForm->dikablisSetTimeStamp(journal.timestamp);

	// Calibration
	mainForm->dikablisSetEyeRoiHoriz(journal.eyeroihoriz);
	mainForm->dikablisSetEyeRoiVert(journal.eyeroivert);
	mainForm->dikablisSetEyeRoiZoomX(journal.eyeroizoomx);
	mainForm->dikablisSetEyeRoiZoomY(journal.eyeroizoomy);

	// Eye Data
	mainForm->dikablisSetEyeX(journal.eye_x);
	mainForm->dikablisSetEyeY(journal.eye_y);
	mainForm->dikablisSetFieldX(journal.field_x);
	mainForm->dikablisSetFieldY(journal.field_y);

	if (journal.eye_valid)
		mainForm->dikablisSetEyeValid("Pupil was detected");
	else
		mainForm->dikablisSetEyeValid("Pupil was not detected");

		if (journal.olinecalib)
		mainForm->dikablisSetOnlineCalibration("Calibration was performed online");
	else
		mainForm->dikablisSetOnlineCalibration("No online calibration");
}

void MainFormController::optiTrackOutputLog(std::string msg) {
	mainForm->optiTrackOutputLog(gcnew String(msg.c_str()));
}

