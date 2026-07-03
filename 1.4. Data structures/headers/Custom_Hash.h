#pragma once
#include <cstdint>
#include <string>

namespace Custom_Hash
{
	inline uint64_t calc_poly_hash(const std::string& data)
	{
		static constexpr uint64_t BASE{ 31 };
		static constexpr uint64_t MOD{ 1000000007 };
		uint64_t hash{ 0 };

		for (const char sym : data)
		{
			uint8_t x{ static_cast<uint8_t>(sym) };
			hash = (hash * BASE + x) % MOD;
		}

		return hash;
	}
}
