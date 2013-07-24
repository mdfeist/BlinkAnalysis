#ifndef STREAMHANDLER_H
#define STREAMHANDLER_H

#include <string>

namespace BlinkAnalysis
{
	using namespace System;
	using namespace System::IO;
	using namespace System::Net;
	using namespace System::Net::Sockets;
	using namespace System::Text;
	using namespace System::Collections;
	using namespace System::Threading;

	public ref class StreamHandler {

		// socket opened to client
		TcpClient^ ClientSocket ;
		bool ContinueProcess;
		bool streamData;
		// thread for listening to client commands
		Thread^ ClientThread ;
		int ClientNumber;
		ASCIIEncoding^ ascii;


	private:
		// if socket exception, test if client still responsive
		bool TestConnection();
		// stream static data header
		void streamHeader();
		// main looping thread
		void Process();

	public:
		StreamHandler (TcpClient^ ClientSocket, int ClientNumber);

		void Start();

		void Stop();

		bool Alive();

		bool getStreamData() { return streamData; }
		void addFrame(String^ frame);
		void addFrameAsync(String^ frame);

	};
}

#endif