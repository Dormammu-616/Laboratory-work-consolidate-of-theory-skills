#include "lab3/LogAggregator.hpp"
#include <iostream>

lab3::LogAggregator::LogAggregator(std::string name) : node_name_(std::move(name))
{
	std::cout << "[LogAggregator] Called constructor from parameter '"<< node_name_ << "'.\n";
}

void lab3::LogAggregator::add_log(std::string message)
{
	std::cout << "[LogAggregator] Adding log...\n";
	log_entries_.emplace_back(std::move(message));
}

lab3::LogAggregator lab3::LogAggregator::create_aggregator(std::string name)
{
	std::cout << "[LogAggregator] Creating aggregator...\n";

	lab3::LogAggregator local_aggregator{ std::move(name) };
	
	std::cout << "\t[LogAggregator] Log addition start.\n";
	local_aggregator.add_log("log_second");
	local_aggregator.add_log("log_first");
	std::cout << "\t[LogAggregator] Finished adding logs.\n";

	return local_aggregator;
}

std::string_view lab3::LogAggregator::get_node_name() const
{
	std::cout << "[LogAggregator] Getting mode name...\n";

	return node_name_;
}

const size_t lab3::LogAggregator::get_size_log() const
{
	return log_entries_.size();
}