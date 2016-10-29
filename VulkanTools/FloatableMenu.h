#pragma once
#include "IMenu.h"
class FloatableMenu :
	public IMenu
{
public:
	FloatableMenu();
	virtual ~FloatableMenu();
	virtual void addAction(Action action);

protected:

};

