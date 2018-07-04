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
#include <string_view>

class c_socket_server
{
	// Obtained from /etc/protocols
	const int PROTOCOL_NUMBER = 6;
	const std::string_view PROTOCOL_NAME = "tcp";

	struct hostent *ptrh;          /*pointer to a host table entry*/
	struct protoent *ptrp;      /*pointer to a protocol table entry*/
	struct sockaddr_in s_add, c_add;      /*structure to hold server’s address*/

	int s_id;
	int port_num;

public:

	c_socket_server()
		: ptrh(nullptr), ptrp(nullptr), s_id(-1), port_num(-1)
	{
		memset((char *)&s_add,0,sizeof(s_add));        /*clear sockaddr structure*/ 
		s_add.sin_family = AF_INET;                  /*set family to Internet v4*/
		s_add.sin_addr.s_addr = INADDR_ANY;          /*set the local IP address*/
	}

	int connect(std::string_view address, int port);
	void loop(void);
};

#endif
