#pragma once
#include "Brush.h"

NS_MPF
NS_VSL

//�̶���ɫ��ˢ
class SolidColorBrush : public Brush
{
public:
	//���� SolidColorBrush ����ʵ��
	MPF_API SolidColorBrush() mnoexcept;

	//���� SolidColorBrush ����ʵ��
	MPF_API SolidColorBrush(color_t color) mnoexcept;

	//����
	MPF_API virtual color_t TakeSample(float u, float v) const;

	//��ȡ��ɫ
	MPF_API color_t GetColor() const mnoexcept;
	//������ɫ
	MPF_API void SetColor(color_t color) mnoexcept;

	//��ȡ����
	MPF_API DECLARE_GETTYPE(SolidColorBrush)
	MPF_API DECLARE_GETINSTANTTYPE(SolidColorBrush)
private:
	//��ɫ��Ĭ�Ϻ�ɫ��
	color_t color = 0xFF000000;

	DECLARE_TYPE(SolidColorBrush)
};

NS_ED
NS_ED