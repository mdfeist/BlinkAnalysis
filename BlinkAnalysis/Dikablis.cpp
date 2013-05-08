#include "StdAfx.h"
#include <Windows.h>
#include <process.h> 

#include "Dikablis.h"
#include "MainFormController.h"

#include "Split.h"

#include "TCPClientListener.h"

std::string ip_address = "127.0.0.1";
std::string port = "2002";

TCPClientListener *client;

bool serverStarted = false;

void Dikablis::connectToDikablis(std::string ip, std::string p)
{
	ip_address = ip;
	port = p;

	startServer();
}

void Dikablis::setIPAddress(std::string ip) {
	ip_address = ip;
}

void Dikablis::setPort(std::string p) {
	port = p;
}

void message(std::string msg) {
	MainFormController::getInstance()->dikablisOutputLog(msg);
}

void recieved(std::string msg) {
	Split split(msg, "\t", true);

	Dikablis::journal_struct journal;

	if (split.size() >= 20) {
		sscanf_s(split[0].c_str(), "J%d", &journal.index);
		sscanf_s(split[1].c_str(), "%d", &journal.timestamp);
		sscanf_s(split[2].c_str(), "%d", &journal.eyeroihoriz);
		sscanf_s(split[3].c_str(), "%d", &journal.eyeroivert);
		sscanf_s(split[4].c_str(), "%d", &journal.eyeroizoomx);
		sscanf_s(split[5].c_str(), "%d", &journal.eyeroizoomy);

		int olinecalib, eye_valid;
		sscanf_s(split[8].c_str(), "%d", &olinecalib);
		sscanf_s(split[9].c_str(), "%d", &eye_valid);

		if (olinecalib == 1)
			journal.olinecalib = true;
		else
			journal.olinecalib = false;

		if (eye_valid == 1)
			journal.eye_valid = true;
		else
			journal.eye_valid = false;

		sscanf_s(split[10].c_str(), "%d", &journal.eye_x);
		sscanf_s(split[11].c_str(), "%d", &journal.eye_y);
		sscanf_s(split[15].c_str(), "%d", &journal.field_x);
		sscanf_s(split[16].c_str(), "%d", &journal.field_y);
	}

	MainFormController::getInstance()->dikablisMessage(journal);
}

void createServerThread(void) {
	if (!client)
		client = new TCPClientListener();

	client->messageCallback(message);
	client->recievedCallback(recieved);
	
	client->connectTo(ip_address, port);

	// Connection Finished
	serverStarted = false;
}

void Dikablis::stopServer() {
	if (client)
	{
		if (client->isRunning())
		{
			serverStarted = false;

			if (client)
				client->stop();
		}
	}
}

void Dikablis::startServer() {
	if (serverStarted) {
		message("Already Connected to Dikablis\n");
		return;
	}

	// Flag to indicate that server was started
	serverStarted = true;

	//Create Thread
	DWORD   dwThreadId;

	HANDLE  hThread = CreateThread( 
		NULL,												// default security attributes
		0,													// use default stack size  
		(LPTHREAD_START_ROUTINE)createServerThread,			// thread function name
		NULL,												// argument to thread function 
		CREATE_SUSPENDED,									// use default creation flags 
		&dwThreadId);										// returns the thread identifier 

	SetThreadPriority(hThread, THREAD_MODE_BACKGROUND_BEGIN);
	ResumeThread(hThread);

	if (hThread == NULL) 
	{
		printf("Thread could not be created.\n");
	}
}