#include <laboratory 2/WiredCamera.h>
#include <iostream>

WiredCamera::WiredCamera(const std::string& network) : cur_network(network), is_network_conected(!network.empty()) {};

bool WiredCamera::is_connected() const
{
	std::cout << "[WiredCamera] Check connected WiredCamera\n";
	return is_network_conected;
}

void WiredCamera::connect(std::string_view network)
{
	if (!network.empty())
	{
		is_network_conected = true;
		cur_network = network;
		std::cout << "[WiredCamera] Connected successful on WiredCamera\n";
	}
}

void WiredCamera::disconnect()
{
	is_network_conected = false;
	cur_network.clear();
	std::cout << "[WiredCamera] Disconnected successful on WiredCamera\n";
}

std::optional<double> WiredCamera::read_data() const
{
	if (is_connected())
	{
		std::cout << "[WiredCamera] Successful read data on WiredCamera\n";
		return SIZE_FRAME;
	}

	std::cout << "[WiredCamera] Unsuccessful read data on WiredCamera\n";
	return std::nullopt;
}