#pragma once
#include "lab2/CounterMixin.hpp"
#include "lab2/RenderMixin.hpp"
#include <iostream>
#include <string_view>

namespace lab2
{
	class Enemy : public lab2::CounterMixin<Enemy>, public lab2::RenderMixin<Enemy>
	{
	public:
		std::string_view get_model_name() const
		{
			return "Orc_Grunt";
		}
	};
}