#pragma once
#include <ft2build.h>
#include <freetype\freetype.h>
#include <string>
#include <assert.h>

struct character_info
{
	float ax;	// advance x
	float ay;	// advance y
	float w;	// width
	float h;	// height
	float bx;	// bearing X
	float by;	// bearing Y
	uint32_t bw;	// bitmap width
	uint32_t bh;	// bitmap height
	float tx;	// x texture coordinate 
	float ty;	// y texture coordinate
};

class Font
{
public:
	Font(std::string fontpath, uint32_t fontSize);
	~Font();
	void getCharacterInfo(character_info* dst, uint32_t beg = 0, uint32_t end = 255);

protected:
	FT_Face m_face;
	character_info m_charinfo[256];

public:
	static Font segoeui12;
};