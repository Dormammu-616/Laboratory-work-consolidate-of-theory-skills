#pragma once
#include <cstdint>

namespace lab1
{
	class RawNetworkBuffer
	{
	public:
		RawNetworkBuffer() = default;
		RawNetworkBuffer(size_t size);
		~RawNetworkBuffer();
		RawNetworkBuffer(const RawNetworkBuffer& buffer);
		RawNetworkBuffer& operator=(const RawNetworkBuffer& other);
	private:
		uint8_t* data_{nullptr};
		size_t size_{0};
	};
}