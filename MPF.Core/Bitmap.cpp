#include "stdafx.h"
#include "GDI/Bitmap.h"

using namespace MPF;
using namespace MPF::GDI;

DEFINE_TYPE(Bitmap, MPF::GDI::Bitmap)

Bitmap::Bitmap()
:width(0u), height(0u)
{

}

std::shared_ptr<Bitmap> Bitmap::CreateDIBSection(HDC hDC, uint width, uint height)
{
	width &= ~(4 - 1);
	height &= ~(4 - 1);

	auto bitmap = std::make_shared<Bitmap>();
	
	BITMAPINFO bmpInfo;
	bmpInfo.bmiHeader.biSize = sizeof(bmpInfo);
	bmpInfo.bmiHeader.biWidth = width;
	bmpInfo.bmiHeader.biHeight = -(LONG)height;
	bmpInfo.bmiHeader.biPlanes = 1;
	bmpInfo.bmiHeader.biBitCount = 32;			//32 λ��
	bmpInfo.bmiHeader.biCompression = BI_RGB;

	bitmap->hBitmap = ::CreateDIBSection(hDC, &bmpInfo, 
		DIB_RGB_COLORS, (void**)&bitmap->data, nullptr, 0);
	massert(bitmap->hBitmap != nullptr);
	bitmap->width = width;
	bitmap->height = height;

	memset(bitmap->data, 0xFFFFFFFF, width * height * 4);

	return bitmap;
}

byte* Bitmap::GetDataPointer() const mnoexcept
{
	return data;
}

Bitmap::~Bitmap()
{
	if (hBitmap)
	{
		DeleteObject(hBitmap);
		hBitmap = nullptr;
	}
	data = nullptr;
}

HBITMAP Bitmap::GetNativeHandle() const mnoexcept
{
	return hBitmap;
}