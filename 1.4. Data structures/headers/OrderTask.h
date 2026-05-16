#pragma once
#include <iostream>
#include <cstdint>
#include <string>

struct OrderTask
{
	uint64_t order_id{};
	uint8_t priority{0};
	uint8_t padding[7]{};
	std::string operation{};
	OrderTask(const uint64_t id, const uint8_t rank, const std::string& name_operation);
	OrderTask(const uint64_t id, const std::string& name_operation);
};

std::ostream& operator<<(std::ostream& os, const OrderTask& task);