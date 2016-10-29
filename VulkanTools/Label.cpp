#include "Label.h"



Label::Label(std::string text, rect2D boundary, Font font) : m_text(text), m_font(font), Widget(text,  boundary)
{
}

Label::Label(std::string text, offset2D position, Font font) : 
	Label(text, rect2D(position, guitools::getTextSize(text, font)), font)
{

}


Label::~Label()
{
}
