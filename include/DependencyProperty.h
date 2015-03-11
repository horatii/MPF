#pragma once
#include "Type.h"

NS_MPF

//��������
template<typename TValue>
class DependencyProperty
{
public:
	// ���� DependencyProperty ����ʵ��
	DependencyProperty(const String& name)
		:name(name), value()
	{

	}

	// ���� DependencyProperty ����ʵ��
	DependencyProperty(String&& name)
		:name(std::move(name)), value()
	{

	}

	// ���� DependencyProperty ����ʵ��
	DependencyProperty(const String& name, const TValue& value)
		:name(name), value(value)
	{

	}

	// ���� DependencyProperty ����ʵ��
	DependencyProperty(String&& name, const TValue& value)
		:name(std::move(name)), value(value)
	{

	}

	// ���� DependencyProperty ����ʵ��
	DependencyProperty(const String& name, TValue&& value)
		:name(name), value(std::forward<TValue>(value))
	{

	}

	// ���� DependencyProperty ����ʵ��
	DependencyProperty(String&& name, TValue&& value)
		:name(std::move(name)), value(std::forward<TValue>(value))
	{

	}

	// ��ȡ��������
	const String& GetName() const
	{
		return name;
	}

	mgproperty(const String&, Name);

	// ��ȡֵ
	const TValue& GetValue() const
	{
		return value;
	}

	// ��ȡֵ
	TValue& GetValue()
	{
		return value;
	}
	// ����ֵ
	void SetValue(TValue&& value)
	{
		this->value = std::forward<TValue>(value);
	}
	// ����ֵ
	void SetValue(const TValue& value)
	{
		this->value = value;
	}
	mproperty(const TValue&, Value);
private:
	String name;
	TValue value;
};

NS_ED