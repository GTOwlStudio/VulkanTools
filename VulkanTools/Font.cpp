#include "Font.h"

Font Font::segoeui12("./data/fonts/segoeui.ttf", 12);

Font::Font(std::string fontpath, uint32_t fontSize)
{
	FT_Library lib;
	if (FT_Init_FreeType(&lib)) {
		printf("Error while loading Freetype library");
		assert(0);
	}

	FT_New_Face(lib, fontpath.c_str(), 0, &m_face);

	FT_Set_Char_Size(m_face, 0, fontSize * 64, 300, 300);

	FT_GlyphSlot slot = m_face->glyph;

	for (uint32_t i = 0; i < 256;i++) {
		if (FT_Load_Char(m_face, i, FT_LOAD_RENDER)) {
			continue;
		}
		m_charinfo[i].ax = slot->advance.x >> 6;
		m_charinfo[i].ay = slot->advance.y >> 6;
		m_charinfo[i].w = slot->metrics.width >> 6; //Divide by 64=2^6, the with is for 1/64th of a pixel
		m_charinfo[i].h = slot->metrics.height >> 6;//Same as upstairs
		m_charinfo[i].bw = slot->bitmap.width;
		m_charinfo[i].bh = slot->bitmap.rows;
	}

	FT_Done_FreeType(lib);
}

Font::~Font()
{

}

void Font::getCharacterInfo(character_info * dst, uint32_t beg, uint32_t end)
{
	for (uint32_t i = beg; i < end;i++) {
		dst[i - beg] = m_charinfo[i];
	}
}
