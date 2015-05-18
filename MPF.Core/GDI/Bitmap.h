#pragma once
#include "../../include/Type.h"

NS_MPF
NS_GDI

//λͼ
class Bitmap : public Object
{
public:
	//���� Bitmap ����ʵ��
	Bitmap();
	//�ͷ�
	virtual ~Bitmap();

	//��ȡ����
	byte* GetDataPointer() const noexcept;

	//��ȡ������ʶ��
	HBITMAP GetNativeHandle() const noexcept;

	//��ȡ���
	uint32_t GetWidth() const noexcept { return width; }

	//��ȡ�߶�
	uint32_t GetHeight() const noexcept { return height; }

	//�����豸�޹�λͼ
	static std::unique_ptr<Bitmap> CreateDIBSection(HDC hDC, uint32_t width, uint32_t height);

	void AlphaBlend(argb_color color);
	void Clear(argb_color color);

	//��ȡ����
	DECLARE_GETTYPE(Bitmap)
private:
	HBITMAP hBitmap = nullptr;
	uint32_t width, height;
	byte* data = nullptr;
	DECLARE_TYPE(Bitmap)
};

NS_ED
NS_ED