#pragma once
#include "core.h"

NS_MPF

class Type;
class String;

#define DECLARE_GETINSTANTTYPE(typeName) virtual const Type& GetInstantType()const mnoexcept{ return typeName ## Type; }
#define DECLARE_GETTYPE(typeName) static const Type& GetType() mnoexcept{ return typeName ## Type; }
#define DECLARE_TYPE(typeName) static Type typeName ## Type;
#define DEFINE_TYPE(typeName, fullName) Type typeName::typeName ## Type(L#fullName);

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