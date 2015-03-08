#pragma once
#include "Brush.h"
#include "BitmapData.h"

NS_MPF
NS_VSL

//Alpha��ϻ�ˢ
class AlphaBlendBrush : public Brush
{
public:
	//���� AlphaBlendBrush ����ʵ��
	MPF_API AlphaBlendBrush(const BitmapData<byte>& alpha, 
		const Brush& secondBrush) noexcept;

	//����
	MPF_API virtual color_t TakeSample(float u, float v) const;

	//��ȡ Alpha ����
	MPF_API const BitmapData<byte>& GetAlpha() const noexcept;
	//���� Alpha ����
	MPF_API void SetAlpha(const BitmapData<byte>& value) noexcept;
	//��ȡ������ Alpha ����
	mproperty(const BitmapData<byte>&, Alpha);

	//��ȡ�ڶ� Brush
	MPF_API const Brush& GetSecondBrush() const noexcept;
	//���õڶ� Brush
	MPF_API void SetSecondBrush(const Brush& value) noexcept;
	//��ȡ�����õڶ� Brush
	mproperty(const Brush&, SecondBrush)

	//��ȡ����
	MPF_API DECLARE_GETTYPE(AlphaBlendBrush);
	MPF_API DECLARE_GETINSTANTTYPE(AlphaBlendBrush);
private:
	const BitmapData<byte>* alpha;
	const Brush* secondBrush;

	DECLARE_TYPE(AlphaBlendBrush)
};

NS_ED
NS_ED