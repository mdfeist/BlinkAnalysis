#ifndef OUTPUTMANAGER_H
#define OUTPUTMANAGER_H

#include "RecordingManager.h"
#include "StreamingManager.h"


public class OutputManager
{
private:
	static OutputManager* m_pInstance;
	int framesPerSec;
	bool isRecording;
	bool isStreaming;
	bool isProcessing;

	static void process(void *);

protected:
	OutputManager(void);
	~OutputManager(void);

public:
	static OutputManager* getInstance() {
		if(!m_pInstance) m_pInstance = new OutputManager();
		return m_pInstance;
	}

	void setFramesPerSec(int fps) { 
		if (fps <= 1000 && fps > 0)
			framesPerSec = fps; 
	}
	int getFramesPerSec() { return framesPerSec; }

	void record(bool recording);

	void stream(bool streaming);
};

#endif
