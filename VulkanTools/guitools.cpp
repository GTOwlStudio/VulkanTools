#include "guitools.h"

namespace guitools {

	offset2D center(rect2D parent, extent2D child)
	{
		offset2D centeredPos = {};
		centeredPos.x = parent.offset.x +(parent.extent.width /2.0f)- (child.width / 2.0f);
		centeredPos.y = parent.offset.y + (parent.extent.height / 2.0f) - (child.height / 2.0f);
		return centeredPos;
	}

	extent2D getTextSize(std::string text, Font font)
	{
		float height = 0.0f;
		float width = 0.0f;
		character_info cinfo[256];
		font.getCharacterInfo(cinfo);
		for (size_t i = 0; i < text.size();i++) {
			if (cinfo[(int)text[i]].h>height) {
				height = cinfo[(int)text[i]].h;
			}
			width += cinfo[int(text[i])].w;
		}
		return extent2D(width,height);
	}

	bool entered(rect2D surface, offset2D xy)
	{
		if ((xy.x >= surface.offset.x) && (xy.x <= (surface.offset.x +surface.extent.width)) &&	
			(xy.y >= surface.offset.y) && (xy.y <= (surface.offset.y + surface.extent.height))	) {
			return true;
		}
		return false;
	}

}