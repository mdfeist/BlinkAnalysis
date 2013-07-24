#include "StdAfx.h"
#include "Recording.h"

#include "MainFormController.h"
#include "RecordingManager.h"
#include "Settings.h"

Recording::Recording(void)
{
	this->readyForRecording = false;
	this->id = RecordingManager::getInstance()->getNewID();
}


Recording::~Recording(void)
{
	this->rigidBodies.clear();
}

bool Recording::loadRecording(pugi::xml_node recording) {
	// Clear previous frames
	frames.clear();

	// Get the name of the recording
	pugi::xml_attribute recording_name = recording.attribute("name");

	if (recording_name) {
		this->name = recording_name.value();
	}

	// Get Static Objects
	pugi::xml_node static_objects = recording.child("StaticData");

	for (pugi::xml_node rigidBody = static_objects.child("RigidBody"); rigidBody; rigidBody = static_objects.next_sibling("RigidBody")) {
		pugi::xml_attribute id = rigidBody.attribute("id");
		pugi::xml_attribute name = rigidBody.attribute("name");

		RigidBody* rb = new RigidBody();
		rb->setID(id.as_int());
		rb->setName((char*)name.value());

		// Add the Rigid Body
		this->rigidBodies.insert ( std::pair<int, RigidBody*>(id.as_int(), rb) );
	}

	return true;
}

void XTrace(LPCTSTR lpszFormat, ...)
{
    va_list args;
    va_start(args, lpszFormat);
    int nBuf;
    TCHAR szBuffer[512]; // get rid of this hard-coded buffer
    nBuf = _vsntprintf_s(szBuffer, 511, lpszFormat, args);
    ::OutputDebugString(szBuffer);
    va_end(args);
}

void CTrace(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    int nBuf;
    char szBuffer[512]; // get rid of this hard-coded buffer
    nBuf = sprintf_s(szBuffer, 511, format, args);
    ::OutputDebugStringA(szBuffer);
    va_end(args);
}


void Recording::initializeRecording() {

	ClientHandler* client = AppData::getInstance()->getClient();

	if (client) {
		UINT uRetVal = 0;
		DWORD dwRetVal = 0;
		// Get the temp path.
		dwRetVal = GetTempPath(MAX_PATH, // length of the buffer
			lpTempPathBuffer); // buffer for path

		if (dwRetVal > MAX_PATH) {
			MainFormController::getInstance()->showError(L"Failed to find temporary directory.\n");
			RecordingManager::getInstance()->stopRecording();
			return;
		}

		// Create a temporary file.
		uRetVal = GetTempFileName(lpTempPathBuffer, // directory for tmp files
			L"BlinkAnalysisRecording", // temp file name prefix
			0, // create unique name
			szTempFileName); // buffer for the name

		if (uRetVal == 0)
		{
			MainFormController::getInstance()->showError(L"Failed to create temporary file.\n");
			RecordingManager::getInstance()->stopRecording();
			return;
		}

		fileStream.open(szTempFileName);
		
		if (fileStream.is_open()) {
			
			fileStream << "<Recording>\n";
			fileStream << "<StaticData>\n";

			fileStream << AppData::getInstance()->getRigidBodyStaticData();
			fileStream << WorldManager::getInstance()->getWorldStaticData();

			fileStream << "</StaticData>\n";
			fileStream << "<Frames>\n";
		} else {
			MainFormController::getInstance()->showError(L"Failed to open file for recording.\n");
			RecordingManager::getInstance()->stopRecording();
			return;
		}
	}
	
	this->readyForRecording = true;
}

void Recording::addFrame(std::string frame) {
	if (!this->readyForRecording)
		initializeRecording();

	if (!fileStream.is_open())
		return;

	fileStream << frame;
}

void Recording::closeRecording() {
	if (fileStream.is_open()) {
		fileStream << "</Frames>\n";
		fileStream << "</Recording>\n";
		fileStream.close();
	}

	bool save = true;

	if (!MainFormController::getInstance()->propt(L"Save Recording", L"Would you like to save the recording?"))
		save = false;

	while (save) {
		std::string filePath;
		MainFormController::getInstance()->getFilePath(filePath, Settings::getInstance()->getDefaultProjectDirectory());

		if (filePath != "") {
			TCHAR destination[MAX_PATH + 1];
			MultiByteToWideChar(CP_ACP, 0, filePath.c_str(), -1, destination, filePath.length());

			destination[filePath.length()] = 0;

			MoveFileEx(szTempFileName, destination, MOVEFILE_REPLACE_EXISTING);

			save = false;
		} else {
			if (MainFormController::getInstance()->propt(L"Save Recording", L"Are you sure you would like to continue without saving the recording?")) {
				save = false;
			}
		}
	}
}
