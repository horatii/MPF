#pragma once
#include "TextBlock.h"

NS_MPF
NS_UI

//����UIԪ��
class ContentElement : public TextBlock
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

	//��ȡ������ˢ
	MPF_API const MPF::Visual::Brush* GetBackground() const;
	//���ñ�����ˢ
	MPF_API void SetBackground(const MPF::Visual::Brush* value);
	//��ȡ�����ñ�����ˢ
	mproperty(const MPF::Visual::Brush*, Background);

	using TextBlock::HitTest;
	MPF_API virtual bool HitTest(MPF::Visual::Point point, std::vector<UIElement*>& elements) noexcept;

	//��ȡ����
	MPF_API DECLARE_GETTYPE(ContentElement);
	MPF_API DECLARE_GETINSTANTTYPE(ContentElement);
	DECLARE_PUB_UI_FUNCS;
public:
	//����
	MPF_API static DependencyProperty<UIElement*> ContentProperty;
	//����
	MPF_API static DependencyProperty<const MPF::Visual::Brush*> BackgroundProperty;
protected:
	MPF_API virtual void RenderCore(MPF::Visual::RenderCoreProvider& renderer, const RenderArgs& args);
	MPF_API virtual void UpdateCore(MPF::Visual::RenderCoreProvider& renderer, const UpdateArgs& args);
	MPF_API virtual MPF::Visual::Point MakeContentOffset(UIElement& elem);
	//�Զ������С
	MPF_API virtual MPF::Visual::Size AutoMeasureSize() noexcept;
protected:
	DECLARE_UI_FUNCS
private:
	DECLARE_UI_VALUES
	DECLARE_TYPE(ContentElement)
};

NS_ED
NS_ED