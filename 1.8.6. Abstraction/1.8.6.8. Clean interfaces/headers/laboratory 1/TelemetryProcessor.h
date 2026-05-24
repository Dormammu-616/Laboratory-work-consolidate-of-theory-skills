#pragma once
#include <laboratory 1/ITelemetrySender.h>
#include <memory>

class TelemetryProcessor
{
public:
	TelemetryProcessor() = delete;
	TelemetryProcessor(std::shared_ptr<ITelemetrySender> ptr_telemetry);
	void process_metrics();
private:
	std::shared_ptr<ITelemetrySender> telemetry;
};