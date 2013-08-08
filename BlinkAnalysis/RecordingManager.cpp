#include "StdAfx.h"
#include "RecordingManager.h"

#include <Windows.h>
#include <process.h>
#include <stdlib.h>

RecordingManager* RecordingManager::m_pInstance = NULL; 

RecordingManager::RecordingManager(void)
{
	this->recording = false;
	this->recordingIDCount = 0;

	this->currentRecording = NULL;
}


RecordingManager::~RecordingManager(void)
{
	this->recordings.clear();
}

void RecordingManager::addRecording() {
	if (this->currentRecording != NULL) {
		this->recordings.push_back(this->currentRecording);
		this->currentRecording->closeRecording();
		this->currentRecording = 0;
	}
}

void RecordingManager::startRecording() {
	if (!this->recording) {
		addRecording();

		this->currentRecording = new Recording();

		this->recording = true;
	}
}

void RecordingManager::stopRecording() {
	if (this->recording) {
		this->recording = false;

		addRecording();
	}
}

void RecordingManager::addFrame(std::string frame)
{
	if (this->recording) {
		this->currentRecording->addFrame(frame);
	}
}
