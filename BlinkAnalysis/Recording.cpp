#include "StdAfx.h"
#include "Recording.h"

#include "AppData.h"
#include "MainFormController.h"
#include "RecordingManager.h"

typedef std::map<int, RigidBody*>::iterator RigidBody_iterator;

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

		std::string filePath;
		MainFormController::getInstance()->getFilePath(filePath);

		//tempFileStream.open(szTempFileName);
		tempFileStream.open(filePath);

		if (tempFileStream.is_open()) {
			
			tempFileStream << "<Recording>\n";
			tempFileStream << "\t<StaticData>\n";
			std::map<int, RigidBody*>* rigidBodies = client->getRigidBodyMap();

			for (RigidBody_iterator it = rigidBodies->begin(); it != rigidBodies->end(); ++it) {
				tempFileStream << "\t\t<RigidBody ";
				tempFileStream << "id=\"" << it->second->getID() << "\" ";
				tempFileStream << "name=\"" << it->second->getName() << "\" ";
				tempFileStream << "/>\n";
			}

			tempFileStream << "\t</StaticData>\n";
			tempFileStream << "\t<Frames>\n";
		}
	}
	
	this->readyForRecording = true;
}

void Recording:: addFrame() {
	if (!this->readyForRecording)
		initializeRecording();

	if (!tempFileStream.is_open())
		return;

	ClientHandler* client = AppData::getInstance()->getClient();

	if (client) {
		tempFileStream << "\t\t<Frame>\n";

		std::map<int, RigidBody*>* rigidBodies = client->getRigidBodyMap();

		for (RigidBody_iterator it = rigidBodies->begin(); it != rigidBodies->end(); ++it) {
			tempFileStream << "\t\t\t<RigidBody \n";
			
			tempFileStream << "id=\"" << it->second->getID() << "\" ";

			tempFileStream << "x=\"" << it->second->getPosition().x() << "\" ";
			tempFileStream << "y=\"" << it->second->getPosition().y() << "\" ";
			tempFileStream << "z=\"" << it->second->getPosition().z() << "\" ";

			tempFileStream << "qx=\"" << it->second->getRotation().x() << "\" ";
			tempFileStream << "qy=\"" << it->second->getRotation().y() << "\" ";
			tempFileStream << "qz=\"" << it->second->getRotation().z() << "\" ";
			tempFileStream << "qw=\"" << it->second->getRotation().w() << "\" ";

			tempFileStream << "/>\n";
		}
		
		tempFileStream << "\t\t</Frame>\n";
	}
}

void Recording::closeRecording() {
	if (tempFileStream.is_open()) {
		tempFileStream << "\t</Frames>\n";
		tempFileStream << "</Recording>\n";
		tempFileStream.close();
	}
}
