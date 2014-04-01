#pragma once
#include "../Type.h"
#include "../DependencyObject.h"
#include "Visibility.h"
#include "../visual/RenderCoreProvider.h"
#include "RenderArgs.h"
#include "../visual/Thickness.h"
#include "../visual/Size.h"

NS_MPF
NS_UI

class UIElement : public DependencyObject
{
public:
	MPF_API UIElement();
	MPF_API virtual ~UIElement();

	//����
	MPF_API virtual void Initialize();

	//��ȡ���
	MPF_API float GetWidth() const;
	//���ÿ��
	MPF_API void SetWidth(float value);
	//��ȡ�����ÿ��
	mproperty(float, Width);

	//��ȡ�߶�
	MPF_API float GetHeight() const;
	//���ø߶�
	MPF_API void SetHeight(float value);
	//��ȡ�����ø߶�
	mproperty(float, Height);

	//��ȡ�ɼ���
	MPF_API Visibility GetVisibility() const;
	//���ÿɼ���
	MPF_API void SetVisibility(Visibility value);
	//��ȡ�����ÿɼ���
	mproperty(Visibility, Visibility);

	//��ȡ�߾�
	MPF_API MPF::Visual::Thickness GetMargin() const;
	//���ñ߾�
	MPF_API void SetMargin(const MPF::Visual::Thickness& value);
	//��ȡ�����ñ߾�
	mproperty(MPF::Visual::Thickness, Margin);

	//��ȡ����
	MPF_API MPF::Visual::Thickness GetPadding() const;
	//��������
	MPF_API void SetPadding(const MPF::Visual::Thickness& value);
	//��ȡ����������
	mproperty(MPF::Visual::Thickness, Padding);

	MPF_API void Render(MPF::Visual::RenderCoreProvider& renderer, RenderArgs&& args);
	MPF_API void Update(MPF::Visual::RenderCoreProvider& renderer, float elapsedTime);
	//�����Χ�ı���
	MPF_API virtual MPF::Visual::Quad MeasureBound();
	//�����С
	MPF_API virtual MPF::Visual::Size MeasureSize();

	//��ȡ����
	MPF_API DECLARE_GETTYPE(UIElement)
	MPF_API DECLARE_GETINSTANTTYPE(UIElement)
public:
	//���
	MPF_API static DependencyProperty<float> WidthProperty;
	//�߶�
	MPF_API static DependencyProperty<float> HeightProperty;
	//�ɼ���
	MPF_API static DependencyProperty<MPF::UI::Visibility> VisibilityProperty;
	//�߾�
	MPF_API static DependencyProperty<MPF::Visual::Thickness> MarginProperty;
	//����
	MPF_API static DependencyProperty<MPF::Visual::Thickness> PaddingProperty;
protected:
	MPF_API virtual void RenderCore(MPF::Visual::RenderCoreProvider& renderer, RenderArgs&& args);
	MPF_API virtual void UpdateCore(MPF::Visual::RenderCoreProvider& renderer, float elapsedTime);
protected:
	DECLARE_UI_FUNCS
private:
	DECLARE_UI_VALUES
	DECLARE_TYPE(UIElement)
};

NS_ED
NS_ED