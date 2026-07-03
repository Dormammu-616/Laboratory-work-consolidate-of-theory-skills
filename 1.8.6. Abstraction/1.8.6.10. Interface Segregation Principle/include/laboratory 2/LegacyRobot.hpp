#pragma once
#include "include/laboratory 2/IUniversalRobotAPI.hpp"

class LegacyRobot : public IUniversalRobotAPI
{
public:
	LegacyRobot() = default;
	~LegacyRobot() override = default;
	void weld() override;
	void paint() override;
	void carry_item(std::string_view target) override;
};