#include "StdAfx.h"
#include "MainFormController.h"

#include "AppData.h"

#include <msclr\marshal_cppstd.h>

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

void MainFormController::showError(LPCTSTR msg) {
	MessageBox::Show(gcnew String(msg), "Error", 
    MessageBoxButtons::OK, MessageBoxIcon::Warning);
}

std::string MainFormController::getSpecialFolderMyDocuments() {
	msclr::interop::marshal_context context;
	return context.marshal_as<std::string>(Environment::GetFolderPath(Environment::SpecialFolder::MyDocuments));
}

void MainFormController::getFilePath(std::string& pathBuffer) {
	getFilePath(pathBuffer, "");
}

void MainFormController::getFilePath(std::string& pathBuffer, std::string defaultPath) {
	SaveFileDialog^ dialog = gcnew SaveFileDialog;

	dialog->DefaultExt = "xml";
	dialog->Filter = "XML files (*.xml)|*.xml|All files (*.*)|*.*";
	dialog->FilterIndex = 2;
	dialog->RestoreDirectory = true;

	if (defaultPath != "") {
		dialog->InitialDirectory = gcnew String(defaultPath.c_str());
	}
	
	if ( dialog->ShowDialog() == ::DialogResult::OK )
	{
		msclr::interop::marshal_context context;
		pathBuffer = context.marshal_as<std::string>(dialog->FileName);
	}
}

bool MainFormController::propt(LPCTSTR title, LPCTSTR msg) {
	if (MessageBox::Show(gcnew String(msg), gcnew String(title), MessageBoxButtons::YesNo) == DialogResult::Yes) {
		return true;
	} else {
		return false;
	}
}

