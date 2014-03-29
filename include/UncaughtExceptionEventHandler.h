#pragma once
#include "Delegate.h"

NS_MPF

//δ�����쳣�¼�����
class UncaughtExceptionEventHandler : public Delegate
{
public:
	MPF_API UncaughtExceptionEventHandler(std::function<void(bool&)> handler) mnoexcept;

	//����
	MPF_API void Invoke(bool& isHandled) const;

	//����
	MPF_API void operator()(bool& isHandled) const;

	//��ȡ����
	MPF_API DECLARE_GETTYPE(UncaughtExceptionEventHandler)
private:
	std::function<void(bool&)> handler;
	DECLARE_TYPE(UncaughtExceptionEventHandler)
};

NS_ED