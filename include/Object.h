#pragma once
#include "core.h"

NS_MPF

class Type;
class String;

#define DECLARE_GETINSTANTTYPE(typeName) virtual const Type& GetInstantType()const noexcept{ return typeName ## Type; }
#define DECLARE_GETTYPE(typeName) static const Type& GetType() noexcept{ return typeName ## Type; }
#define DECLARE_TYPE(typeName) static Type typeName ## Type;
#define DEFINE_TYPE(typeName, fullName) Type typeName::typeName ## Type(L#fullName);

//MPF �����ж���Ļ���
class Object
{
public:
	//���� Object ����ʵ��
	constexpr Object() noexcept {}

	//��ȡ��ϣֵ
	virtual uint32_t GetHashCode() const noexcept { return (uint32_t)this; }
	//��ȡ����
	MPF_API DECLARE_GETTYPE(Object)
	MPF_API DECLARE_GETINSTANTTYPE(Object)
private:
	DECLARE_TYPE(Object)
};

NS_ED