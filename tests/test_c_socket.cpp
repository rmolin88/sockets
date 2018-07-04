#include <gtest/gtest.h>

#include "c_socket.hpp"

TEST(C_Socket, OpenSocket)
{
	c_socket socket;
	EXPECT_EQ(8, socket.connect(8888));
	EXPECT_EQ(-1, socket.connect(-1));
}
