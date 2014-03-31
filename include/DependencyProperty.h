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
		:name(name), value()
	{

	}

	//���� DependencyProperty ����ʵ��
	DependencyProperty(const String& name, const TValue& value)
		:name(name), value(value)
	{

	}

	//���� DependencyProperty ����ʵ��
	DependencyProperty(const String& name, TValue&& value)
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
		return value;
	}

	//��ȡֵ
	TValue& GetValue()
	{
		return value;
	}

	//����ֵ
	void SetValue(const TValue& value)
	{
		this->value = value;
	}
private:
	String name;
	TValue value;
};

NS_ED