#include "lab1/HardwareAcceleratedWindow.hpp"
#include <iostream>

lab1::HardwareAcceleratedWindow::HardwareAcceleratedWindow()
{
	memory_size = 1024;
	std::cout << "[HardwareAcceleratedWindow] Requesting GPU context. Size of '" << memory_size << "' byte.\n";
}

void lab1::HardwareAcceleratedWindow::render() const
{
	std::cout << "\t[HardwareAcceleratedWindow] GPU load...\n";
}

lab1::HardwareAcceleratedWindow::~HardwareAcceleratedWindow()
{
	memory_size = 0;
	std::cout << "[HardwareAcceleratedWindow] Releasing GPU context. Size of '"<<memory_size << "' byte.\n";
}
