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

class c_socket
{
	// Obtained from /etc/protocols
	const int PROTOCOL_NUMBER = 6;

	struct hostent *ptrh;          /*pointer to a host table entry*/
	struct protoent *ptrp;      /*pointer to a protocol table entry*/
	struct sockaddr_in sad;      /*structure to hold server’s address*/
	struct sockaddr_in cad;      /*structure to hold client’s address*/ 

public:

	c_socket()
		: ptrh(nullptr), ptrp(nullptr) 
	{
		memset((char *)&sad,0,sizeof(sad));        /*clear sockaddr structure*/ 
		sad.sin_family = AF_INET;                  /*set family to Internet v4*/
		sad.sin_addr.s_addr = INADDR_ANY;          /*set the local IP address*/
	}

	int connect(uint16_t port);
};

#endif
