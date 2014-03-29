#pragma once
#include "Brush.h"

NS_MPF
NS_VSL

//���Խ�����ɫ��ˢ
class LinearGradientBrush : public Brush
{
public:
	//���� LinearGradientBrush ����ʵ��
	MPF_API LinearGradientBrush(color_t startColor, color_t endColor) mnoexcept;

	//����
	MPF_API virtual color_t TakeSample(float u, float v) const;

	//��ȡ��ɫ
	MPF_API color_t GetStartColor() const mnoexcept;
	//������ɫ
	MPF_API void SetStartColor(color_t color) mnoexcept;
	//��ȡ��ɫ
	MPF_API color_t GetEndColor() const mnoexcept;
	//������ɫ
	MPF_API void SetEndColor(color_t color) mnoexcept;

	//��ȡ����
	MPF_API DECLARE_GETTYPE(LinearGradientBrush)
	MPF_API DECLARE_GETINSTANTTYPE(LinearGradientBrush)
private:
	//��ɫ
	argb_color startColor;
	argb_color endColor;

	DECLARE_TYPE(LinearGradientBrush)
};

NS_ED
NS_ED