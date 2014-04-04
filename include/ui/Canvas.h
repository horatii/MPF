#pragma once
#include "Panel.h"

NS_MPF
NS_UI

//����
class Canvas : public Panel
{
public:
	MPF_API Canvas();
	MPF_API virtual ~Canvas();

	//��ȡ������
	MPF_API static float GetLeft(const UIElement& elem);
	//���ú�����
	MPF_API static void SetLeft(UIElement& elem, float value);
	//��ȡ������
	MPF_API static float GetTop(const UIElement& elem);
	//����������
	MPF_API static void SetTop(UIElement& elem, float value);
	//��ȡ����
	MPF_API static std::pair<float, float> GetPosition(const UIElement& elem);
	//��������
	MPF_API static void SetPosition(UIElement& elem, const std::pair<float, float>& position);

	//��ȡ����
	MPF_API DECLARE_GETTYPE(Canvas);
	MPF_API DECLARE_GETINSTANTTYPE(Canvas);
public:
	//������
	MPF_API static DependencyProperty<float> LeftProperty;
	//������
	MPF_API static DependencyProperty<float> TopProperty;
protected:
	MPF_API virtual MPF::Visual::Point MakeChildOffset(UIElement& elem);
protected:
	DECLARE_UI_FUNCS
private:
	DECLARE_UI_VALUES
	DECLARE_TYPE(Canvas)
};

NS_ED
NS_ED