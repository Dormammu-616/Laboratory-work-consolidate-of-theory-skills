#pragma once
#include <iostream>

namespace lab2
{
	template <typename Derived> class RenderMixin
	{
	public:
		void render_frame() const
		{
			std::cout << "[template<RenderMixin>] Model rendering: "
				<< static_cast<const Derived*>(this)->get_model_name()
				<< "\n";
		}
	private:

	};
}