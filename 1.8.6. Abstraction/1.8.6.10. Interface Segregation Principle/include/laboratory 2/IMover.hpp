#pragma once
#include <string_view>

class IMover
{
public:
	virtual void move_cargo(std::string_view destination) = 0;
	virtual ~IMover() = default;
};
