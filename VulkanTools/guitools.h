#pragma once
#include <vector>
#include <vulkan\vulkan.h>
#include "Font.h"

struct offset2D { 
	float x, y; 
	offset2D() : x(0.0f), y(0.0f) {}
	offset2D(float px, float py) : x(px), y(py) {}
};
struct extent2D { 
	float width, height; 
	extent2D() : width(0.0f), height(0.0f){}
	extent2D(float w, float h) : width(w), height(h){}

};

struct rect2D {
	offset2D offset;
	extent2D extent;
	rect2D(offset2D poffset, extent2D pextent) : offset(poffset) ,extent(pextent) {}
};


struct f
{
	std::string fname;
	f(std::string f) : fname(f) {};
};

//fcalibri("Calibri");

namespace guitools
{
	 offset2D center(rect2D parent, extent2D child);
	 extent2D getTextSize(std::string text, Font font);
	 bool entered(rect2D surface, offset2D xy);
}

struct GuiObject
{
	rect2D boundary;
	std::vector<GuiObject> childs;
	GuiObject(float x, float y, float w, float h) : boundary(offset2D(x,y),extent2D(w,h)){}
	GuiObject(GuiObject* parents, float w, float h) : boundary(guitools::center(parents->boundary, extent2D(w,h)), extent2D(w,h)){};
	void addObject(GuiObject object) 
	{
	};
};

class GuiLayout
{
public:
	GuiLayout();
	~GuiLayout();
	void addObject(GuiObject object, GuiObject *parents);
protected:
	std::vector<GuiObject> m_objects;

};
