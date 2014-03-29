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
	byte* GetDataPointer() const mnoexcept;

	//��ȡ������ʶ��
	HBITMAP GetNativeHandle() const mnoexcept;

	//��ȡ���
	uint GetWidth() const mnoexcept { return width; }

	//��ȡ�߶�
	uint GetHeight() const mnoexcept { return height; }

	//�����豸�޹�λͼ
	static std::shared_ptr<Bitmap> CreateDIBSection(HDC hDC, uint width, uint height);

	//��ȡ����
	DECLARE_GETTYPE(Bitmap)
private:
	HBITMAP hBitmap = nullptr;
	uint width, height;
	byte* data = nullptr;
	DECLARE_TYPE(Bitmap)
};

NS_ED
NS_ED