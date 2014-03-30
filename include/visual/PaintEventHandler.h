#pragma once
#include "../Delegate.h"

NS_MPF

//�����¼�����
class PaintEventHandler : public Delegate
{
public:
	MPF_API PaintEventHandler(std::function<void()> handler) mnoexcept;

	//����
	MPF_API void Invoke() const;

	//����
	MPF_API void operator()() const;

private:
	std::function<void()> handler;
};

NS_ED