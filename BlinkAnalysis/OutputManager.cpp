#include "stdafx.h"

#include <Windows.h>
#include <stdlib.h>
#include <process.h>
#include <sstream>
#include <time.h>

#include "OutputManager.h"
#include "AppData.h"
#include "Dikablis.h"

OutputManager* OutputManager::m_pInstance = NULL; 

OutputManager::OutputManager(void)
{
	framesPerSec = 60;
	isRecording = false;
	isStreaming = false;
	isProcessing = false;

	streamRigid = true;
	streamMarker = true;
	streamEye = true;
}


OutputManager::~OutputManager(void)
{
}

// main thread that creates data frames based on FPS
void OutputManager::process(void *)
{
	// do not spawn multiple threads
	if (getInstance()->isProcessing) return;

	OutputManager* inst = getInstance();
	inst->isProcessing = true;

	ULONGLONG start = 0;
	std::stringstream sstream;
	ClientHandler* client = AppData::getInstance()->getClient();
	while (inst->isRecording || inst->isStreaming)
	{
		// track time since first frame created
		// Note: Windows has ~10-16 ms resolution, depending on CPU
		ULONGLONG t = GetTickCount64();
		ULONGLONG nextFrame = t + 1000/inst->framesPerSec;
		if (start == 0) start = t;
		
		// create frame
		
		// Lock the ClientHandler so data isn't changed
		// by another thread.
		if (client && client->lock()) {
			sstream << "<Frame time=\"";
			sstream << (float)(t-start) / CLOCKS_PER_SEC;
			sstream << "\" >\n";

			if (inst->streamEye)
			{
				// Get current position of head
				RigidBody* head = client->getHead();

				if (head != NULL) {
					sstream << "<EyeVector>\n";

					osg::Vec3 pos = head->getPosition();

					// Add to the head point
					sstream << "<Start ";
					sstream << "x=\"" << pos.x() << "\" ";
					sstream << "y=\"" << pos.y() << "\" ";
					sstream << "z=\"" << pos.z() << "\" ";
					sstream << "/>";

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

					sstream << "<End ";
					sstream << "x=\"" << ray.x() << "\" ";
					sstream << "y=\"" << ray.y() << "\" ";
					sstream << "z=\"" << ray.z() << "\" ";
					sstream << "/>";

					sstream << "</EyeVector>\n";
				}
			}

			if (inst->streamRigid)
			{
				std::map<int, RigidBody*>* rigidBodies = client->getRigidBodyMap();
			
				for (RigidBody_iterator it = rigidBodies->begin(); it != rigidBodies->end(); ++it) {
					sstream << "<RigidBody ";
			
					sstream << "id=\"" << it->second->getID() << "\" ";

					sstream << "x=\"" << it->second->getPosition().x() << "\" ";
					sstream << "y=\"" << it->second->getPosition().y() << "\" ";
					sstream << "z=\"" << it->second->getPosition().z() << "\" ";

					sstream << "qx=\"" << it->second->getRotation().x() << "\" ";
					sstream << "qy=\"" << it->second->getRotation().y() << "\" ";
					sstream << "qz=\"" << it->second->getRotation().z() << "\" ";
					sstream << "qw=\"" << it->second->getRotation().w() << "\" ";

					sstream << ">\n";

					std::vector<Marker>* markers = it->second->getMarkersVector();

					for (unsigned int i = 0; i < markers->size(); i++) {
						sstream << "<Marker ";
						sstream << "x=\"" << (*markers)[i].x() << "\" ";
						sstream << "y=\"" << (*markers)[i].y() << "\" ";
						sstream << "z=\"" << (*markers)[i].z() << "\" ";
						sstream << "/>\n";
					}

					sstream << "</RigidBody>\n";
				}
			}
			
			if (inst->streamMarker)
			{
				std::map<int, Marker*>* markerMap = client->getLabeledMarkerMap();
				for (labeledmarker_iterator it_marker = markerMap->begin(); it_marker != markerMap->end(); ++it_marker)
				{
					// Get Pointer to marker
					Marker* marker = it_marker->second;

					sstream << "<Labeled Marker ";
					sstream << "id=\"" << (*marker).getID() << "\" ";
					sstream << "x=\"" << (*marker).x() << "\" ";
					sstream << "y=\"" << (*marker).y() << "\" ";
					sstream << "z=\"" << (*marker).z() << "\" ";
					sstream << "/>\n";
				}
			}

			// Unlock the ClientHandler
			client->unlock();
		
			sstream << "</Frame>\n";
			
			if (inst->isRecording)
				RecordingManager::getInstance()->addFrame(sstream.str());

			if (inst->isStreaming)
				BlinkAnalysis::StreamingManager::getInstance()->addFrame(sstream.str());
		}
		else 
		{
			client = AppData::getInstance()->getClient();
		}
		sstream.str(std::string());
		sstream.clear();

		// sleep until next frame time
		int sleep = nextFrame-GetTickCount64();
		Sleep( (sleep) > 0 ? sleep : 0 );
	}

	inst->isProcessing = false;

	// Terminate thread
    _endthread();
}


void OutputManager::record(bool start)
{
	if (isRecording == start) return;

	if (start)
	{
		RecordingManager::getInstance()->startRecording();
		if (!isProcessing)
			_beginthread(&OutputManager::process, 0, NULL);
	}
	else
		RecordingManager::getInstance()->stopRecording();
	isRecording = start;
}

void OutputManager::stream(bool start)
{
	if (isStreaming == start) return;

	if (start)
	{
		BlinkAnalysis::StreamingManager::getInstance()->startStreaming();
		if (!isProcessing)
			_beginthread(&OutputManager::process, 0, NULL);
	}
	else
		BlinkAnalysis::StreamingManager::getInstance()->stopStreaming();
	isStreaming = start;
}

