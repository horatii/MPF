#pragma once
#include "UIElement.h"

NS_MPF
NS_UI

//����UIԪ��
class ContentElement : public UIElement
{
public:
	MPF_API ContentElement();
	MPF_API virtual ~ContentElement();

	//��ȡ����
	MPF_API UIElement* GetContent() const;
	//��������
	MPF_API void SetContent(UIElement* value);
	//��ȡ����������
	mproperty(UIElement*, Content);

	//��ȡ����
	MPF_API DECLARE_GETTYPE(ContentElement)
	MPF_API DECLARE_GETINSTANTTYPE(ContentElement)
public:
	//����
	MPF_API static DependencyProperty<UIElement*> ContentProperty;
protected:
	MPF_API virtual void RenderCore(MPF::Visual::RenderCoreProvider& renderer, RenderArgs&& args);
	MPF_API virtual void UpdateCore(MPF::Visual::RenderCoreProvider& renderer, float elapsedTime);
protected:
	DECLARE_UI_FUNCS
private:
	DECLARE_UI_VALUES
	DECLARE_TYPE(ContentElement)
};

NS_ED
NS_ED