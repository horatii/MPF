#pragma once
#include "../include/Type.h"
#include "../include/Event.h"
#include "../include/visual/RenderCoreProviders.h"
#include "NativeEvents.h"
#include <windef.h>

NS_MPF
NS_VSL

class RenderCoreProvider;

//ϵͳ����
class NativeWindow
{
public:
	//���� NativeWindow ����ʵ��
	NativeWindow();
	~NativeWindow();

	//����
	void Create();
	//��ʾ
	void Show() const;

	//��ȡ����
	String GetTitle() const;
	//���ñ���
	void SetTitle(const String& title);

	//��ȡ���
	uint32_t GetWidth() const;
	//���ÿ��
	void SetWidth(uint32_t width);

	//��ȡ�߶�
	uint32_t GetHeight() const;
	//���ø߶�
	void SetHeight(uint32_t height);

	//��ȡ�ͻ������
	uint32_t GetClientWidth() const;

	//��ȡ�ͻ����߶�
	uint32_t GetClientHeight() const;

	//��ȡ������ʶ��
	handle_t GetNativeHandle() const;

	//���� RenderCoreProvider
	std::unique_ptr<RenderCoreProvider> CreateRenderCoreProvider(RenderCoreProviders provider);

	// �����¼�
	Event<PaintEventHandler> Paint;
	// �������ͷŵ���¼�
	Event<MPF::Input::NativeMouseEventHandler> MouseLeftButtonUp;
	// ���������µ���¼�
	Event<MPF::Input::NativeMouseEventHandler> MouseLeftButtonDown;
private:
	//���ڹ���
	LRESULT CALLBACK WindowProc(HWND hWnd, uint32_t uMsg, WPARAM wParam, LPARAM lParam);
	LRESULT OnPaint() const;
	LRESULT OnMouseLeftButtonUp(WPARAM wParam, LPARAM lParam) const;
	LRESULT OnMouseLeftButtonDown(WPARAM wParam, LPARAM lParam) const;
private:
	static void CreateWindowClass();
	static LRESULT CALLBACK WindowProcWrapper(HWND hWnd, uint32_t uMsg, WPARAM wParam, LPARAM lParam);
private:
	HWND hWnd = nullptr;
};

NS_ED
NS_ED