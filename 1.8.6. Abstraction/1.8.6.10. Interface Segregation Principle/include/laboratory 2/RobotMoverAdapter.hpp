#pragma once
#include "include/laboratory 2/IMover.hpp"
#include "include/laboratory 2/IUniversalRobotAPI.hpp"

class RobotMoverAdapter : public IMover
{
public:
	RobotMoverAdapter(IUniversalRobotAPI& robot);
	RobotMoverAdapter(const RobotMoverAdapter&) = delete;
	RobotMoverAdapter& operator=(const RobotMoverAdapter&) = delete;
	~RobotMoverAdapter() = default;
	void move_cargo(std::string_view destination) override;
private:
	IUniversalRobotAPI& legacy_robot;
};