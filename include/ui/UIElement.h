#pragma once
#include "../Type.h"
#include "../DependencyObject.h"
#include "Visibility.h"
#include "../visual/RenderCoreProvider.h"
#include "RenderArgs.h"
#include "../visual/Thickness.h"
#include "../visual/Size.h"
#include "../RoutedEvent.h"
#include "../RoutedEventArgs.h"
#include "../EventWrapper.h"
#include "../input/InputEventHandlers.h"
#include "ControlTemplate.h"

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
	MPF_API const MPF::Visual::Thickness& GetMargin() const;
	//���ñ߾�
	MPF_API void SetMargin(const MPF::Visual::Thickness& value);
	//��ȡ�����ñ߾�
	mproperty(MPF::Visual::Thickness, Margin);

	//��ȡ����
	MPF_API const MPF::Visual::Thickness& GetPadding() const;
	//��������
	MPF_API void SetPadding(const MPF::Visual::Thickness& value);
	//��ȡ����������
	mproperty(MPF::Visual::Thickness, Padding);

	//��ȡģ��
	MPF_API ControlTemplate GetTemplate() const;
	//����ģ��
	MPF_API void SetTemplate(ControlTemplate&& value);
	//��ȡ������ģ��
	mproperty(ControlTemplate, Template);

	MPF_API UIElement* GetParent() const mnoexcept{ return parent; }

	//�������ͷ�ʱ�����¼�
	EventWrapper<UIElement, MPF::Input::MouseEventHandler, MPF::Input::MouseEventArgs> MouseLeftButtonUp;

	MPF_API void Render(MPF::Visual::RenderCoreProvider& renderer, RenderArgs&& args);
	MPF_API void Update(MPF::Visual::RenderCoreProvider& renderer, UpdateArgs&& args);

	MPF_API MPF::Visual::Size MeasureSize() mnoexcept;
	MPF_API MPF::Visual::Quad GetRenderBound() const mnoexcept;
	///<summary>�������</summary>
	///<return>���Գɹ���UIԪ�أ������߼����ϴӶ��˵��׶�����</return>
	MPF_API std::vector<UIElement*> HitTest(MPF::Visual::Point point) mnoexcept;
	MPF_API virtual bool HitTest(MPF::Visual::Point point, std::vector<UIElement*>& elements) mnoexcept;

	//�����¼�
	template<typename THandler, typename TArgs>
	static void RaiseEvent(const RoutedEvent<THandler>& ent, TArgs& args)
	{
		RaiseEventInternal(ent, args);
	}

	//��ȡ����
	MPF_API DECLARE_GETTYPE(UIElement);
	MPF_API DECLARE_GETINSTANTTYPE(UIElement);
	DECLARE_PUB_UI_FUNCS;
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
	//ģ��
	MPF_API static DependencyProperty<ControlTemplate> TemplateProperty;
	//�������ͷ�ʱ�����¼�
	MPF_API static RoutedEvent<MPF::Input::MouseEventHandler> MouseLeftButtonUpEvent;
protected:
	MPF_API virtual void RenderCore(MPF::Visual::RenderCoreProvider& renderer, RenderArgs&& args);
	MPF_API virtual void UpdateCore(MPF::Visual::RenderCoreProvider& renderer, UpdateArgs&& args);
	MPF_API virtual void OnMouseLeftButtonUp(MPF::Input::MouseEventArgs& args);
protected:
	//������Ը��ڵ��ƫ��
	MPF_API virtual void UpdateRelativeOffset() mnoexcept;
	///<summary>������Ⱦ����</summary>
	///<param name="parentOffset">���ڵ�ľ���ƫ��</param>
	MPF_API virtual void UpdateRenderBound(MPF::Visual::Point parentOffset) mnoexcept;
	//���´�С
	MPF_API virtual void UpdateSize() mnoexcept;
	//�Զ������С
	MPF_API virtual MPF::Visual::Size AutoMeasureSize() mnoexcept;

	DECLARE_UI_FUNCS
protected:
	//��Ⱦ����
	std::pair<bool, MPF::Visual::Quad> renderBound = { true, MPF::Visual::Quad()};
	//��Ը��ڵ��ƫ��
	std::pair<bool, MPF::Visual::Point> relativeOffset = { true, MPF::Visual::Point() };
	//��С
	std::pair<bool, MPF::Visual::Size> size = { true, MPF::Visual::Size() };
protected:
	MPF_API static void RaiseEventInternal(const IRoutedEvent& ent, RoutedEventArgs& args);
	MPF_API static void SetParent(UIElement& element, UIElement* parent) mnoexcept;
private:
	void InitializeEventHandlers();
private:
	UIElement* parent = nullptr;
	std::unique_ptr<TemplateInstance> templateInst;
	UIElement* templateRoot = nullptr;
	DECLARE_UI_VALUES
	DECLARE_TYPE(UIElement)
};

NS_ED
NS_ED