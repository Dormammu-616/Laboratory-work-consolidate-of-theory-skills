#pragma once
#include <string_view>

class IComputeNode
{
public:
	virtual void execute_task(std::string_view task_name) = 0;
	virtual ~IComputeNode() = default;
};