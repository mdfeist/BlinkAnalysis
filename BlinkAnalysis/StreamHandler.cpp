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
		sync = gcnew Object();
		nextFileID = 0;
		writeReady = false;
		saveData = false;
		lastFrame = gcnew array<Byte>(1);
	}


	// start listening for client commands
	void StreamHandler::Start() {
		if (ContinueProcess) return; // already started
		ContinueProcess = true ;
		ClientThread = gcnew Thread ( gcnew ThreadStart(this, &StreamHandler::Process) ) ;
		ClientThread->Start() ;
	}

	void StreamHandler::Stop() 	{
		if (!ContinueProcess) return; // already stopped
		ContinueProcess = false ;
		streamData = false;
		if ( ClientThread && ClientThread->IsAlive )
			ClientThread->Join() ;
		int count = frames.Count;
		frames.Clear();
	}

	bool StreamHandler::Alive() {
		return  ( ClientThread && ClientThread->IsAlive  );
	}

	void StreamHandler::openWriter()
	{
		if (writeReady) return;
		Monitor::Enter(sync);

		DateTime time = DateTime::Now;
		String^ file = gcnew String(StreamingManager::getInstance()->getFolderPath().c_str());
		file += "\\cl" + ClientNumber.ToString() + "_" + time.ToString("ddMMMyyyy") + "_" 
			+ nextFileID++ + "_" + time.ToString("HHmmss") + ".xml";
		currentStream = gcnew StreamWriter(file);
		currentStream->Write("<StaticData>\n");

		currentStream->Write(gcnew String(AppData::getInstance()->getRigidBodyStaticData().c_str()));
		currentStream->Write(gcnew String(WorldManager::getInstance()->getWorldStaticData().c_str()));

		currentStream->Write("</StaticData>\n");
		currentStream->Write("<Frames>\n");
		
		writeReady = true;
		Monitor::Exit(sync);
	}

	void StreamHandler::closeWriter()
	{
		if (!writeReady) return;
		Monitor::Enter(sync);
		writeReady = false;
		currentStream->Write("</Frames>\n");
		currentStream->Close();
		Monitor::Exit(sync);
	}

	void StreamHandler::addFrame(std::string frame, bool save)
	{
		saveData = save;
		if (saveData || !streamData)
		{
			try 
			{
				Monitor::Enter(sync);
				if (streamData && writeReady)
					currentStream->Write(gcnew String(frame.c_str()));
				int len = frame.size();
				lastFrame = gcnew array<Byte>(len);
				System::Runtime::InteropServices::Marshal::Copy(IntPtr(&frame[0]), lastFrame, 0, len);
				Monitor::Exit(sync);
			}
			catch (Exception^ ex)
			{
				Console::WriteLine("Error writing file: {0}", ex->ToString());
			}
		}
		else
		{
			int len = frame.size();
			array<Byte>^ response = gcnew array<Byte>(len);
			System::Runtime::InteropServices::Marshal::Copy(IntPtr(&frame[0]), response, 0, len);
			Monitor::Enter(sync);
			frames.Enqueue(response);
			Monitor::Exit(sync);
			if (!StreamThread || !StreamThread->IsAlive)
			{
				StreamThread = gcnew Thread(gcnew ThreadStart(this, &StreamHandler::Stream));
				StreamThread->Start();
			}
		}
	}

	void StreamHandler::Stream()
	{
		NetworkStream^ stream;
		try
		{
			stream = ClientSocket->GetStream();
		}
		catch(Exception^ ex)
		{
			Console::WriteLine("Exception add frame: {0}", ex->Message);
			return;
		}
		while (streamData || frames.Count > 0)
		{
			if (frames.Count > 0)
			{
				try
				{
					Monitor::Enter(sync);
					array<Byte>^ response = frames.Dequeue();
					Monitor::Exit(sync);
					stream->Write(response, 0, response->Length);
				}
				catch(Exception^ ex)
				{
					Console::WriteLine("Exception add frame: {0}", ex->Message);
					break;
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
	void StreamHandler::streamLast() 
	{
		try
		{
			Monitor::Enter(sync);
			ClientSocket->GetStream()->Write(lastFrame, 0, lastFrame->Length);
			Monitor::Exit(sync);
		}
		catch(Exception^ ex)
		{
			Console::WriteLine("Exception stream last frame: {0}", ex->Message);
		}
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
		int bufferSize = ClientSocket->ReceiveBufferSize;

		// Data buffer for incoming data.
		array<Byte>^ bytes = gcnew array<Byte>(bufferSize);

		if ( ClientSocket ) {
			ClientSocket->ReceiveTimeout = 1000 ; // 1000 miliseconds

			while ( ContinueProcess ) {
				Array::Clear(bytes,0,bytes->Length);
				try {
					// this will throw a socketException if the client does not send
					// any data within the ReceiveTimeout timeframe
					if (ClientSocket->GetStream()->DataAvailable)
					{
						int BytesRead = ClientSocket->GetStream()->Read(bytes, 0, bufferSize);

						for (int i = 0; i < BytesRead; i++)
						{
							switch(bytes[i])
							{
							case 'q':
								ContinueProcess = false;
								break;
							case 's':
								streamData = true;
								if (saveData) openWriter();
								break;
							case 'd':
								streamData = false;
								if (saveData) closeWriter();
								break;
							case 'h':
								streamHeader();
								break;
							case 'l':
								if (saveData || !streamData) 
									streamLast();
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

			if (StreamThread && StreamThread->IsAlive)
				StreamThread->Join();

			ClientSocket->Close();
			streamData = false;
			closeWriter();
		}
	}  // Process()
}