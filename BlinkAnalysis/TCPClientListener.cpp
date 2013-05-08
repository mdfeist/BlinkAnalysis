#include "StdAfx.h"
#include "TCPClientListener.h"

#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>
#include <stdlib.h>

// Need to link with Ws2_32.lib, Mswsock.lib, and Advapi32.lib
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")

#define DEFAULT_BUFLEN 6505

TCPClientListener::TCPClientListener(void)
{
	this->running = false;
}

int TCPClientListener::connectTo(std::string& ip_address, std::string& port)
{
	WSADATA wsaData;
    SOCKET ConnectSocket = INVALID_SOCKET;
    struct addrinfo *result = NULL, *ptr = NULL, hints;

	char recvbuf[DEFAULT_BUFLEN];
    int iResult;
    int recvbuflen = DEFAULT_BUFLEN;

	char strbuf[1024];

	if (message) {
		sprintf_s(strbuf, "Connecting to Server...\nAddress: %s\nPort: %s\n", ip_address.c_str(), port.c_str());
		message(strbuf);
	}

	// Initialize Winsock
    iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
    if (iResult != 0) {
		if (message) {
			sprintf_s(strbuf, "WSAStartup failed with error: %d\n", iResult);
			message(strbuf);
		}
        return 1;
    }
 
    ZeroMemory( &hints, sizeof(hints) );
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
 
    // Resolve the server address and port
    iResult = getaddrinfo( ip_address.c_str(), port.c_str(), &hints, &result);
	
    if ( iResult != 0 ) {
		if (message) {
			sprintf_s(strbuf, "getaddrinfo failed with error: %d\n", iResult);
			message(strbuf);
		}
        WSACleanup();
        return 1;
    }

	// Attempt to connect to an address until one succeeds
    for(ptr=result; ptr != NULL ;ptr=ptr->ai_next) {
 
        // Create a SOCKET for connecting to server
        ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype, 
            ptr->ai_protocol);
        if (ConnectSocket == INVALID_SOCKET) {
			if (message) {
				sprintf_s(strbuf, "socket failed with error: %d\n", WSAGetLastError());
				message(strbuf);
			}
            WSACleanup();
            return 1;
        }
 
        // Connect to server.
        iResult = connect( ConnectSocket, ptr->ai_addr, (int)ptr->ai_addrlen);
        if (iResult == SOCKET_ERROR) {
            closesocket(ConnectSocket);
            ConnectSocket = INVALID_SOCKET;
            continue;
        }
        break;
    }
 
    freeaddrinfo(result);

    if (ConnectSocket == INVALID_SOCKET) {
		if (message) {
			sprintf_s(strbuf, "Unable to connect to server!\n");
			message(strbuf);
		}
        WSACleanup();
        return 1;
    }

	this->running = true;

	if (message) {
		sprintf_s(strbuf, "Successfully connected to server.");
		message(strbuf);
	}
	
	while (this->running) {
		ZeroMemory(recvbuf,6501);
		iResult = recv(ConnectSocket, recvbuf, 6500, 0);

		if ( iResult > 0 ) {
			//printf("\nBytes received: %d\n\n", iResult);
			if (recieved)
				recieved(recvbuf);

		}
		else if ( iResult == 0 ) 
		{
			if (message) {
				sprintf_s(strbuf, "\nConnection closed\n");
				message(strbuf);
			}
			break;
		}
		else
		{
			if (message) {
				sprintf_s(strbuf, "recv failed with error: %d\n", WSAGetLastError());
				message(strbuf);
			}
			break;
		}
	} 

	this->running = false;

	// shutdown the connection since no more data will be sent
	iResult = shutdown(ConnectSocket, SD_SEND);
	if (iResult == SOCKET_ERROR) {
		if (message) {
			sprintf_s(strbuf, "shutdown failed with error: %d\n", WSAGetLastError());
			message(strbuf);
		}
		closesocket(ConnectSocket);
		WSACleanup();
		return 1;
	}

	if (message) {
		sprintf_s(strbuf, "\nClosing Connection...\n");
		message(strbuf);
	}

    // cleanup
    closesocket(ConnectSocket);
    WSACleanup();

	if (message) {
		sprintf_s(strbuf, "\nConnection Closed\n");
		message(strbuf);
	}

	return 0;
}
