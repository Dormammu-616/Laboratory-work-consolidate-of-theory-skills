#pragma once
#include <cstdint>
#include <string>
#include <iostream>

namespace lab2
{
	class MockFileHandle
	{
	public:
		MockFileHandle(const std::string& file_name)
		{
			std::cout << "\t[MockFileHandle] Opening file: '" << file_name << "'.\n";
			file_id = 100;
		}
		~MockFileHandle()
		{
			if (file_id != -1)
			{
				std::cout << "\t[~MockFileHandle] Closing file_id: '" << file_id << "'.\n";
			}
		}
		MockFileHandle(const MockFileHandle&) = delete;
		MockFileHandle& operator=(const MockFileHandle&) = delete;
		MockFileHandle& operator=(MockFileHandle&& other) noexcept
		{
			if (this != &other)
			{
				file_id = std::exchange(other.file_id, -1);
				std::cout << "\t[MockFileHandle] A move operation was performed using operator=(const MockFileHandle&&).\n";
			}

			return *this;
		}
	private:
		int64_t file_id{ -1 };
	};
}