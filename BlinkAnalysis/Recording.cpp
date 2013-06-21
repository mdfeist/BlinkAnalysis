#include "StdAfx.h"
#include "Recording.h"

#include "AppData.h"
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

			// Lock the ClientHandler so data isn't changed
			// by another thread.
			if (!client->lock())
				return;

			std::map<int, RigidBody*>* rigidBodies = client->getRigidBodyMap();

			for (RigidBody_iterator it = rigidBodies->begin(); it != rigidBodies->end(); ++it) {
				fileStream << "<RigidBody ";
				fileStream << "id=\"" << it->second->getID() << "\" ";
				fileStream << "name=\"" << it->second->getName() << "\" ";
				fileStream << "/>\n";
			}

			// Unlock the ClientHandler
			client->unlock();

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

void Recording:: addFrame() {
	if (!this->readyForRecording)
		initializeRecording();

	if (!fileStream.is_open())
		return;

	ClientHandler* client = AppData::getInstance()->getClient();

	if (client) {
		fileStream << "<Frame>\n";

		// Lock the ClientHandler so data isn't changed
		// by another thread.
		if (!client->lock())
			return;

		// Get current position of head
		RigidBody* head = client->getHead();

		if (head != NULL) {
			fileStream << "<EyeVector>\n";

			osg::Vec3 pos = head->getPosition();

			// Add to the head point
			fileStream << "<Start ";
			fileStream << "x=\"" << pos.x() << "\" ";
			fileStream << "y=\"" << pos.y() << "\" ";
			fileStream << "z=\"" << pos.z() << "\" ";
			fileStream << "/>";

			osg::Matrixf headMatrix;
			headMatrix.makeIdentity();
			float qx = -head->getRotation().x();
			float qy = -head->getRotation().y();
			float qz = -head->getRotation().z();
			float qw = head->getRotation().w();
			headMatrix.makeRotate(osg::Quat(qx, qy, qz, qw));

			Dikablis::journal_struct journal = Dikablis::getJournal();

			int x = journal.field_x;
			int y = journal.field_y;

			osg::Vec3 ray = client->getRay(x, y);

			ray = headMatrix * ray;
			ray = (ray + pos);

			fileStream << "<End ";
			fileStream << "x=\"" << ray.x() << "\" ";
			fileStream << "y=\"" << ray.y() << "\" ";
			fileStream << "z=\"" << ray.z() << "\" ";
			fileStream << "/>";

			fileStream << "</EyeVector>\n";
		}

		std::map<int, RigidBody*>* rigidBodies = client->getRigidBodyMap();

		for (RigidBody_iterator it = rigidBodies->begin(); it != rigidBodies->end(); ++it) {
			fileStream << "<RigidBody ";
			
			fileStream << "id=\"" << it->second->getID() << "\" ";

			fileStream << "x=\"" << it->second->getPosition().x() << "\" ";
			fileStream << "y=\"" << it->second->getPosition().y() << "\" ";
			fileStream << "z=\"" << it->second->getPosition().z() << "\" ";

			fileStream << "qx=\"" << it->second->getRotation().x() << "\" ";
			fileStream << "qy=\"" << it->second->getRotation().y() << "\" ";
			fileStream << "qz=\"" << it->second->getRotation().z() << "\" ";
			fileStream << "qw=\"" << it->second->getRotation().w() << "\" ";

			fileStream << ">\n";

			std::vector<Marker>* markers = it->second->getMarkersVector();

			for (unsigned int i = 0; i < markers->size(); i++) {
				fileStream << "<Marker ";
				fileStream << "x=\"" << (*markers)[i].x() << "\" ";
				fileStream << "y=\"" << (*markers)[i].y() << "\" ";
				fileStream << "z=\"" << (*markers)[i].z() << "\" ";
				fileStream << "/>\n";
			}

			fileStream << "</RigidBody>\n";
		}

		std::map<int, Marker*>* markerMap = client->getLabeledMarkerMap();
		for (labeledmarker_iterator it_marker = markerMap->begin(); it_marker != markerMap->end(); ++it_marker)
		{
			// Get Pointer to marker
			Marker* marker = it_marker->second;

			fileStream << "<Marker ";
			fileStream << "x=\"" << (*marker).x() << "\" ";
			fileStream << "y=\"" << (*marker).y() << "\" ";
			fileStream << "z=\"" << (*marker).z() << "\" ";
			fileStream << "/>\n";
		}

		// Unlock the ClientHandler
		client->unlock();
		
		fileStream << "</Frame>\n";
	}
}

void Recording::closeRecording() {
	if (fileStream.is_open()) {
		fileStream << "</Frames>\n";
		fileStream << "</Recording>\n";
		fileStream.close();
	}

	std::string filePath;
	MainFormController::getInstance()->getFilePath(filePath, Settings::getInstance()->getDefaultProjectDirectory());

	if (filePath != "") {
		TCHAR destination[MAX_PATH + 1];
		MultiByteToWideChar(CP_ACP, 0, filePath.c_str(), -1, destination, filePath.length());

		destination[filePath.length()] = 0;

		MoveFileEx(szTempFileName, destination, MOVEFILE_REPLACE_EXISTING);
	}
}
