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
	MPF_API AlphaBlendBrush(std::shared_ptr<BitmapData<byte>> alpha, 
		std::shared_ptr<Brush> secondBrush) mnoexcept;

	//����
	MPF_API virtual color_t TakeSample(float u, float v) const;

	//��ȡ Alpha ����
	MPF_API std::shared_ptr<BitmapData<byte>> GetAlpha() const mnoexcept;
	//���� Alpha ����
	MPF_API void SetAlpha(std::shared_ptr<BitmapData<byte>> value) mnoexcept;
	//��ȡ������ Alpha ����
	mproperty(std::shared_ptr<BitmapData<byte>>, Alpha);

	//��ȡ�ڶ� Brush
	MPF_API std::shared_ptr<Brush> GetSecondBrush() const mnoexcept;
	//���õڶ� Brush
	MPF_API void SetSecondBrush(std::shared_ptr<Brush> value) mnoexcept;
	//��ȡ�����õڶ� Brush
	mproperty(std::shared_ptr<Brush>, SecondBrush)

	//��ȡ����
	MPF_API DECLARE_GETTYPE(AlphaBlendBrush);
	MPF_API DECLARE_GETINSTANTTYPE(AlphaBlendBrush);
private:
	std::shared_ptr<BitmapData<byte>> alpha;
	std::shared_ptr<Brush> secondBrush;

	DECLARE_TYPE(AlphaBlendBrush)
};

NS_ED
NS_ED