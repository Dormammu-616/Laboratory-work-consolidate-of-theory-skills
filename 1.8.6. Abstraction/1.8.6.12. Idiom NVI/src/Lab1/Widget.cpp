#include "Lab1/Widget.hpp"
#include <iostream>

void Widget::render()
{
	std::cout << "[Widget] Capturing GPU context...\n";
	std::cout << "[Widget] Pre-conditions met.\n";

	draw_content();

	std::cout << "[Widget] Releasing GPU Context...\n";
	std::cout << "[Widget] Logging render performance.\n\n";
}