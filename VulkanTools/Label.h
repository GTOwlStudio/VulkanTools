#pragma once
#include "Widget.h"
#include "Font.h"


class Label : public Widget
{
public:
	Label(std::string text, rect2D boundary, Font font = Font::segoeui12);
	Label(std::string text, offset2D position, Font font = Font::segoeui12);
	~Label();
	

protected:
	std::string m_text;
	//f m_f;
	Font m_font;
};

