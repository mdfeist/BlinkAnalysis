#ifndef STREAMINGMANAGER_H
#define STREAMINGMANAGER_H

#include <vcclr.h>
#include <string>
#include <queue>
#include <Windows.h>

#include "StreamHandler.h"


/*
This and StreamHandler class are largely based on the code by Matthew YC So found here
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

	public class StreamingManager
	{

	private:
		StreamingManager();
		~StreamingManager(void);
		StreamingManager(StreamingManager const&);
		StreamingManager& operator=(StreamingManager const&);
		/*StreamingManager(const StreamingManager%) { 
			throw gcnew System::InvalidOperationException("singleton cannot be copy-constructed"); 
		}*/
		static StreamingManager* m_pInstance;

		bool streaming;
		gcroot<IPAddress^> address;
		int portNum;
		gcroot<TcpListener^> listener;

		static gcroot<ArrayList^> ClientSockets;
		static bool ContinueReclaim;
		static gcroot<Thread^> ThreadReclaim ;
		static gcroot<Thread^> ThreadListen ;

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

		bool setIPAddress(char* addr);
		void setPortNumber(int port);

		bool isStreaming() { return this->streaming; }
		void startStreaming();
		void stopStreaming();
		void addFrame(std::string frame);

	};
}

#endif
