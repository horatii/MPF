#pragma once
#include "Type.h"
#include "any.h"
#include "DependencyProperty.h"

NS_MPF

//�����������ԵĶ���
class DependencyObject
{
public:
	//���� DependencyObject ����ʵ��
	DependencyObject()
	{

	}

	virtual ~DependencyObject()
	{
		localValues.clear();
		animationValues.clear();
		styleValues.clear();
	}

	//��ȡ��ǰֵ
	template<typename T>
	const T& GetValue(const DependencyProperty<T>& property) const
	{
		auto& name = property.GetName();
		//��⶯��ֵ
		auto it = animationValues.find(name);
		if (it != animationValues.end())
		{
			return it->second;
		}
		//��Ȿ��ֵ
		it = localValues.find(name);
		if (it != localValues.end())
		{
			return it->second;
		}
		//�����ʽֵ
		it = styleValues.find(name);
		if (it != styleValues.end())
		{
			return it->second;
		}
		//���ͨ��ֵ
		return GetCommonValue(property);
	}

	//��ȡ��ǰֵ
	template<typename T>
	T& GetValue(DependencyProperty<T>& property)
	{
		auto& name = property.GetName();
		//��⶯��ֵ
		auto it = animationValues.find(name);
		if (it != animationValues.end())
		{
			return it->second;
		}
		//��Ȿ��ֵ
		it = localValues.find(name);
		if (it != localValues.end())
		{
			return it->second;
		}
		//�����ʽֵ
		it = styleValues.find(name);
		if (it != styleValues.end())
		{
			return it->second;
		}
		//���ͨ��ֵ
		return GetCommonValue(property);
	}

	//���ñ���ֵ
	template<typename T>
	void SetValue(const DependencyProperty<T>& property, T&& value)
	{
		auto& name = property.GetName();
		//��Ȿ��ֵ
		auto it = localValues.find(name);
		if (it != localValues.end())
		{
			if ((const T&)(it->second) != value)
			{
				it->second = value;
				OnValueChange(name);
			}
		}
		else
		{
			localValues.emplace(name, std::move(value));
		}
	}

	//���ñ���ֵ
	template<typename T>
	void SetValue(const DependencyProperty<T>& property, const T& value)
	{
		auto& name = property.GetName();
		//��Ȿ��ֵ
		auto it = localValues.find(name);
		if (it != localValues.end())
		{
			if ((const T&)(it->second) != value)
			{
				it->second = value;
				OnValueChange(name);
			}
		}
		else
		{
			localValues.emplace(name, value);
		}
	}
protected:

	template<typename T>
	void SetPropertyChangedHandler(const DependencyProperty<T>& property, std::function<void()> handler)
	{
		auto& name = property.GetName();
		auto it(observers.find(name));

		if (it != observers.end())
		{
			it->second = handler;
		}
		else
		{
			observers.emplace(name, handler);
		}
	}

	template<typename T>
	void ClearPropertyChangedHandler(const DependencyProperty<T>& property)
	{
		auto& name = property.GetName();
		auto it(observers.find(name));

		if (it != observers.end())
		{
			observers.erase(it);
		}
	}

	template<typename T>
	const T& GetCommonValue(const DependencyProperty<T>& property) const
	{
		auto& val = FindParentCommonValue(property.GetName());
		if (val.isEmpty())
		{
			return property.GetValue();
		}
		return val;
	}

	template<typename T>
	T& GetCommonValue(DependencyProperty<T>& property)
	{
		auto& val = FindParentCommonValue(property.GetName());
		if (val.isEmpty())
		{
			return property.GetValue();
		}
		return val;
	}

	void OnValueChange(const String& name) const
	{
		auto it(observers.find(name));
		if (it != observers.end())
		{
			it->second();
		}
	}
protected:
	virtual any& FindParentCommonValue(const String& name) const
	{
		return any::empty;
	}

	virtual any& FindParentCommonValue(const String& name)
	{
		return any::empty;
	}
private:
	std::unordered_map<String, any> localValues;
	std::unordered_map<String, any> animationValues;
	std::unordered_map<String, any> styleValues;
	std::unordered_map<String, std::function<void()>> observers;
};

#define DECLARE_UI_VALUES \
	static std::unordered_map<String, any> commonAnimationValues; \
	static std::unordered_map<String, any> commonStyleValues;

#define DEFINE_UI_VALUES(CLASS) \
	std::unordered_map<String, any> CLASS::commonAnimationValues; \
	std::unordered_map<String, any> CLASS::commonStyleValues;

#define DECLARE_UI_FUNCS \
	virtual any& FindParentCommonValue(const String& name) const; \
	virtual any& FindParentCommonValue(const String& name);

#define DEFINE_UI_FUNCS(CLASS, BASE) \
	any& CLASS::FindParentCommonValue(const String& name) const \
	{															\
		auto it = CLASS::commonAnimationValues.find(name); 		\
		if (it != CLASS::commonAnimationValues.end()) 			\
		{														\
			return it->second;									\
		}														\
		it = CLASS::commonStyleValues.find(name);				\
		if (it != CLASS::commonStyleValues.end())				\
		{														\
			return it->second;									\
		}														\
		return BASE::FindParentCommonValue(name);				\
	}															\
	any& CLASS::FindParentCommonValue(const String& name)		\
	{															\
		auto it = CLASS::commonAnimationValues.find(name); 		\
		if (it != CLASS::commonAnimationValues.end()) 			\
		{														\
			return it->second;									\
		}														\
		it = CLASS::commonStyleValues.find(name);				\
		if (it != CLASS::commonStyleValues.end())				\
		{														\
			return it->second;									\
		}														\
		return BASE::FindParentCommonValue(name);				\
	}

NS_ED