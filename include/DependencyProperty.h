#pragma once
#include "Type.h"

NS_MPF

//��������
template<typename TValue>
class DependencyProperty
{
public:
	//���� DependencyProperty ����ʵ��
	DependencyProperty(const String& name)
		:name(name), value(std::make_shared<TValue>())
	{

	}

	//���� DependencyProperty ����ʵ��
	DependencyProperty(const String& name, const TValue& value)
		:name(name), value(std::make_shared<TValue>(value))
	{

	}

	//���� DependencyProperty ����ʵ��
	DependencyProperty(const String& name, TValue&& value)
		:name(name), value(std::make_shared<TValue>(value))
	{

	}

	//���� DependencyProperty ����ʵ��
	DependencyProperty(const String& name, std::shared_ptr<TValue> value)
		:name(name), value(value)
	{

	}

	//��ȡ��������
	const String& GetName() const
	{
		return name;
	}

	//��ȡֵ
	const TValue& GetValue() const
	{
		return *value;
	}

	//��ȡֵ
	TValue& GetValue()
	{
		return *value;
	}
private:
	String name;
	std::shared_ptr<TValue> value;
};

NS_ED