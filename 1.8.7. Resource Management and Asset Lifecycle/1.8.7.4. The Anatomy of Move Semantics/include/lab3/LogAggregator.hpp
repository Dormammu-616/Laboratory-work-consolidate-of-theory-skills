#pragma once
#include <string>
#include <vector>

namespace lab3
{
	class LogAggregator
	{
	public:
		LogAggregator(std::string name);
		void add_log(std::string message);
		static LogAggregator create_aggregator(std::string name);
		std::string_view get_node_name() const [[msvc::lifetimebound]];
		const size_t get_size_log() const;
	private:
		std::string node_name_{ "" };
		std::vector<std::string> log_entries_{};
	};
}