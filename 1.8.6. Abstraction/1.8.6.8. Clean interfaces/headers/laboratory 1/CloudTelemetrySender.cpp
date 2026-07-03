#include <laboratory 1/CloudTelemetrySender.h>
#include <iostream>

CloudTelemetrySender::CloudTelemetrySender(const std::string& url) : url_server(url) { std::cout << "\trun CloudTelemetrySender::CloudTelemetrySender\n"; };

void CloudTelemetrySender::send_metrics(const std::string& name, double val)
{
	std::cout << "\trun CloudTelemetrySender::send_metrics\n";

	std::cout << "Connecting to: " << url_server << "\n"
		<< "Sending payload {'" << name << "' : '" << val << "'}\n"
		<< "Data sent successful!\n\n";
}

bool CloudTelemetrySender::is_available() const
{
	std::cout << "\trun CloudTelemetrySender::is_available\n";

	if (!url_server.empty())	return true;

	return false;
}