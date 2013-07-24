#include "stdafx.h"

#include "StreamingManager.h"
#include <process.h>

namespace BlinkAnalysis
{
	StreamingManager* StreamingManager::m_pInstance = NULL;
	bool StreamingManager::ContinueReclaim = true;
	gcroot<Thread^> StreamingManager::ThreadReclaim = nullptr;
	gcroot<Thread^> StreamingManager::ThreadListen = nullptr;
	gcroot<ArrayList^> StreamingManager::ClientSockets = nullptr;
	bool StreamingManager::streamFrames = false;
	std::queue<std::string> StreamingManager::frameBuffer;

	// default to listen through localhost on port 10510
	StreamingManager::StreamingManager()
	{
		address = (IPAddress^) Dns::GetHostEntry( "localhost" )->AddressList[ 0 ];
		//setIPAddress("142.244.234.121");
		portNum = 10510;
		streaming = false;
	}

	void StreamingManager::Reclaim()  {
		while (ContinueReclaim) {
			Monitor::Enter(ClientSockets->SyncRoot); // Monitor is more lightweight than mutex lock
			try
			{
				for (int i = 0; i < ClientSockets->Count; i++)  {
					Object^ stream = ClientSockets->default[i];
					if ( !((StreamHandler^)stream)->Alive() )  {
						ClientSockets->RemoveAt(i);
						Console::WriteLine("A client left") ;
					}
				}
			}
			finally
			{
				Monitor::Exit(ClientSockets->SyncRoot);
			}
			Thread::Sleep(200) ;
		}
	}

	// TCP server listening for client connections
	void StreamingManager::Listen()
	{
		StreamingManager* inst = StreamingManager::getInstance();
		inst->listener = gcnew TcpListener(inst->address, inst->portNum);
		try {
			inst->listener->Start();

			int ClientNbr = 0 ;

			// Start listening for connections.
			Console::WriteLine("Waiting for a connection...");
			streamFrames = true;
			_beginthread(&StreamingManager::streamFrame, 0, NULL);

			while ( inst->streaming ) {
				// this blocks until exception or a client connects
				TcpClient^ handler = inst->listener->AcceptTcpClient();

				if (  handler )  {
					Console::WriteLine("Client#{0} accepted!", ++ClientNbr) ;
					// An incoming connection needs to be processed.
					Monitor::Enter(ClientSockets->SyncRoot);
					try
					{
						// add to client list and start client thread to listen for commands
						StreamHandler^ client = gcnew StreamHandler(handler, ClientNbr);
						int i = ClientSockets->Add( client ) ;
						((StreamHandler^) ClientSockets->default[i])->Start() ;
					}
					finally
					{
						Monitor::Exit(ClientSockets->SyncRoot);
					}
				}
				else // something's wrong
					break;                
			}

		} catch (Exception^ e) {
			Console::WriteLine(e->ToString());
		}
		finally {
			ContinueReclaim = false ;
			ThreadReclaim->Join() ;

			streamFrames = false;
			for (int i = 0; i < ClientSockets->Count; i++)  {
				( (StreamHandler^)ClientSockets->default[i] )->Stop();
			}
		}

		Console::WriteLine("\nHit enter to continue...");
		Console::Read();
	}

	bool StreamingManager::setIPAddress(const char* addr)
	{
		try {
			address = IPAddress::Parse(gcnew String(addr));
			return true;
		}
		catch (Exception^ ) {
			Console::WriteLine("Invalid IP address");
			return false;
		}
		return false;
	}
	
	String^ StreamingManager::getIPAddress()
	{
		return address->ToString();
	}

	void StreamingManager::startStreaming()
	{
		streaming = true;

		ClientSockets = gcnew ArrayList() ;

		ThreadListen = gcnew Thread( gcnew ThreadStart(StreamingManager::Listen) );
		ThreadListen->Start();

		ThreadReclaim = gcnew Thread( gcnew ThreadStart(StreamingManager::Reclaim) );
		ThreadReclaim->Start() ;
	}

	void StreamingManager::stopStreaming()
	{
		streaming = false;
		listener->Stop();
	}

	void StreamingManager::addFrame(std::string frame)
	{
		if (streamFrames)
		{
			// buffer overflowing, drop oldest frame
			if (frameBuffer.size() > MAX_BUFFER_SIZE)
				frameBuffer.pop();

			frameBuffer.push(frame);
		}
	}

	// stream frames in the buffer
	// placing in buffer means addFrame method will return quickly
	void StreamingManager::streamFrame(void*)
	{
		while (streamFrames)
		{
			if (!frameBuffer.empty())
			{
				String^ str = gcnew String(frameBuffer.front().c_str());
				frameBuffer.pop();

				Monitor::Enter(ClientSockets->SyncRoot);
				for (int i = 0; i < ClientSockets->Count; i++)  {
					StreamHandler^ client = (StreamHandler^)ClientSockets->default[i];
					// if client still alive and wants data streamed
					if( client->getStreamData() && client->Alive() )
					{
						client->addFrame(str);
					}
				}
				Monitor::Exit(ClientSockets->SyncRoot);
			}
		}
		_endthread();
	}

}
