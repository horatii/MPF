#pragma once
#include "TextBlock.h"

NS_MPF
NS_UI

//内容UI元素
class ContentElement : public TextBlock
{
public:
	MPF_API ContentElement();
	MPF_API virtual ~ContentElement();

	//获取内容
	MPF_API UIElement* GetContent() const;
	//设置内容
	MPF_API void SetContent(UIElement* value);
	//获取或设置内容
	mproperty(UIElement*, Content);
	//计算大小
	MPF_API virtual MPF::Visual::Size MeasureSize();

	//获取背景画刷
	MPF_API const MPF::Visual::Brush* GetBackground() const;
	//设置背景画刷
	MPF_API void SetBackground(const MPF::Visual::Brush* value);
	//获取或设置背景画刷
	mproperty(const MPF::Visual::Brush*, Background);

	//获取类型
	MPF_API DECLARE_GETTYPE(ContentElement)
	MPF_API DECLARE_GETINSTANTTYPE(ContentElement)
public:
	//内容
	MPF_API static DependencyProperty<UIElement*> ContentProperty;
	//背景
	MPF_API static DependencyProperty<const MPF::Visual::Brush*> BackgroundProperty;
protected:
	MPF_API virtual void RenderCore(MPF::Visual::RenderCoreProvider& renderer, RenderArgs&& args);
	MPF_API virtual void UpdateCore(MPF::Visual::RenderCoreProvider& renderer, float elapsedTime);
	MPF_API virtual MPF::Visual::Quad MeasureContentBound(UIElement& elem);
protected:
	DECLARE_UI_FUNCS
private:
	DECLARE_UI_VALUES
	DECLARE_TYPE(ContentElement)
};

NS_ED
NS_ED