#include "stdafx.h"

#include "StreamHandler.h"
#include "AppData.h"
#include "WorldManager.h"
#include "StreamingManager.h"

namespace BlinkAnalysis
{
	StreamHandler::StreamHandler(TcpClient^ ClientSocket, int ClientNumber) {
		ContinueProcess = false;
		this->ClientSocket = ClientSocket;
		this->ClientNumber = ClientNumber;
		ascii = gcnew ASCIIEncoding();
		frames = new std::queue<std::string>();
		sync = gcnew Object();
	}


	// start listening for client commands
	void StreamHandler::Start() {
		ContinueProcess = true ;
		ClientThread = gcnew Thread ( gcnew ThreadStart(this, &StreamHandler::Process) ) ;
		ClientThread->Start() ;
	}

	void StreamHandler::Stop() 	{
		ContinueProcess = false ;
		if ( ClientThread && ClientThread->IsAlive )
			ClientThread->Join() ;
		if (StreamThread && StreamThread->IsAlive)
			StreamThread->Join();
	}

	bool StreamHandler::Alive() {
		return  ( ClientThread && ClientThread->IsAlive  );
	}

	void StreamHandler::addFrame(std::string frame)
	{
		Monitor::Enter(sync);
		frames->push(frame);
		Monitor::Exit(sync);
		if (!StreamThread)
		{
			StreamThread = gcnew Thread(gcnew ThreadStart(this, &StreamHandler::Stream));
			StreamThread->Start();
		}
	}

	void StreamHandler::Stream()
	{
		while (streamData)
		{
			int count = frames->size();
			if (count > 0)
			{
				try
				{
					std::string str = frames->front();
					array<Byte>^ response = gcnew array<Byte>(str.size());
					System::Runtime::InteropServices::Marshal::Copy(IntPtr(&str[0]), response, 0, str.size());
					ClientSocket->GetStream()->Write(response, 0, response->Length);
					Monitor::Enter(sync);
					frames->pop();
					Monitor::Exit(sync);
				}
				catch(Exception^ ex)
				{
					Console::WriteLine("Exception add frame: {0}", ex->Message);
				}
			}
		}
	}

	// can only check if client alive by trying to send it something
	bool StreamHandler::TestConnection()
	{
		try
		{
			array<Byte>^ tmp = gcnew array<Byte>(1);
			ClientSocket->GetStream()->Write(tmp, 0, 0);
			return ClientSocket->Connected;
		}
		catch (IOException^)
		{
			Console::WriteLine( "Conection is broken!");
			return false;
		}
		catch(InvalidOperationException^)
		{
			Console::WriteLine( "Conection is broken!");
			return false;
		}
		return false;
	}

	void StreamHandler::streamHeader() 
	{
		try
		{
			ClientHandler* client = AppData::getInstance()->getClient();
			if (!client) return;

			String^ header = "<StaticData>\n";

			header += gcnew String(AppData::getInstance()->getRigidBodyStaticData().c_str());
			header += gcnew String(WorldManager::getInstance()->getWorldStaticData().c_str());

			header += "</StaticData>\n";

			array<Byte>^ response = ascii->GetBytes(header);
			ClientSocket->GetStream()->Write(response, 0, response->Length);
		}
		catch(Exception^ ex)
		{
			Console::WriteLine("Exception stream header: {0}", ex->Message);
		}
	}

	// main thread
	// listens for commands from client
	void StreamHandler::Process() {

		// Incoming data from the client.
		String^ data;
		int bufferSize = ClientSocket->ReceiveBufferSize;

		// Data buffer for incoming data.
		array<Byte>^ bytes = gcnew array<Byte>(bufferSize);

		if ( ClientSocket ) {
			NetworkStream^ networkStream = ClientSocket->GetStream();
			ClientSocket->ReceiveTimeout = 1000 ; // 1000 miliseconds

			while ( ContinueProcess ) {
				Array::Clear(bytes,0,bytes->Length);
				try {
					// this will throw a socketException if the client does not send
					// any data within the ReceiveTimeout timeframe
					int BytesRead = networkStream->Read(bytes, 0, bufferSize);
					if ( BytesRead > 0 ) {
						data = ascii->GetString(bytes, 0, BytesRead);

						for (int i = 0; i < data->Length; i++)
						{
							switch (data[i])
							{
							case 'q':
								ContinueProcess = false;
								break;
							case 's':
								streamData = true;
								break;
							case 'd':
								streamData = false;
								break;
							case 'h':
								streamHeader();
								break;
							}
						}
					}
					else
					{
						// client disconnected
						if(!TestConnection())
							break ;
					}
				}
				catch  ( SocketException^ ) {
					Console::WriteLine( "Conection is broken!");
					break ;
				}
				catch  ( IOException^ ) {
					if(!TestConnection())
						break ;
				} // Timeout
				Thread::Sleep(200);
			} // while ( ContinueProcess )
			networkStream->Close();
			ClientSocket->Close();
			streamData = false;
		}
	}  // Process()
}