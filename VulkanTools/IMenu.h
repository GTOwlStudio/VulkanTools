#pragma once
#include "Widget.h" 
#include "Action.h"

class IMenu : public Widget
{
public:
	IMenu(std::string name, rect2D bounds) : Widget(name, bounds) {}
	virtual ~IMenu() = 0;
	virtual void addAction(Action action) = 0;

};