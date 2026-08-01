#pragma once
#include <cstdint>
#include <iostream>

namespace lab2
{
	class MockSocketHandle
	{
	public:
		MockSocketHandle(int64_t port)
		{
			std::cout << "\t\t[MockSocketHandle] Attempting to bind port: '" << port << "'\n";

			if (port == 80)
			{
				throw std::runtime_error("Port 80 is already in use!");
			}

			socket_id = 200;
			std::cout << "\t\t[MockSocketHandle] Successful binding to port '" << socket_id << "'\n";
		}
		~MockSocketHandle()
		{
			if (socket_id != -1)
			{
				std::cout << "\t\t[~MockSocketHandle] Socket closed!\n";
			}
		}

		MockSocketHandle(MockSocketHandle&) = delete;
		MockSocketHandle& operator=(const MockSocketHandle&) = delete;
		MockSocketHandle& operator=(MockSocketHandle&& other) noexcept
		{
			if (this != &other)
			{
				socket_id = std::exchange(other.socket_id, -1);
				std::cout << "\t\t[MockSocketHandle] A move operation was performed using operator=(const MockSocketHandle&&).\n";
			}

			return *this;
		}
	private:
		int64_t socket_id{ -1 };
	};
}