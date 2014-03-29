#pragma once
#include "../../include/visual/NativeWindow.h"

NS_MPF
NS_GDI

//设备上下文
class DeviceContext : public Object
{
public:
	//创建 DeviceContext 的新实例
	DeviceContext();
	//析构
	virtual ~DeviceContext();

	//获取 HDC
	HDC GetNativeHandle() const mnoexcept;

	//设置颜色

	//从窗口客户端获取
	static std::shared_ptr<DeviceContext> FromWindowClient(HWND hWnd);
	//创建兼容设备上下文
	static std::shared_ptr<DeviceContext> CreateCompatible(HDC hDC);

	//获取类型
	DECLARE_GETTYPE(DeviceContext)
protected:
private:
	HDC hDC = nullptr;
	HWND hWnd = nullptr;
	bool isOwner = false;
	DECLARE_TYPE(DeviceContext)
};

NS_ED
NS_ED