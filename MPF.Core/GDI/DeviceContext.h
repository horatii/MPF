#pragma once
#include <windef.h>

NS_MPF
NS_GDI

//�豸������
class DeviceContext
{
public:
	//���� DeviceContext ����ʵ��
	DeviceContext();
	//����
	virtual ~DeviceContext();

	//��ȡ HDC
	HDC GetNativeHandle() const mnoexcept;

	//������ɫ

	//�Ӵ��ڿͻ��˻�ȡ
	static std::unique_ptr<DeviceContext> FromWindowClient(HWND hWnd);
	//���������豸������
	static std::unique_ptr<DeviceContext> CreateCompatible(HDC hDC);
protected:
private:
	HDC hDC = nullptr;
	HWND hWnd = nullptr;
	bool isOwner = false;
};

NS_ED
NS_ED