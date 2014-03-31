#pragma once
#include "String.h"

NS_MPF

//����
class Type : public Object
{
public:
	//���� Type ����ʵ��
	MPF_API Type(const String& typeName);

	MPF_API bool Equals(const Type& type) const;
	bool operator==(const Type& type) const
	{
		return Equals(type);
	}

	//��ȡ����
	MPF_API DECLARE_GETTYPE(Type)
private:
	String typeName;
	DECLARE_TYPE(Type)
};

NS_ED