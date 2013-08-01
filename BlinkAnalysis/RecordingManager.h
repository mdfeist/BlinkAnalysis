#pragma once
#include <vector>

#include "Recording.h"

/**
 * Class for managing recording saving
 */
class RecordingManager
{
public:
	static RecordingManager* getInstance() {
		if(!m_pInstance) m_pInstance = new RecordingManager();
		return m_pInstance;
	}

	bool isRecording() { return this->recording; }
	void startRecording();
	void stopRecording();
	void addFrame(std::string frame);

	std::vector<Recording*> getRecordings() { return this->recordings; }

	int getNewID() { 
		this->recordingIDCount++;
		return this->recordingIDCount;
	}

protected:
	RecordingManager(void);
	~RecordingManager(void);
private:
	RecordingManager(RecordingManager const&);
	RecordingManager& operator=(RecordingManager const&);

	static RecordingManager* m_pInstance;

	int recordingIDCount;
	bool recording;

	Recording* currentRecording;

	std::vector<Recording*> recordings;

	void addRecording();
};

