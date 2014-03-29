#pragma once
#include "Brush.h"

NS_MPF
NS_VSL

//ͼƬ��ˢ
class ImageBrush : public Brush
{
public:
	//���� ImageBrush ����ʵ��
	MPF_API ImageBrush() mnoexcept;

	//���� ImageBrush ����ʵ��
	MPF_API ImageBrush(color_t color) mnoexcept;

	//����
	MPF_API virtual color_t TakeSample(float u, float v) const;

	//��ȡ��ɫ
	MPF_API color_t GetColor() const mnoexcept;
	//������ɫ
	MPF_API void SetColor(color_t color) mnoexcept;

	//��ȡ����
	MPF_API DECLARE_GETTYPE(ImageBrush)
	MPF_API DECLARE_GETINSTANTTYPE(ImageBrush)
private:
	//��ɫ��Ĭ�Ϻ�ɫ��
	color_t color = 0xFF000000;

	DECLARE_TYPE(ImageBrush)
};

NS_ED
NS_ED