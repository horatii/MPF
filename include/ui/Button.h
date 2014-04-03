#pragma once
#include "ButtonBase.h"
#include "Border.h"

NS_MPF
NS_UI

//��ť
class Button : public ButtonBase
{
public:
	MPF_API Button();
	MPF_API virtual ~Button();

	//��ȡ�߿�ˢ
	MPF_API const MPF::Visual::Brush* GetBorderBrush() const;
	//���ñ߿�ˢ
	MPF_API void SetBorderBrush(const MPF::Visual::Brush* value);
	//��ȡ�����ñ߿�ˢ
	mproperty(const MPF::Visual::Brush*, BorderBrush);

	//��ȡ�߿���
	MPF_API MPF::Visual::Thickness GetBorderThickness() const;
	//���ñ߿���
	MPF_API void SetBorderThickness(const MPF::Visual::Thickness& value);
	//��ȡ�����ñ߿���
	mproperty(MPF::Visual::Thickness, BorderThickness);

	//��ȡ����
	MPF_API DECLARE_GETTYPE(Button);
	MPF_API DECLARE_GETINSTANTTYPE(Button);
protected:

	DECLARE_UI_FUNCS
private:


	DECLARE_UI_VALUES
	DECLARE_TYPE(Button);
};

NS_ED
NS_ED