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

	bool streamRigid;
	bool streamMarker;
	bool streamEye;

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
		if (fps <= 100 && fps > 0)
			framesPerSec = fps; 
	}
	int getFramesPerSec() { return framesPerSec; }

	void setRigid(bool stream) { streamRigid = stream; }
	bool getRigid() { return streamRigid; }

	void setMarker(bool stream) { streamMarker = stream; }
	bool getMarker() { return streamMarker; }

	void setEye(bool stream) { streamEye = stream; }
	bool getEye() { return streamEye; }

	void record(bool recording);

	void stream(bool streaming);
};

#endif
