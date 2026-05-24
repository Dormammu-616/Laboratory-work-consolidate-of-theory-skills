#pragma once
#include <laboratory 2/IConnectable.h>
#include <laboratory 2/ISensor.h>

class WiredCamera :public IConnectable, public ISensor
{
public:
	WiredCamera() = default;
	WiredCamera(const std::string& network);
	bool is_connected() const override;
	void connect(std::string_view network) override;
	void disconnect() override;
	std::optional<double> read_data() const override;
	~WiredCamera() = default;
private:
	static constexpr double SIZE_FRAME{ 14.5 };
	std::string cur_network{""};
	bool is_network_conected{false};
};