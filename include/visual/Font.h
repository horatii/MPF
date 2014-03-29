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
	MPF_API Font(std::shared_ptr<MPF::String> faceName, float size);

	//�������ļ���������źʹ�С��������
	MPF_API Font(std::shared_ptr<MPF::String> fileName, uint faceIndex, float size);

	MPF_API Font(const Font& font);

	//���Ƶ����ַ��������ַ������ش�С
	MPF_API std::pair<uint, uint> DrawChar(BitmapData<byte>& bitmap, uint left, 
		uint top, wchar_t chr);

	MPF_API void DrawText(BitmapData<byte>& bitmap, uint left, uint top, const MPF::String& text);

	//�����ı�Ҫռ�õ����ش�С
	MPF_API std::pair<uint, uint> MeasureText(const MPF::String& text);

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