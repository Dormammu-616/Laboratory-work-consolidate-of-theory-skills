#pragma once

class Widget
{
public:
	virtual ~Widget() = default;
	void render();
private:
	virtual void draw_content() const = 0;
};