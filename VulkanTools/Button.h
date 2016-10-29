#pragma once
#include "Widget.h"
#include "Label.h"

class Button :
	public Widget
{
public:
	Button(std::string text, rect2D bounds);
	~Button();
	virtual void update();
	

protected:


};

