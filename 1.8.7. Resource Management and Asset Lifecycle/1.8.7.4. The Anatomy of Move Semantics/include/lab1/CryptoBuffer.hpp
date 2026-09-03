#pragma once
#include <cstdint>

namespace lab1
{
	class CryptoBuffer
	{
	public:
		CryptoBuffer(size_t size);
		~CryptoBuffer();
		CryptoBuffer(const CryptoBuffer& other);
		CryptoBuffer& operator=(const CryptoBuffer& other);
		CryptoBuffer(CryptoBuffer&& other) noexcept;
		CryptoBuffer& operator=(CryptoBuffer&& other) noexcept;
		void get_memory_address() const;
	private:
		size_t size_{ 0 };
		uint8_t* data_{ nullptr };
	};
}