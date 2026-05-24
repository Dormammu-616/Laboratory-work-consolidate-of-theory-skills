#pragma once
#include <laboratory 1/ITelemetrySender.h>

class CloudTelemetrySender : public ITelemetrySender
{
public:
	CloudTelemetrySender() = delete;
	CloudTelemetrySender(const std::string& url);
	~CloudTelemetrySender() = default;
	void send_metrics(const std::string& name, double val) override;
	bool is_available() const override;
private:
	std::string url_server{};
};
