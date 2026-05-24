#pragma once
#include <laboratory 1/ITelemetrySender.h>
#include <filesystem>

class LocalFileTelemetrySender : public ITelemetrySender
{
public:
	LocalFileTelemetrySender() = delete;
	LocalFileTelemetrySender(const std::string& name_path);
	~LocalFileTelemetrySender() = default;
	void send_metrics(const std::string& name, double val) override;
	bool is_available() const override;
private:
	std::filesystem::path path{};
};