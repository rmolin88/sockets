#include <iostream>
#include <glog/logging.h>

#include "c_socket.hpp"

int c_socket_server::connect(std::string_view address, int port)
{
	if (s_id > -1)
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

	s_add.sin_port = port;

	if ((ptrp = getprotobyname(PROTOCOL_NAME.data())) == nullptr)
	{
		LOG(ERROR) << "Failed to get protocol by name\n";
		return -3;
	}

	std::cout << "ptrp->p_proto = " << ptrp->p_proto << std::endl;

	if ((s_id = socket(PF_INET, SOCK_STREAM, ptrp->p_proto)) < 0)
	{
		LOG(ERROR) << "Failed to create socket: s_id = " << s_id << "\n";
		return -4;
	}

	if (listen(s_id, SOMAXCONN) < 0)
	{
		LOG(ERROR) << "Failed to listen\n";
		return -5;
	}

	return 1;
}

void c_socket_server::loop(void)
{
	socklen_t c_add_len = sizeof(c_add);
	int soc_id = -1;

	if (s_id < 0)
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
		// if ((soc_id = accept(s_id)))
	}
}
