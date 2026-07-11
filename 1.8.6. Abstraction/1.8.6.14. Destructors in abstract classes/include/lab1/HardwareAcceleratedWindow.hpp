#pragma once
#include "lab1/IWindow.hpp"

namespace lab1
{
	class HardwareAcceleratedWindow : public IWindow
	{
	public:
		HardwareAcceleratedWindow();
		~HardwareAcceleratedWindow() override;
		void render() const override;
	private:
		size_t memory_size{ 0 };
	};
}