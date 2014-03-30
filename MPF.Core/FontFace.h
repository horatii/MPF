#pragma once
#include "../include/String.h"
#include "FontFaceKeys.h"
#include <ft2build.h>
#include FT_FREETYPE_H
#include "../include/visual/BitmapData.h"

NS_MPF
NS_VSL

class FontManager;

//����
class FontFace
{
public:
	FontFace(FT_Face face);
	~FontFace();

	//���ɸ���
	FontFace(const FontFace& fontFace) = delete;

	//���Ƶ����ַ��������ַ������ش�С
	std::pair<uint, uint> DrawChar(BitmapData<byte>& bitmap, uint left, uint top, wchar_t chr, float size);

	//�����ı�Ҫռ�õ����ش�С
	std::pair<uint, uint> MeasureText(const MPF::String& text, float size);

	FT_Face GetFace() const mnoexcept;
	operator FT_Face() const mnoexcept;
private:
	const FontGlyph& GetGlyphCache(const FontFaceCacheKey& key);
	const FontGlyph& GetGlyphCache(wchar_t chr, float size);
	const FontGlyph& LoadGlyphCache(const FontFaceCacheKey& key);
private:
	FT_Face face;
	std::shared_ptr<FontManager> fontMgr;
	std::unordered_map<FontFaceCacheKey, FontGlyph> cache;
};

NS_ED
NS_ED