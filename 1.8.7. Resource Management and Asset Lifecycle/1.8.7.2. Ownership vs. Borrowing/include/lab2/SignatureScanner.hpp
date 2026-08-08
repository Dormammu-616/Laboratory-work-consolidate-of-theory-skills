#pragma once
#include <string_view>

namespace lab2
{
	class SignatureScanner
	{
	public:
		[[nodiscard]] bool is_contains(std::string_view data, std::string_view pattern) const;
		void print_hex_dump(std::string_view data) const;
	};
}