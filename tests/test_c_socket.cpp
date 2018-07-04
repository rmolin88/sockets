#include <gtest/gtest.h>
#include <glog/logging.h>

#include "c_socket.hpp"

TEST(CSocketServer, OpenSocket)
{
	google::InitGoogleLogging("test_c_socket");

	c_socket_server socket;
	EXPECT_EQ(1, socket.connect(8888));

	// Socket already connected
	EXPECT_EQ(0, socket.connect(-1));
}

TEST(CSocketServer, BadSocketPort)
{
	c_socket_server socket;
	EXPECT_EQ(-1, socket.connect(-1));
}
