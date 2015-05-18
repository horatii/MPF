#pragma once
#include "Type.h"
#include "String.h"
#include "Event.h"

NS_MPF

//MPF �������
typedef void(_stdcall*MPFMainHandler)();

//Ӧ�ó���
class Application : Object
{
public:
	// ���� Application ����ʵ��
	MPF_API Application();
	MPF_API ~Application();

	Application(const Application& app) = delete;
	const Application& operator=(const Application& app) = delete;

	// ��ʼ����
	MPF_API void Run();

	// ��ȡӦ�ó���ı�����ʶ��
	MPF_API handle_t GetNativeHandle() const;

	// ��ȡ������
	MPF_API String GetCommandLines() const;

	//��ȡ��ǰ Application
	MPF_API static Application& GetCurrent();

	// δ�����쳣
	Event<UncaughtExceptionEventHandler> UncaughtException;

	// ��ȡ����
	MPF_API DECLARE_GETTYPE(Application)
protected:
	MPF_API virtual void OnFrame();
private:
	void OnUncaughtException(bool& isHandled) const;
	bool DoFrame();
private:
	DECLARE_TYPE(Application)
};

NS_ED

extern "C" MPF_API int _stdcall MPFStartup(MPF::MPFMainHandler handler);
extern "C" MPF_API int _stdcall MPFConsoleStartup(MPF::MPFMainHandler handler);