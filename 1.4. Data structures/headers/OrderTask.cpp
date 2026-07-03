#include "OrderTask.h"

OrderTask::OrderTask(const uint64_t id, const uint8_t rank, const std::string& name_operation) : order_id(id), priority(rank), operation(name_operation) {};

OrderTask::OrderTask(const uint64_t id, const std::string& name_operation) : order_id(id), priority(static_cast<uint8_t>(0)), operation(name_operation) {};

std::ostream& operator<<(std::ostream& os, const OrderTask& task)
{
	if (task.priority != 0)
	{
		os << "Priority:\t" << static_cast<int>(task.priority) << "\n";
	}

	return os << "ID:\t\t" << task.order_id << "\n"
		<< "Operation:\t" << task.operation << "\n";
}