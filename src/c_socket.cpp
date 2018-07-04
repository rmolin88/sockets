#include "c_socket.hpp"

#include <iostream>

int c_socket::connect(uint16_t port)
{
	if (port <= 0)
	{
		return -1;
	}

	std::cout << "All well so far" << std::endl;
	return 8;
}
