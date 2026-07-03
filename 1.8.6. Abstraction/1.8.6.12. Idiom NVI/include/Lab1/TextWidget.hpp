#pragma once
#include "Lab1/Widget.hpp"

class TextWidget : public Widget
{
public:
	~TextWidget() override = default;
private:
	void draw_content() const override;
};