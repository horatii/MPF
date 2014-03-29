#pragma once
#include "Type.h"

NS_MPF

//��������
template<typename TValue>
class DependencyProperty
{
public:
	//���� DependencyProperty ����ʵ��
	DependencyProperty(std::shared_ptr<String> name)
		:name(name), value(std::make_shared<TValue>())
	{

	}

	//���� DependencyProperty ����ʵ��
	DependencyProperty(std::shared_ptr<String> name, const TValue& value)
		:name(name), value(std::make_shared<TValue>(value))
	{

	}

	//���� DependencyProperty ����ʵ��
	DependencyProperty(std::shared_ptr<String> name, TValue&& value)
		:name(name), value(std::make_shared<TValue>(value))
	{

	}

	//���� DependencyProperty ����ʵ��
	DependencyProperty(std::shared_ptr<String> name, std::shared_ptr<TValue> value)
		:name(name), value(value)
	{

	}

	//��ȡ��������
	std::shared_ptr<String> GetName() const
	{
		return name;
	}

	//��ȡֵ
	const TValue& GetValue() const
	{
		return *value;
	}
private:
	std::shared_ptr<String> name;
	std::shared_ptr<TValue> value;
};

NS_ED