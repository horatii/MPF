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
	MPF_API TextBlock(std::shared_ptr<MPF::String> text);
	MPF_API virtual ~TextBlock();

	//��ȡ����
	MPF_API std::shared_ptr<MPF::String> GetText() const;
	//��������
	MPF_API void SetText(std::shared_ptr<MPF::String> value);
	//��ȡ����������
	mproperty(std::shared_ptr<MPF::String>, Text);

	//��ȡ����
	MPF_API std::shared_ptr<MPF::Visual::Font> GetFont() const;
	//��������
	MPF_API void SetFont(std::shared_ptr<MPF::Visual::Font> value);
	//��ȡ����������
	mproperty(std::shared_ptr<MPF::Visual::Font>, Font);

	//��ȡ����
	MPF_API DECLARE_GETTYPE(TextBlock);
	MPF_API DECLARE_GETINSTANTTYPE(TextBlock);
public:
	//����
	MPF_API static DependencyProperty<std::shared_ptr<MPF::String>> TextProperty;
	//����
	MPF_API static DependencyProperty<std::shared_ptr<MPF::Visual::Font>> FontProperty;
protected:
	MPF_API virtual void UpdateCore(MPF::Visual::RenderCoreProvider& renderer, float elapsedTime);
	MPF_API virtual void RenderCore(MPF::Visual::RenderCoreProvider& renderer);

	DECLARE_UI_FUNCS
private:
	void AddPropertyHandlers();
	void OnTextChanged();
	void UpdateTextGlyphs();
private:
	std::shared_ptr<MPF::Visual::BitmapData<byte>> textGlyphs;

	DECLARE_UI_VALUES
	DECLARE_TYPE(TextBlock)
};

NS_ED
NS_ED