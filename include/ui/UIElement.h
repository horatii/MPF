#pragma once
#include "../Type.h"
#include "../DependencyObject.h"
#include "Visibility.h"
#include "../visual/RenderCoreProvider.h"

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

	MPF_API void Render(MPF::Visual::RenderCoreProvider& renderer);
	MPF_API void Update(MPF::Visual::RenderCoreProvider& renderer, float elapsedTime);

	//��ȡ����
	MPF_API DECLARE_GETTYPE(UIElement)
	MPF_API DECLARE_GETINSTANTTYPE(UIElement)
public:
	//���
	MPF_API static DependencyProperty<float> WidthPropery;
	//�߶�
	MPF_API static DependencyProperty<float> HeightPropery;
	//�ɼ���
	MPF_API static DependencyProperty<MPF::UI::Visibility> VisibilityPropery;
protected:
	MPF_API virtual void RenderCore(MPF::Visual::RenderCoreProvider& renderer);
	MPF_API virtual void UpdateCore(MPF::Visual::RenderCoreProvider& renderer, float elapsedTime);
protected:
	DECLARE_UI_FUNCS
private:
	DECLARE_UI_VALUES
	DECLARE_TYPE(UIElement)
};

NS_ED
NS_ED