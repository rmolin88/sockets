#ifndef C_SOCKET_HPP
#define C_SOCKET_HPP

#ifndef unix
#define WIN32
#include <windows.h>
#include <winsock.h>
#else
#define closesocket close
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#include <arpa/inet.h>
#endif

#include <stdio.h>
#include <string.h>

class c_socket_server
{
	// Obtained from /etc/protocols
	const int PROTOCOL_NUMBER = 6;
	const std::string_view PROTOCOL_NAME = "tcp";

	int descriptor;

public:

	c_socket_server()
		: descriptor(-1) {}

	int connect(const std::string &address, int port);
	void loop(void);
};

#endif
