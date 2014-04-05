#pragma once
#include "Type.h"
#include "any.h"
#include "DependencyProperty.h"
#include "RoutedEvent.h"
#include "RoutedEventArgs.h"

NS_MPF

//�����������ԵĶ���
class DependencyObject
{
public:
	//���� DependencyObject ����ʵ��
	DependencyObject(){}
	virtual ~DependencyObject();

	//��ȡ��ǰֵ
	template<typename T>
	T& GetValue(DependencyProperty<T>& property) const
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

	//����¼�������
	template<typename THandler, typename TArgs>
	void AddEventHandler(const RoutedEvent<THandler>& ent, std::function<void(TArgs&)> handler)
	{
		localEvents.emplace(ent.GetName(), [=](RoutedEventArgs& args)
		{
			handler(*(TArgs*)(&args));
		});
	}

	//����¼�������
	template<typename THandler, typename TArgs>
	void AddStyleEventHandler(const RoutedEvent<THandler>& ent, std::function<void(TArgs&)> handler)
	{
		AddCommonEventHandlers(ent.GetName(), [=](RoutedEventArgs& args)
		{
			handler(*(TArgs*)(&args));
		});
	}

	//�����¼�
	template<typename THandler, typename TArgs>
	void RaiseEvent(const RoutedEvent<THandler>& ent, TArgs& args)
	{
		OnRaiseEvent(ent, args);
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
	T& GetCommonValue(DependencyProperty<T>& property) const
	{
		auto& val = FindParentCommonValue(property.GetName());
		if (val.isEmpty())
		{
			return property.GetValue();
		}
		return val;
	}
	MPF_API void OnValueChange(const String& name) const;
	MPF_API virtual void OnRaiseEvent(const IRoutedEvent& ent, RoutedEventArgs& args);
protected:
	virtual any& FindParentCommonValue(const String& name) const;
	virtual void InvokeParentCommonEventHandlers(const IRoutedEvent& ent, RoutedEventArgs& args) const;
	virtual void AddCommonEventHandlers(const String& name, RoutedEventHandler&& handler) const;
private:
	//����
	std::unordered_map<String, any> localValues;
	std::unordered_map<String, any> animationValues;
	std::unordered_map<String, any> styleValues;
	std::unordered_map<String, std::function<void()>> observers;
	//�¼�
	std::unordered_multimap<String, RoutedEventHandler> localEvents;
	std::unordered_multimap<String, RoutedEventHandler> styleEvents;
};

#define DECLARE_UI_VALUES \
	static std::unordered_map<String, any> commonAnimationValues; \
	static std::unordered_map<String, any> commonStyleValues;	  \
	static std::unordered_multimap<String, RoutedEventHandler> commonStyleEvents;

#define DEFINE_UI_VALUES(CLASS) \
	std::unordered_map<String, any> CLASS::commonAnimationValues; \
	std::unordered_map<String, any> CLASS::commonStyleValues;	  \
	std::unordered_multimap<String, RoutedEventHandler> CLASS::commonStyleEvents;

#define DECLARE_UI_FUNCS \
	virtual any& FindParentCommonValue(const String& name) const; \
	virtual void InvokeParentCommonEventHandlers(const IRoutedEvent& ent, RoutedEventArgs& args) const; \
	virtual void AddCommonEventHandlers(const String& name, RoutedEventHandler&& handler) const;

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
	void CLASS::InvokeParentCommonEventHandlers(const IRoutedEvent& ent, RoutedEventArgs& args) const \
	{																							 \
		auto it = CLASS::commonStyleEvents.find(ent.GetName()); 								 \
		if (it != CLASS::commonStyleEvents.end()) 										  		 \
		{																				  		 \
			RoutedEventHandler& handler = it->second;				      						 \
			handler(args);																  		 \
		}						   														  		 \
		BASE::InvokeParentCommonEventHandlers(ent, args);								  		 \
	}																					  		 \
	void CLASS::AddCommonEventHandlers(const String& name, RoutedEventHandler&& handler) const	 \
	{																			 				 \
		CLASS::commonStyleEvents.emplace(name, handler); 							  			 \
	}

#define DEFINE_COMMON_ROUTEDEVENT(name, TArgs) \
	AddStyleEventHandler<std::function<void(TArgs&)>, TArgs>(name##Event, [&](TArgs& args){On##name(args);});

NS_ED