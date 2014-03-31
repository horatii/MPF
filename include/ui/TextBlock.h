#pragma once
#include "UIElement.h"
#include "../visual/BitmapData.h"
#include "../visual/Font.h"

NS_MPF
NS_UI

//�ı���
class TextBlock : public UIElement
{
public:
	MPF_API TextBlock();
	MPF_API TextBlock(const MPF::String& text);
	MPF_API virtual ~TextBlock();

	//��ȡ����
	MPF_API const MPF::String& GetText() const;
	//��������
	MPF_API void SetText(const MPF::String& value);
	//��ȡ����������
	mproperty(MPF::String, Text);

	//��ȡ����
	MPF_API const MPF::Visual::Font& GetFont() const;
	//��������
	MPF_API void SetFont(const MPF::Visual::Font& value);
	//��ȡ����������
	mproperty(MPF::Visual::Font, Font);

	//��ȡ����
	MPF_API DECLARE_GETTYPE(TextBlock);
	MPF_API DECLARE_GETINSTANTTYPE(TextBlock);
public:
	//����
	MPF_API static DependencyProperty<MPF::String> TextProperty;
	//����
	MPF_API static DependencyProperty<MPF::Visual::Font> FontProperty;
protected:
	MPF_API virtual void UpdateCore(MPF::Visual::RenderCoreProvider& renderer, float elapsedTime);
	MPF_API virtual void RenderCore(MPF::Visual::RenderCoreProvider& renderer, RenderArgs&& args);
	//�����С
	MPF_API virtual MPF::Visual::Quad MeasureSize();

	DECLARE_UI_FUNCS
private:
	void AddPropertyHandlers();
	void OnTextChanged();
	void UpdateTextGlyphs();
private:
	std::unique_ptr<MPF::Visual::BitmapData<byte>> textGlyphs;

	DECLARE_UI_VALUES
	DECLARE_TYPE(TextBlock)
};

NS_ED
NS_ED