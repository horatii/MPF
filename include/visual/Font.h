#pragma once
#include "../Type.h"
#include "BitmapData.h"

#ifdef DrawText
#undef DrawText
#endif

NS_MPF
NS_VSL

class FontFace;

//����
class Font : public MPF::Object
{
public:
	//���������ƺʹ�С��������
	MPF_API Font(const MPF::String& faceName, float size);

	//�������ļ���������źʹ�С��������
	MPF_API Font(const MPF::String& fileName, uint32_t faceIndex, float size);
	//�������ļ���������źʹ�С��������
	MPF_API Font(MPF::String&& fileName, uint32_t faceIndex, float size);

	MPF_API Font(const Font& font);
	MPF_API Font(Font&& font) noexcept;

	//���Ƶ����ַ��������ַ������ش�С
	MPF_API std::pair<uint32_t, uint32_t> DrawChar(BitmapData<byte>& bitmap, uint32_t left, 
		uint32_t top, wchar_t chr);

	MPF_API void DrawText(BitmapData<byte>& bitmap, uint32_t left, uint32_t top, const MPF::String& text);

	//�����ı�Ҫռ�õ����ش�С
	MPF_API std::pair<uint32_t, uint32_t> MeasureText(const MPF::String& text);

	MPF_API bool operator!=(const Font& font)const noexcept;
	MPF_API const Font& operator=(const Font& font);
	MPF_API const Font& operator=(Font&& font) noexcept;

	//��ȡ����
	MPF_API DECLARE_GETTYPE(Font)
	MPF_API DECLARE_GETINSTANTTYPE(Font)
private:
	float size;
	std::shared_ptr<FontFace> face;
	DECLARE_TYPE(Font)
};

NS_ED
NS_ED