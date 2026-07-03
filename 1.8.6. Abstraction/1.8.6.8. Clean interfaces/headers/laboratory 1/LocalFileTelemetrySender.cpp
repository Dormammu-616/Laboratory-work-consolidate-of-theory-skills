#include <laboratory 1/LocalFileTelemetrySender.h>
#include <iostream> 
#include <fstream>

LocalFileTelemetrySender::LocalFileTelemetrySender(const std::string& name_path) : path(name_path) { std::cout << "\tLocalFileTelemetrySender::LocalFileTelemetrySender\n"; };

void LocalFileTelemetrySender::send_metrics(const std::string& name, double val)
{
	std::cout << "\trun LocalFileTelemetrySender::send_metrics\n";

	std::cout << "Open log file: " << path << "\n";

	std::ofstream file(path, std::ios::app);

	if (file.is_open())
	{
		file << "Metric: " << name << "| Value: " << val << "\n";
		std::cout << "Writing successfully!\n\n";
	}
	else
	{
		std::cout << "ERROR: could not open file for writting: " << path << "\n\n";
	}
}

bool LocalFileTelemetrySender::is_available() const
{
	std::cout << "\trun LocalFileTelemetrySender::is_available\n";

	if (!path.empty())	return true;

	return false;
}