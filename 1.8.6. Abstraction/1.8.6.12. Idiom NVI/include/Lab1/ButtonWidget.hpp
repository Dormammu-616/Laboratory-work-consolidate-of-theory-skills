#pragma once
#include "Lab1/Widget.hpp"

class ButtonWidget : public Widget
{
public:
	~ButtonWidget() override = default;
private:
	void draw_content() const override;
};
