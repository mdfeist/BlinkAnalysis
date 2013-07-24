#include "stdafx.h"

#include "StreamHandler.h"
#include "AppData.h"

namespace BlinkAnalysis
{
	StreamHandler::StreamHandler(TcpClient^ ClientSocket, int ClientNumber) {
		ContinueProcess = false;
		this->ClientSocket = ClientSocket;
		this->ClientNumber = ClientNumber;
		ascii = gcnew ASCIIEncoding();
	}


	void StreamHandler::Start() {
		ContinueProcess = true ;
		ClientThread = gcnew Thread ( gcnew ThreadStart(this, &StreamHandler::Process) ) ;
		ClientThread->Start() ;
	}

	void StreamHandler::Stop() 	{
		ContinueProcess = false ;
		if ( ClientThread && ClientThread->IsAlive )
			ClientThread->Join() ;
	}

	bool StreamHandler::Alive() {
		return  ( ClientThread && ClientThread->IsAlive  );
	}

	void StreamHandler::addFrameAsync(String^ frame)
	{
		try
		{
			array<Byte>^ response = ascii->GetBytes(frame);
			ClientSocket->GetStream()->Write(response, 0, response->Length);
		}
		catch(Exception^ ex)
		{
			Console::WriteLine("Exception add frame: {0}", ex->Message);
		}
	}

	delegate void AddFrameAsyncCaller(String^ frame);

	void StreamHandler::addFrame(String^ frame)
	{
		AddFrameAsyncCaller^ call = gcnew AddFrameAsyncCaller(this, &StreamHandler::addFrameAsync);
		call->BeginInvoke(frame, nullptr, nullptr);
	}

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

			// Lock the ClientHandler so data isn't changed
			// by another thread.
			if (!client->lock())
				return;

			std::map<int, RigidBody*>* rigidBodies = client->getRigidBodyMap();

			for (RigidBody_iterator it = rigidBodies->begin(); it != rigidBodies->end(); ++it) {
				header += "<RigidBody ";
				header += "id=\"" + it->second->getID() + "\" ";
				header += "name=\"" + gcnew String(it->second->getName()) + "\" ";
				header += "/>\n";
			}

			// Unlock the ClientHandler
			client->unlock();

			header += "</StaticData>\n";

			array<Byte>^ response = ascii->GetBytes(header);
			ClientSocket->GetStream()->Write(response, 0, response->Length);
		}
		catch(Exception^ ex)
		{
			Console::WriteLine("Exception stream header: {0}", ex->Message);
		}
	}

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
					int BytesRead = networkStream->Read(bytes, 0, bufferSize);
					if ( BytesRead > 0 ) {
						data = String::Concat(data, ascii->GetString(bytes, 0, BytesRead));
						int idx = data->IndexOf('\n');
						if (idx < 0)
							continue;

						data->Replace("\r","");
						array<String^>^ split = data->Split(gcnew array<wchar_t> {'\n'});
						int i;
						for (i = 0; i < split->Length-1; i++)
						{
							String^ command = split[i];

							// Show the data on the console.
							Console::WriteLine( "Text received : {0}", command);

							switch (command[0])
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
						data = split[i];
					}
					else
					{
						if(!TestConnection())
							break ;
					}
				}
				catch  ( IOException^ ) {
					if(!TestConnection())
						break ;
				} // Timeout
				catch  ( SocketException^ ) {
					Console::WriteLine( "Conection is broken!");
					break ;
				}
				Thread::Sleep(200) ;
			} // while ( ContinueProcess )
			networkStream->Close() ;
			ClientSocket->Close();			
		}
	}  // Process()
}