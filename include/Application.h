#pragma once
#include "Type.h"
#include "String.h"
#include "Event.h"
#include "UncaughtExceptionEventHandler.h"

NS_MPF

//MPF �������
typedef void(_stdcall*MPFMainHandler)();

//Ӧ�ó���
class Application : Object
{
public:
	//���� Application ����ʵ��
	MPF_API Application();
	Application(const Application& app) = delete;
	const Application& operator=(const Application& app) = delete;

	//����
	MPF_API void Run(MPFMainHandler handler) const;

	//��ʼ����
	MPF_API void Run() const;

	//��ȡӦ�ó���ı�����ʶ��
	MPF_API handle_t GetNativeHandle() const;

	//��ȡ������
	MPF_API String GetCommandLines() const;

	//��ȡ��ǰ Application
	MPF_API static Application& GetCurrent() mnoexcept;

	//δ�����쳣
	Event<UncaughtExceptionEventHandler> UncaughtException;

	//��ȡ����
	MPF_API DECLARE_GETTYPE(Application)
protected:
	MPF_API void OnUncaughtException(bool& isHandled) const;
private:
private:
	DECLARE_TYPE(Application)
};

NS_ED

extern "C" MPF_API int _stdcall MPFStartup(MPF::MPFMainHandler handler);
extern "C" MPF_API int _stdcall MPFConsoleStartup(MPF::MPFMainHandler handler);