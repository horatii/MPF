#pragma once
#include "../visual/NativeWindow.h"
#include "ContentElement.h"

NS_MPF
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
	MPF_API DECLARE_GETTYPE(Window)
	MPF_API DECLARE_GETINSTANTTYPE(Window)
public:
	//����
	MPF_API static DependencyProperty<MPF::String> TitleProperty;
protected:
	DECLARE_UI_FUNCS
private:
	std::shared_ptr<MPF::Visual::NativeWindow> nativeWindow;
	std::shared_ptr<MPF::Visual::RenderCoreProvider> renderer;
	DECLARE_UI_VALUES
	DECLARE_TYPE(Window)
};

NS_ED
NS_ED