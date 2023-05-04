#include "Font.h"
#include <cassert>

Font::Font(const std::string& filename, Color chroma)
	:
	surface(filename),
	glyphWidth(surface.GetWidth() / nColumns),
	glyphHeight(surface.GetHeight() / nRows),
	chroma(chroma)
{
	assert(glyphHeight * nRows == surface.GetHeight());
	assert(glyphWidth * nColumns== surface.GetWidth());
}

void Font::DrawText(const std::string& text, const Vei2& pos, Color textcolor, Graphics& gfx) const
{
	auto curPos = pos;
	for (auto c : text) {
		
		if (c == '\n') {
			curPos.x = pos.x; //carriage return
			curPos.y += glyphHeight; //line feed
			continue;
		}
		if (c >= firstChar + 1 && c <= lastChar) {
			gfx.DrawSpriteSubstitute(curPos.x, curPos.y, textcolor, MapGlyphRect(c), surface, chroma);
		}
		curPos.x += glyphWidth;
	}

}

RectI Font::MapGlyphRect(char c) const
{
	assert(c >= firstChar && c <= lastChar);

	const int glyphIndex = c - ' ';
	const int yGlyph = glyphIndex / nColumns;
	const int xGlyph = glyphIndex % nColumns;
	return RectI({xGlyph*glyphWidth, yGlyph*glyphHeight}, glyphWidth, glyphHeight);
}
