#pragma once
#include "../Type.h"
#include "../Binding.h"
#include "TemplateBinding.h"

NS_MPF
NS_UI

class UIElement;

//�ؼ�ģ��
class ControlTemplate : public Object
{
public:
	MPF_API ControlTemplate(UIElement& element);
	MPF_API virtual ~ControlTemplate();

	//��ȡģ��
	MPF_API UIElement& GetTemplate() const mnoexcept;
	//����ģ��
	MPF_API void SetTemplate(UIElement& element) mnoexcept;
	//��ȡ������ģ��
	mproperty(UIElement&, Template);

	//����ģ���
	template<typename T>
	void SetTemplateBinding(UIElement& element, DependencyProperty<T>& property)
	{

	}

	//��ȡ����
	MPF_API DECLARE_GETTYPE(ControlTemplate);
	MPF_API DECLARE_GETINSTANTTYPE(ControlTemplate);
private:
	UIElement* element;
	
	DECLARE_TYPE(ControlTemplate);
};

NS_ED
NS_ED