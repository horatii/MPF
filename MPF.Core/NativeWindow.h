#pragma once
#include "../include/Type.h"
#include "../include/Event.h"
#include "../include/visual/RenderCoreProviders.h"
#include "../include/input/InputEventHandlers.h"
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
	uint GetWidth() const;
	//���ÿ��
	void SetWidth(uint width);

	//��ȡ�߶�
	uint GetHeight() const;
	//���ø߶�
	void SetHeight(uint height);

	//��ȡ�ͻ������
	uint GetClientWidth() const;

	//��ȡ�ͻ����߶�
	uint GetClientHeight() const;

	//��ȡ������ʶ��
	handle_t GetNativeHandle() const;

	//���� RenderCoreProvider
	std::unique_ptr<RenderCoreProvider> CreateRenderCoreProvider(RenderCoreProviders provider);

	//�����¼�
	Event<PaintEventHandler> Paint;
	//������¼�
	Event<MPF::Input::MouseEventHandler> MouseClick;
private:
	//���ڹ���
	LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	LRESULT OnPaint() const;
	LRESULT OnMouseLeftButtonUp(WPARAM wParam, LPARAM lParam) const;
private:
	static void CreateWindowClass();
	static LRESULT CALLBACK WindowProcWrapper(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
private:
	HWND hWnd = nullptr;
};

NS_ED
NS_ED