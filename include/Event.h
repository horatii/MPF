#pragma once
#include "Type.h"
#include "EventHandlers.h"

NS_MPF

//�¼�
template<typename TDelegate>
class Event
{
public:
	//���� Event ����ʵ��
	Event() noexcept
	{

	}

	//���������
	void operator += (TDelegate handler)
	{
		handlers.emplace_back(handler);
	}

	//ɾ��������
	void operator -= (TDelegate handler)
	{
		handlers.erase(std::find(handlers.begin(), handlers.end(), handler));
	}

	//����������
	void operator ()(std::function<void(TDelegate)> func) const
	{
		Invoke(func);
	}
private:
	//����������
	void Invoke(std::function<void(TDelegate)> func) const
	{
		for (auto& handler : handlers)
		{
			func(handler);
		}
	}

	//��������
	std::vector<TDelegate> handlers;
};

NS_ED