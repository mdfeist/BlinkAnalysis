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

	StreamingManager::StreamingManager()
	{
		//address = (IPAddress^) Dns::GetHostEntry( "localhost" )->AddressList[ 0 ];
		//address = (IPAddress^) Dns::GetHostEntry( "PWS-CC-3" )->AddressList[ 0 ];
		setIPAddress("142.244.234.121");
		portNum = 10510;
		streaming = false;
	}

	void StreamingManager::Reclaim()  {
		while (ContinueReclaim) {
			Monitor::Enter(ClientSockets->SyncRoot);
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
				TcpClient^ handler = inst->listener->AcceptTcpClient();

				if (  handler )  {
					Console::WriteLine("Client#{0} accepted!", ++ClientNbr) ;
					// An incoming connection needs to be processed.
					Monitor::Enter(ClientSockets->SyncRoot);
					try
					{
						StreamHandler^ client = gcnew StreamHandler(handler, ClientNbr);
						int i = ClientSockets->Add( client ) ;
						((StreamHandler^) ClientSockets->default[i])->Start() ;
					}
					finally
					{
						Monitor::Exit(ClientSockets->SyncRoot);
					}
				}
				else 
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

	bool StreamingManager::setIPAddress(char* addr)
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

	void StreamingManager::setPortNumber(int port)
	{
		portNum = port;
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
			if (frameBuffer.size() > MAX_BUFFER_SIZE)
				frameBuffer.pop();

			frameBuffer.push(frame);
		}
	}

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
