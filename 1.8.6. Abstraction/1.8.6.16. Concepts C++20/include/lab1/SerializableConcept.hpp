#pragma once
#include <concepts>
#include <string>

namespace lab1
{
	template <typename T> 
	concept Serializable = requires(const T& x)
	{
		{ x.serialize() } -> std::same_as<std::string>;
	};
}