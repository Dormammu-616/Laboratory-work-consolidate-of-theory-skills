#pragma once
#include <string_view>

class IUniversalRobotAPI
{
public:
	virtual void weld() = 0;
	virtual void paint() = 0;
	virtual void carry_item(std::string_view target) = 0;
	virtual ~IUniversalRobotAPI() = default;
};