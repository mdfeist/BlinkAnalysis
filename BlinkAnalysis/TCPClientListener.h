/**
 * TCPClientListener.h
 * Created By: Michael Feist
 *
 * An simple abstract TCP client.
 */
#pragma once
#include <string>

class TCPClientListener
{
private:
	// Message Callback Function
	void (*message)(std::string);
	// Recieved Callback Function
	void (*recieved)(std::string);

	// Flag to tell if the client is running and connected
	bool running;

public:
	TCPClientListener(void);

	// Set a pointer to the message callback.
	// Used to give updates on the status of
	// the client.
	void messageCallback(void (*f)(std::string)) {
		message = f;
	}

	// Set a pointer to the received callback.
	// This is called when the client receives
	// new data from the server.
	void recievedCallback(void (*f)(std::string)) {
		recieved = f;
	}

	// Connect to the server
	int connectTo(std::string& ip_address, std::string& port);
	// Checks if the client is connected and running
	bool isRunning() { return running; }
	// Stop the client and close the connection
	void stop() { running = false; }
};

