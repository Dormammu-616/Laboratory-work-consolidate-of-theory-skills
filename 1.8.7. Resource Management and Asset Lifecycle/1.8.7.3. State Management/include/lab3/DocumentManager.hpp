#pragma once
#include <string>
#include <vector>
#include <cstdint>

namespace lab3
{
	class DocumentManager
	{
	public:
		DocumentManager(const std::string& title, size_t size_content);
		void print_info() const;
	private:
		std::string title_{""};
		std::vector<uint8_t> content_{};
	};
}