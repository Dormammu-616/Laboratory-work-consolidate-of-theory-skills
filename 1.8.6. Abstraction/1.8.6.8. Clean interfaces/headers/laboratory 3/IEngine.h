#pragma once
#include <string>
#include <memory>

class IEngine
{
public:
	virtual void initialize() = 0;
	virtual void execute_task(std::string_view task_name) = 0;
	virtual ~IEngine() = default;
};

std::unique_ptr<IEngine> create_engine(std::string_view engine_type);
