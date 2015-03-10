//
// MPF
// ͼ��ˢ
//
// (c) SunnyCase 
// �������� 2014-03-23
#pragma once
#include "Brush.h"
#include "../media/ImageSource.h"

NS_MPF
NS_VSL

//ͼƬ��ˢ
class ImageBrush : public Brush
{
public:
	// ���� ImageBrush ����ʵ��
	MPF_API ImageBrush(std::shared_ptr<Media::ImageSource> source);
	// ���� ImageBrush ����ʵ��
	MPF_API ImageBrush(Media::ImageSource& source);
	MPF_API virtual ~ImageBrush();

	// ����
	MPF_API virtual color_t TakeSample(float u, float v) const;

	// ��ȡ����
	MPF_API DECLARE_GETTYPE(ImageBrush);
	MPF_API DECLARE_GETINSTANTTYPE(ImageBrush);
private:
	std::shared_ptr<Media::ImageSource> sourceHolder;
	Media::ImageSource* source;

	DECLARE_TYPE(ImageBrush)
};

NS_ED
NS_ED