/**
 * Dikablis.cpp
 * Created By: Michael Feist
 *
 * Handles the eye tracking from the Dikablis Recorder.
 */
#include "StdAfx.h"
#include <Windows.h>
#include <process.h> 

#include "Dikablis.h"
#include "MainFormController.h"

#include "Split.h"

#include "TCPClientListener.h"

// Local Variables
std::string ip_address = "127.0.0.1";
std::string port = "2002";

TCPClientListener *client;

bool serverStarted = false;

// Connect to the Dikablis Recorder
void Dikablis::connectToDikablis(std::string ip, std::string p)
{
	// Set the ip address
	ip_address = ip;
	// Set the slave port
	port = p;

	// Start the connection
	startServer();
}

// Set the ip address of the Dikablis Recorder
void Dikablis::setIPAddress(std::string ip) {
	ip_address = ip;
}

// Set the slave port of the Dikablis Recorder
void Dikablis::setPort(std::string p) {
	port = p;
}

// Send a message to the Dikablis Output view in the MainForm
void message(std::string msg) {
	MainFormController::getInstance()->dikablisOutputLog(msg);
}

// Send a the received to the MainForm
void recieved(std::string msg) {
	// Split data based on tabs.
	// Parameter 3 tells us to delete the last return if any.
	Split split(msg, "\t", true);

	// Create a new journal_struct to hold the new journal info
	Dikablis::journal_struct journal;

	// Check if data is correct we should have at least 20 columns
	if (split.size() >= 20) {
		// Parse strings and retrieve the journal data
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

	// Pass the journal information to the MainForm so it can be displayed
	MainFormController::getInstance()->dikablisMessage(journal);
}

// Start connection with server on a new thread
void createServerThread(void *) {
	// Check if TCP client is already created
	if (!client)
		client = new TCPClientListener();

	// Attach callbacks
	client->messageCallback(message);
	client->recievedCallback(recieved);
	
	// Connect to the given ip address and port
	client->connectTo(ip_address, port);

	// Connection Finished
	serverStarted = false;

	// Terminate thread
    _endthread();
}

// Server
void Dikablis::stopServer() {
	// Check if client exists. If not then do nothing.
	if (client)
	{
		// Check if client is connected and running.
		if (client->isRunning())
		{
			// Set flag that client is running to false
			serverStarted = false;

			// Stop Client
			client->stop();
		}
	}
}

// Start a new connection with the Dikablis Recorder
void Dikablis::startServer() {
	// Check if a connection already exists
	if (serverStarted) {
		message("Already Connected to Dikablis\n");
		return;
	}

	// Flag to indicate that server was started
	serverStarted = true;

	// Start server on new thread
	_beginthread( createServerThread, 0, NULL );
}