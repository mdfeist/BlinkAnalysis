#ifndef STREAMINGMANAGER_H
#define STREAMINGMANAGER_H

#include <vcclr.h>
#include <string>
#include <queue>
#include <Windows.h>

#include "StreamHandler.h"


/*
This and StreamHandler class are based on the code by Matthew YC So found here
http://www.codeproject.com/Articles/2866/Multi-threaded-NET-TCP-Server-Examples
*/
namespace BlinkAnalysis
{
	using namespace System;
	using namespace System::IO;
	using namespace System::Net;
	using namespace System::Net::Sockets;
	using namespace System::Text;
	using namespace System::Collections;
	using namespace System::Threading;

	/**
	 * Class that manages the TCP listener and creates new  
	 * StreamHandlers as clients connect \n
	 * \n
	 * Note: this class is unmanaged to try and avoid overhead
	 * moving from unmanaged to managed code during addframe
	 */
	public class StreamingManager
	{

	private:
		StreamingManager();
		~StreamingManager(void);
		StreamingManager(StreamingManager const&);
		StreamingManager& operator=(StreamingManager const&);
		static StreamingManager* m_pInstance;

		static bool streaming;
		gcroot<IPAddress^> address;
		int portNum;
		gcroot<TcpListener^> listener;
		static bool saveData;
		static std::string folderPath;
		static gcroot<Object^> sync;

		// list of clients connected to server
		static gcroot<ArrayList^> ClientSockets;
		static bool ContinueReclaim;
		// garbage collection for clients
		static gcroot<Thread^> ThreadReclaim ;
		static gcroot<Thread^> ThreadListen ;

		// buffer to store frames, since streaming usually
		// can't keep up to 60 FPS as generated by 
		// OutputManager
		static std::queue<std::string> frameBuffer;
		static const int MAX_BUFFER_SIZE = 100;
		static bool streamFrames;

		static void Reclaim();
		static void Listen();
		static void streamFrame(void*);

	public:

		static StreamingManager* getInstance() {
			if(!m_pInstance) m_pInstance = new StreamingManager();
			return m_pInstance;
		}

		bool setIPAddress(const char* addr);
		String^ getIPAddress();

		void setPortNumber(int port) {
			portNum = port;
		}
		int getPortNumber() {
			return portNum;
		}

		void setSaveData(bool save) {
			saveData = save;
		}
		bool getSaveData() {
			return saveData;
		}

		void setFolderPath(std::string path) {
			folderPath = path;
		}
		std::string getFolderPath() {
			return folderPath;
		}

		bool isStreaming() { return this->streaming; }
		void startStreaming();
		void stopStreaming();
		static void addFrame(std::string frame);

	};
}

#endif
