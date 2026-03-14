#include "SmartCityTelemetry.h"
#include "NetworkSenderFactory.h"
#include "CityThermometer.h"
#include <iostream>
#include <memory>

void Smart_City_Telemetry::run_lab()
{
	std::cout << "*** Start lab #3 ***\n";

	std::cout << "--- Create city thermometer ---\n";
	std::unique_ptr<City_Thermometer> termometer{std::make_unique<City_Thermometer>()};
	const std::string TEMP_FOR_NETWORK{ termometer->takeMeasurement() };
	std::cout << "\ttemperature initialized value: " << TEMP_FOR_NETWORK;

	std::cout << "--- Create network 'secure' ---\n";
	std::unique_ptr<INetwork_Sender> network_secure{ Network_Sender_Factory::create_sender("secure", "99.44.77.11") };
	network_secure->send_payload(TEMP_FOR_NETWORK);

	std::cout << "--- Create network 'open' ---\n";
	std::unique_ptr<INetwork_Sender> network_open{ Network_Sender_Factory::create_sender("open", "45.484.21.44") };
	network_open->send_payload(TEMP_FOR_NETWORK);

	std::cout << "*** End lab #3 ***\n";
}