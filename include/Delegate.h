#pragma once
#include "Type.h"

NS_MPF

//ί��
class Delegate : public Object
{
public:
	//���� Delegate ����ʵ��
	MPF_API Delegate() mnoexcept;

	//��ȡ����
	MPF_API DECLARE_GETTYPE(Delegate)
private:
	DECLARE_TYPE(Delegate)
};

NS_ED