#ifndef STREAMHANDLER_H
#define STREAMHANDLER_H

#include <string>
#include <queue>

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
	 * Handles a single client socket for streaming
	 */
	public ref class StreamHandler {

		// socket opened to client
		TcpClient^ ClientSocket ;
		bool ContinueProcess;
		bool streamData;
		// thread for listening to client commands
		Thread^ ClientThread ;
		int ClientNumber;
		ASCIIEncoding^ ascii;
		Generic::Queue<array<Byte>^> frames;
		Thread^ StreamThread;
		Object^ sync;
		StreamWriter^ currentStream;
		int nextFileID;
		bool writeReady;
		array<Byte>^ lastFrame;
		bool saveData;

	private:
		// if socket exception, test if client still responsive
		bool TestConnection();
		// stream static data header
		void streamHeader();
		// stream most recent frame of data
		// only if data is being saved, not streamed
		void streamLast();
		// main looping thread
		void Process();
		void Stream();

		void openWriter();
		void closeWriter();

	public:
		StreamHandler (TcpClient^ ClientSocket, int ClientNumber);
		~StreamHandler() {  }

		void Start();

		void Stop();

		bool Alive();

		bool getStreamData() { return streamData; }
		void addFrame(std::string frame, bool save);
	};

		
	public ref class FrameObject
	{
	public:
		FrameObject(StreamHandler^ h, String^ str)
		{ handler = h; frame = str; }
		StreamHandler^ handler;
		String^ frame;
	};
}

#endif