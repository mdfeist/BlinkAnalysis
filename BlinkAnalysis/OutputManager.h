#ifndef OUTPUTMANAGER_H
#define OUTPUTMANAGER_H

#include "RecordingManager.h"
#include "StreamingManager.h"


/**
 * This class creates the frames to be output by 
 * either a recording, or a TCP stream
 */
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

	static float intersectBuffer;
	static float intersectLength;

	static void process(void *);

protected:
	OutputManager(void);
	~OutputManager(void);

public:
	static OutputManager* getInstance() {
		if(!m_pInstance) m_pInstance = new OutputManager();
		return m_pInstance;
	}

	// Note: Motive streams at 60FPS, Dikablis at 24FPS
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

	void setIntersectionBuffer(float buff) { 
		if (buff > 0)
			intersectBuffer = buff; 
	}
	float getIntersectionBuffer() { return intersectBuffer; }
	
	void setIntersectionLength(float len) { 
		if (len > 0)
			intersectLength = len; 
	}
	float getIntersectionLength() { return intersectLength; }

	void record(bool recording);
	void stream(bool streaming);
};

#endif
