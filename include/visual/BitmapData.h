#pragma once
#include "../Type.h"

NS_MPF
NS_VSL

//λͼ����
template<typename TColor>
class BitmapData
{
public:
	//���� BitmapData ����ʵ��
	BitmapData(TColor* data, uint width, uint height, uint pitch)
		:data(data), width(width), height(height), pitch(pitch), owner(false)
	{

	}

	//���� BitmapData ����ʵ��
	BitmapData(uint width, uint height, uint pitch)
		:data(nullptr), width(width), height(height), pitch(pitch), owner(true)
	{
		auto size = pitch * height;
		data = new TColor[size];
		memset(data, 0, size);
	}

	//���� BitmapData ����ʵ��
	BitmapData(uint width, uint height)
		:data(nullptr), width(width), height(height), pitch(width), owner(true)
	{
		auto size = pitch * height;
		data = new TColor[size];
		memset(data, 0, size);
	}

	BitmapData(const BitmapData& bitmap)
		:data(bitmap.data), width(bitmap.width), height(bitmap.height), pitch(bitmap.width), owner(bitmap.owner)
	{
		if (owner && bitmap.data)
		{
			const auto size = pitch * height;
			data = new TColor[size];
			memcpy_s(data, size, bitmap.data, size);
		}
	}

	BitmapData(BitmapData&& bitmap)
		:data(bitmap.data), width(bitmap.width), height(bitmap.height), pitch(bitmap.width), owner(bitmap.owner)
	{
		bitmap.data = nullptr;
		bitmap.owner = false;
	}

	~BitmapData()
	{
		Dispose();
	}

	const BitmapData<TColor>& operator=(const BitmapData<TColor>& bitmap)
	{
		Dispose();
		data = bitmap.data;
		width = bitmap.width;
		height = bitmap.height;
		pitch = bitmap.pitch;
		owner = bitmap.owner;

		if (owner && bitmap.data)
		{
			const auto size = pitch * height;
			data = new TColor[size];
			memcpy_s(data, size, bitmap.data, size);
		}
		return *this;
	}

	const BitmapData<TColor>& operator=(BitmapData<TColor>&& bitmap)
	{
		Dispose();
		data = bitmap.data;
		width = bitmap.width;
		height = bitmap.height;
		pitch = bitmap.pitch;
		owner = bitmap.owner;
		bitmap.data = nullptr;
		bitmap.owner = false;
		return *this;
	}

	void CopyFrom(const BitmapData<byte>& source, uint srcLeft = 0, uint srcTop = 0, 
		uint destLeft = 0, uint destTop = 0)
	{
		massert(destLeft <= width);
		massert(destTop <= height);
		size_t maxX = min(width - destLeft, source.width - srcLeft);
		size_t maxY = min(height - destTop, source.height - srcTop);
		size_t srcPitch(source.pitch);
		auto ptr = data + destTop * pitch + destLeft;
		auto srcPtr = source.data + srcTop * srcPitch + srcLeft;
		for (size_t y = 0; y < maxY; y++)
		{
			for (size_t x = 0; x < maxX; x++)
			{
				ptr[x] = srcPtr[x];
			}
			srcPtr += srcPitch;
			ptr += pitch;
		}
	}

	//��ȡ����
	TColor* GetDataPointer() const mnoexcept{ return data; }
	//��ȡ��ȣ����أ�
	uint GetWidth() const mnoexcept{ return width; }
	//��ȡ�߶ȣ����أ�
	uint GetHeight() const mnoexcept{ return height; }
	//��ȡPitch�����أ�
	uint GetPitch() const mnoexcept{ return pitch; }
private:
	void Dispose()
	{
		if (owner && data)
		{
			delete[] data;
		}
		owner = false;
		data = nullptr;
	}
private:
	bool owner;
	TColor* data;
	uint width;
	uint height;
	uint pitch;
};

NS_ED
NS_ED