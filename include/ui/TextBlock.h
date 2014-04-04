#pragma once
#include "UIElement.h"
#include "../visual/BitmapData.h"
#include "../visual/Font.h"
#include "../visual/Brush.h"

NS_MPF
NS_UI

//�ı���
class TextBlock : public UIElement
{
public:
	MPF_API TextBlock();
	MPF_API TextBlock(const MPF::String& text);
	MPF_API TextBlock(MPF::String&& text);
	MPF_API virtual ~TextBlock();

	//��ȡ����
	MPF_API const MPF::String& GetText() const;
	//��������
	MPF_API void SetText(const MPF::String& value);
	//��������
	MPF_API void SetText(MPF::String&& value);
	//��ȡ����������
	mproperty(MPF::String, Text);

	//��ȡ����
	MPF_API const MPF::Visual::Font& GetFont() const;
	//��������
	MPF_API void SetFont(const MPF::Visual::Font& value);
	//��������
	MPF_API void SetFont(MPF::Visual::Font&& value);
	//��ȡ����������
	mproperty(MPF::Visual::Font, Font);

	//��ȡǰ����ˢ
	MPF_API const MPF::Visual::Brush* GetForeground() const;
	//����ǰ����ˢ
	MPF_API void SetForeground(const MPF::Visual::Brush* value);
	//��ȡ������ǰ����ˢ
	mproperty(const MPF::Visual::Brush*, Foreground);

	//��ȡ����
	MPF_API DECLARE_GETTYPE(TextBlock);
	MPF_API DECLARE_GETINSTANTTYPE(TextBlock);
public:
	//����
	MPF_API static DependencyProperty<MPF::String> TextProperty;
	//����
	MPF_API static DependencyProperty<MPF::Visual::Font> FontProperty;
	//ǰ����ˢ
	MPF_API static DependencyProperty<const MPF::Visual::Brush*> ForegroundProperty;
protected:
	MPF_API virtual void UpdateCore(MPF::Visual::RenderCoreProvider& renderer, UpdateArgs&& args);
	MPF_API virtual void RenderCore(MPF::Visual::RenderCoreProvider& renderer, RenderArgs&& args);
	//�Զ������С
	MPF_API virtual MPF::Visual::Size AutoMeasureSize() mnoexcept;

	DECLARE_UI_FUNCS
private:
	void AddPropertyHandlers();
	void OnTextChanged();
	void UpdateTextGlyphs();
	void EnsureTextGlyphs();
private:
	std::unique_ptr<MPF::Visual::BitmapData<byte>> textGlyphs;

	DECLARE_UI_VALUES
	DECLARE_TYPE(TextBlock)
};

NS_ED
NS_ED