#pragma once
#include "String.h"

NS_MPF

//����
class Type : public Object
{
public:
	//���� Type ����ʵ��
	MPF_API Type(const std::shared_ptr<String> typeName);

	MPF_API bool Equals(const std::shared_ptr<Type> type) const;

	//��ȡ����
	MPF_API DECLARE_GETTYPE(Type)
private:
	const std::shared_ptr<String> typeName;
	DECLARE_TYPE(Type)
};

NS_ED