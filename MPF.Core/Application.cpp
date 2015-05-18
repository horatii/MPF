#include "stdafx.h"
#include "../include/Application.h"
#include "../include/platform.h"
#include "../include/diagnostic/Stopwatch.h"
#include <iostream>

using namespace MPF;

DEFINE_TYPE(Application, MPF::Application)
//��ǰ Application
namespace
{
	Application* currentApp = nullptr;
}

Application::Application()
{
	if (currentApp)
		THROW_IF_NOT(!currentApp, "An application has already been instanced.");
	currentApp = this;
}

Application::~Application()
{

}

Application& Application::GetCurrent()
{
	if (currentApp)
		THROW_IF_NOT(currentApp, "None application has been instanced.");
	return *currentApp;
}

handle_t Application::GetNativeHandle() const
{
	return (handle_t)GetModuleHandle(nullptr);
}

void Application::OnUncaughtException(bool& isHandled) const
{
	UncaughtException([&](UncaughtExceptionEventHandler handler)
	{
		handler(isHandled);
	});
}

String Application::GetCommandLines() const
{
	return String(GetCommandLine());
}

bool Application::DoFrame()
{
	MSG msg;
	if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
	{
		if (msg.message == WM_QUIT)
			return true;
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	OnFrame();
	return false;
}

void Application::Run()
{
	Stopwatch watch;

	// ����״�� 60 ֡ÿ��
	const DWORD desiredDelta = 1000 / 30;
	// ��һ��ÿ֡��ʱ
	DWORD lastDelta = desiredDelta;
	while (true)
	{
		try
		{
			watch.Restart();
			if (DoFrame()) break;
			// ��֡��ʱ
			lastDelta = static_cast<DWORD>(watch.Stop() * 1000);
			// Sleep ʣ��ʱ��
			if (lastDelta < desiredDelta)
				Sleep(desiredDelta - lastDelta);
		}
		catch (...)
		{
			bool handled = false;
			OnUncaughtException(handled);
			// �쳣δ����
			if (!handled)
				throw;
		}
	}
}

void Application::OnFrame()
{

}

int _stdcall MPFStartup(MPFMainHandler handler)
{
	handler();
	return 0;
}

int _stdcall MPFConsoleStartup(MPFMainHandler handler)
{
	std::locale::global(std::locale(""));
	handler();
	return 0;
}