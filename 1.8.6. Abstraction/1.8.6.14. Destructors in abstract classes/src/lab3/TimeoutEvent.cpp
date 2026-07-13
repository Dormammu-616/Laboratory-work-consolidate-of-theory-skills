#include "lab3/TimeoutEvent.hpp"
#include <iostream>

lab3::TimeoutEvent::TimeoutEvent(const std::string& name) : process_name(name)
{
	std::cout << "[TimeoutEvent] Constructor: created for process with name '"<< process_name << "'.\n";
}

lab3::TimeoutEvent::~TimeoutEvent()
{
	std::cout << "[TimeoutEvent] Destroyed.\n";
}