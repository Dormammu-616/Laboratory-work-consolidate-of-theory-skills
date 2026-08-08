#pragma once
#include <string>
#include <string_view>

namespace lab2
{
	class Packet
	{
	public:
		Packet(size_t id, std::string payload);
		~Packet() = default;
		Packet(const Packet&) = delete;
		Packet& operator=(const Packet&) = delete;
		Packet(Packet&&) = default;
		Packet& operator=(Packet&&) = default;
		[[nodiscard]] std::string_view get_view() const;
		[[nodiscard]] std::string_view extract_header(size_t header_size) const;
		[[nodiscard]] std::string_view extract_body(size_t header_size) const;
		[[nodiscard]] size_t get_id() const;
	private:
		size_t id_{ 0 };
		std::string raw_payload_{ "" };
	};
}