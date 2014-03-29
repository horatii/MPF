#pragma once
#include "../Type.h"
#include "BitmapData.h"

NS_MPF
NS_VSL

//��ˢ
class Brush : public Object
{
public:
	//���� Brush ����ʵ��
	MPF_API Brush();

	//����
	MPF_API virtual color_t TakeSample(float u, float v) const = 0;

	//��ȡ����
	MPF_API DECLARE_GETTYPE(Brush)
	MPF_API DECLARE_GETINSTANTTYPE(Brush)
private:
	DECLARE_TYPE(Brush)
};

NS_ED
NS_ED