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

	//��ȡ����
	MPF_API DECLARE_GETTYPE(Canvas);
	MPF_API DECLARE_GETINSTANTTYPE(Canvas);
public:
	//������
	MPF_API static DependencyProperty<float> LeftProperty;
	//������
	MPF_API static DependencyProperty<float> TopProperty;
protected:
	MPF_API virtual void RenderCore(MPF::Visual::RenderCoreProvider& renderer, RenderArgs&& args);
protected:
	DECLARE_UI_FUNCS
private:
	DECLARE_UI_VALUES
	DECLARE_TYPE(Canvas)
};

NS_ED
NS_ED