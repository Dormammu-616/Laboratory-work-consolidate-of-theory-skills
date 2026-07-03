#pragma once
#include <iostream>
#include <string_view>

namespace lab1
{
	class CorePacketProcessor
	{
	public:
		void process_packet(std::string_view packet_data)
		{
			++success_count;
			std::cout << "[lab1::CorePacketProcessor] The package [" << packet_data << "] has been processed successfully. Total successful: " << success_count << "\n";
		}
	private:
		size_t success_count{ 0 };
	};
}