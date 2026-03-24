#pragma once
#include <vector>
#include <string>

class LogInspector;

class LogManager
{
public:
	LogManager() = delete;
	LogManager(const std::string& time_log, const size_t error, const std::string& type) : vec_logs{Logs{time_log, error, type}} {};
	~LogManager() = default;
	void add_log(const std::string& time_log, const size_t error, const std::string& type);
	void clear_log();
protected:
	std::string last_type_log() const;
private:
	struct Logs
	{
		Logs() = delete;
		Logs(const std::string& time_log, const size_t error, const std::string& type) : time_tamp(time_log), error_code(error), type_log(type) {};
		~Logs() = default;
		std::string time_tamp{};
		size_t error_code{};
		std::string type_log{};
	};
	friend class LogInspector;
	std::vector<Logs> vec_logs;
};