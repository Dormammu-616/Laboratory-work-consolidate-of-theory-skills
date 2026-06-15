#pragma once
#include <string_view>

class IFax
{
public:
	virtual ~IFax() = default;
	virtual void send_fax(std::string_view text, std::string_view number) = 0;
};