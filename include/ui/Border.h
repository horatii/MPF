#pragma once
#include "ContentElement.h"
#include "../visual/Brush.h"

NS_MPF
NS_UI

//�߿�
class Border : public ContentElement
{
public:
	MPF_API Border();
	MPF_API virtual ~Border();

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
	//�����С
	MPF_API virtual MPF::Visual::Size MeasureSize();

	//��ȡ����
	DECLARE_GETTYPE(Border);
	DECLARE_GETINSTANTTYPE(Border);
public:
	//�߿�ˢ
	MPF_API static DependencyProperty<const MPF::Visual::Brush*> BorderBrushProperty;
	//�߿���
	MPF_API static DependencyProperty<MPF::Visual::Thickness> BorderThicknessProperty;
protected:
	MPF_API virtual void RenderCore(MPF::Visual::RenderCoreProvider& renderer, RenderArgs&& args);
	MPF_API virtual MPF::Visual::Quad MeasureContentBound(UIElement& elem);

	DECLARE_UI_FUNCS
private:
	DECLARE_UI_VALUES
	DECLARE_TYPE(Border);
};

NS_ED
NS_ED