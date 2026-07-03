#pragma once
#include <string_view>

class IPrinter
{
public:
	virtual ~IPrinter() = default;
	virtual void print_document(std::string_view text) = 0;
};