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
	MPF_API std::weak_ptr<UIElement> GetContent() const;
	//��������
	MPF_API void SetContent(std::weak_ptr<UIElement> value);
	//��ȡ����������
	mproperty(std::weak_ptr<UIElement>, Content);

	//��ȡ����
	MPF_API DECLARE_GETTYPE(ContentElement)
	MPF_API DECLARE_GETINSTANTTYPE(ContentElement)
public:
	//����
	MPF_API static DependencyProperty<std::weak_ptr<UIElement>> ContentPropery;
protected:
	MPF_API virtual void RenderCore(MPF::Visual::RenderCoreProvider& renderer);
	MPF_API virtual void UpdateCore(MPF::Visual::RenderCoreProvider& renderer, float elapsedTime);
protected:
	DECLARE_UI_FUNCS
private:
	DECLARE_UI_VALUES
	DECLARE_TYPE(ContentElement)
};

NS_ED
NS_ED