#pragma once
#include "lab2/CounterMixin.hpp"
#include "lab2/RenderMixin.hpp"
#include <iostream>
#include <string_view>

namespace lab2
{
	class Player : public lab2::CounterMixin<Player>, public lab2::RenderMixin<Player>
	{
	public:
		std::string_view get_model_name() const
		{
			return "Hero_Knight";
		}
	};
}