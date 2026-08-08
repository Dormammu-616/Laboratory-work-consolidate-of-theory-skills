#include "lab2/Packet.hpp"
#include <iostream>

lab2::Packet::Packet(size_t id, std::string payload) : id_(id), raw_payload_(std::move(payload)) {};

std::string_view lab2::Packet::get_view() const
{
	return raw_payload_;
}

std::string_view lab2::Packet::extract_header(size_t header_size) const
{
	if (header_size > raw_payload_.size())
	{
		header_size = std::min(header_size, raw_payload_.size());
		std::cout << "\t[Packet] the passed value exceeds the string size - std::min will be used.\n";
	}

	std::string_view view_str{ raw_payload_ };
	return view_str.substr(0, header_size);
}

std::string_view lab2::Packet::extract_body(size_t header_size) const
{
	if (header_size > raw_payload_.size())
	{
		header_size = std::min(header_size, raw_payload_.size());
		std::cout << "\t[Packet] the passed value exceeds the string size - std::min will be used.\n";
	}

	std::string_view view_str{ raw_payload_ };
	return view_str.substr(header_size, view_str.size());
}

size_t lab2::Packet::get_id() const
{
	return id_;
}
