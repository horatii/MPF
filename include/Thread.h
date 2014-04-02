#pragma once
#include "Type.h"
#include "String.h"
#include "Event.h"

NS_MPF

class Thread;

//�߳���������
struct ThreadStartParameter
{
	Thread* thread;
	void* param;

	ThreadStartParameter(Thread* thread, void* param)
		:thread(thread), param(param)
	{

	}
};

//�߳�
class Thread : public Object
{
public:
	//���� Thread ����ʵ��
	MPF_API Thread(std::function<void(void*)> startup);

	//���� Thread ʵ��
	MPF_API ~Thread();

	Thread(Thread&) = delete;

	//����
	MPF_API void Start(void* param = nullptr);
	//����
	MPF_API void Suspend();
	//����
	MPF_API void Resume();
	//ֹͣ
	MPF_API void Abort();

	//δ�����쳣
	Event<UncaughtExceptionEventHandler> UncaughtException;

	//��ȡ����
	MPF_API DECLARE_GETTYPE(Thread)
protected:
	MPF_API void OnUncaughtException(bool& isHandled) const;
private:
	static dword_t _stdcall Invoke(void* startParam);
private:
	std::function<void(void*)> startup;
	std::shared_ptr<ThreadStartParameter> startParam;
	handle_t handle = nullptr;
	//�߳� Id
	dword_t threadId = 0;
	bool isSuspend = false;
	DECLARE_TYPE(Thread)
};

NS_ED