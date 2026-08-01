#pragma once
#include "lab2/MockFileHandle.hpp"
#include "lab2/MockSocketHandle.hpp"
#include <cstdint>
#include <iostream>

namespace lab2
{
	class DatabaseNode
	{
	public:
		DatabaseNode(const std::string& cache_path, int64_t port) : cache_file(cache_path), socket(port)
		{
			std::cout << "[DatabaseNode] Successful initialization with name path '"<< cache_path << "' and port '"<< port << "'.\n";
		};
	private:
		lab2::MockFileHandle cache_file;
		lab2::MockSocketHandle socket;
	};
}