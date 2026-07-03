#include <laboratory 1/TelemetryProcessor.h>
#include <iostream>

TelemetryProcessor::TelemetryProcessor(std::shared_ptr<ITelemetrySender> ptr_telemetry) : telemetry(std::move(ptr_telemetry))
{
	std::cout << "\trun TelemetryProcessor::TelemetryProcessor()\n";
};

void TelemetryProcessor::process_metrics()
{
	const double VAL{ 4.1 };
	const std::string NAME{ "test" };

	std::cout << "\trun TelemetryProcessor::process_metrics ('" << NAME << "', '"<< VAL << "')\n";

	if (telemetry->is_available())
	{
		telemetry->send_metrics(NAME, VAL);
	}
}