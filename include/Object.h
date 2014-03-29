#pragma once
#include "core.h"

NS_MPF

class Type;
class String;

#define DECLARE_GETINSTANTTYPE(typeName) virtual std::shared_ptr<Type> GetInstantType()const mnoexcept{ return typeName ## Type; }
#define DECLARE_GETTYPE(typeName) static std::shared_ptr<Type> GetType() mnoexcept{ return typeName ## Type; }
#define DECLARE_TYPE(typeName) static std::shared_ptr<Type> typeName ## Type;
#define DEFINE_TYPE(typeName, fullName) std::shared_ptr<Type> typeName::typeName ## Type = std::make_shared<Type>(Type(std::make_shared<String>(L#fullName)));

//MPF �����ж���Ļ���
class Object
{
public:
	//���� Object ����ʵ��
	MPF_API Object();

	//��ȡ��ϣֵ
	MPF_API virtual uint GetHashCode() const mnoexcept;
	//��ȡ����
	MPF_API DECLARE_GETTYPE(Object)
	MPF_API DECLARE_GETINSTANTTYPE(Object)
private:
	DECLARE_TYPE(Object)
};

NS_ED