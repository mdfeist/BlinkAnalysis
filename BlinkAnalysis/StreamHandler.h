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

		TcpClient^ ClientSocket ;
		bool ContinueProcess;
		bool streamData;
		int dataCount;
		Thread^ ClientThread ;
		Thread^ DataThread;
		int ClientNumber;
		ASCIIEncoding^ ascii;


	private:
		bool TestConnection();
		
		void streamHeader();

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