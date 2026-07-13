#include "lab3/DisconnectEvent.hpp"
#include <iostream>

lab3::DisconnectEvent::DisconnectEvent(int socket) : socket_id(socket)
{
	std::cout << "[DisconnectEvent] Constructor: created for socket ID '" << socket_id << "'.\n";
}

lab3::DisconnectEvent::~DisconnectEvent()
{
	std::cout << "[DisconnectEvent] Destroyed.\n";
}