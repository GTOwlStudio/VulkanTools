#pragma once
#include "Widget.h" 
#include "Action.h"

class IMenu : public Widget
{
public:
	//virtual IMenu(std::string name, rect2D bounds) : Widget(name, bounds);
	IMenu(std::string name, rect2D) : Widget(name, rect2D(0,0,200,200)) {};
	virtual ~IMenu() {};
	virtual void addAction(Action action) = 0;

};