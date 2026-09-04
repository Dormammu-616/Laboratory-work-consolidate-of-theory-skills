#include "lab2/SecurityEvent.hpp"
#include <iostream>

lab2::SecurityEvent::SecurityEvent(int64_t id, std::string_view payload) : event_id_(id), payload_(payload)
{
	std::cout << "[SecurityEvent] Called constructor from parameters '"<< id << "' and '"<< payload<<"'.\n";
}

lab2::SecurityEvent::SecurityEvent(const lab2::SecurityEvent& other) : event_id_(other.event_id_), payload_(other.payload_)
{
	std::cout << "[SecurityEvent] Called copy constructor from parameter '" << event_id_ <<"'.\n";
}

lab2::SecurityEvent::SecurityEvent(lab2::SecurityEvent&& other) noexcept : event_id_(std::exchange(other.event_id_, 0)), payload_(std::move(other.payload_))
{
	std::cout << "[SecurityEvent] Called move constructor from parameter '" << event_id_ << "'.\n";
}