#include <iostream>
#include <glog/logging.h>
#include <string.h>
#include <string>
#include <errno.h>

#include "c_socket.hpp"

int c_socket_server::connect(const std::string &address, int port)
{
	if (descriptor > -1)
	{
		LOG(WARNING) << "Socket already initialized and connected";
		return 0;
	}

	if (address.empty())
	{
		LOG(ERROR) << "Bad input address is empty\n";
		return -1;
	}

	if (port <= 0)
	{
		LOG(ERROR) << "Bad input port: " << port << "\n";
		return -2;
	}

	struct addrinfo hints, *add_info = nullptr;
	memset((char *)&add_info,0,sizeof(add_info));        /*clear sockaddr structure*/ 
	memset((char *)&hints,0,sizeof(hints));        /*clear sockaddr structure*/ 

	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = 0;

	if (getaddrinfo(address.c_str(), std::to_string(port).c_str(), &hints, &add_info) != 0)
	{
		LOG(ERROR) << "Failed getaddrinfo: \"" << strerror(errno) << "\"\n";
		return -3;
	}

	if ((descriptor = socket(PF_INET, SOCK_STREAM, 0)) < 0)
	{
		LOG(ERROR) << "Failed to create socket: descriptor = " << descriptor << "\n";
		return -4;
	}

	if (listen(descriptor, SOMAXCONN) < 0)
	{
		LOG(ERROR) << "Failed to listen\n";
		return -5;
	}

	return 1;
}

void c_socket_server::loop(void)
{
	socklen_t c_add_len = 0;
	int soc_id = -1;

	if (descriptor < 0)
	{
		LOG(ERROR) << "Socket has being connected\n";
		return;
	}

	if (c_add_len < 1)
	{
		LOG(ERROR) << "Failed to get size of sockaddr_in c_add\n";
		return;
	}

	while (1)
	{
		// soc_id = -1;
		// if ((soc_id = accept(descriptor)))
	}
}
