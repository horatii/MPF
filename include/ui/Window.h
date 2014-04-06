#pragma once
#include "ContentElement.h"
#include "../visual/RenderCoreProviders.h"

NS_MPF
NS_VSL
class NativeWindow;
NS_ED

NS_UI

//����
class Window : public ContentElement
{
public:
	//���� Brush ����ʵ��
	MPF_API Window();
	MPF_API virtual ~Window();

	//����
	MPF_API virtual void Initialize(MPF::Visual::RenderCoreProviders provider = 
		MPF::Visual::RenderCoreProviders::GDI);

	//��ȡ����
	MPF_API const MPF::String& GetTitle() const;
	//���ñ���
	MPF_API void SetTitle(const MPF::String& value);
	//���ñ���
	MPF_API void SetTitle(MPF::String&& value);
	//��ȡ�����ñ���
	mproperty(MPF::String, Title);

	//��ʾ
	MPF_API void Show();

	//����֡
	MPF_API void DoFrame();

	//��ȡ����
	MPF_API DECLARE_GETTYPE(Window);
	MPF_API DECLARE_GETINSTANTTYPE(Window);
	DECLARE_PUB_UI_FUNCS;
public:
	//����
	MPF_API static DependencyProperty<MPF::String> TitleProperty;
protected:
	//������Ը��ڵ��ƫ��
	MPF_API virtual void UpdateRelativeOffset() mnoexcept;
	DECLARE_UI_FUNCS
private:
	void InitializeNativeWindowEventHandlers();
private:
	std::unique_ptr<MPF::Visual::NativeWindow> nativeWindow;
	std::unique_ptr<MPF::Visual::RenderCoreProvider> renderer;
	DECLARE_UI_VALUES
	DECLARE_TYPE(Window)
};

NS_ED
NS_ED