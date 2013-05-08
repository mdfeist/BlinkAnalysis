#pragma once
#include <string>

class TCPClientListener
{
private:
	// Message Callback Function
	void (*message)(std::string);
	// Recieved Callback Function
	void (*recieved)(std::string);

	bool running;

public:
	TCPClientListener(void);

	void messageCallback(void (*f)(std::string)) {
		message = f;
	}

	void recievedCallback(void (*f)(std::string)) {
		recieved = f;
	}

	int connectTo(std::string& ip_address, std::string& port);
	bool isRunning() { return running; }
	void stop() { running = false; }
};

