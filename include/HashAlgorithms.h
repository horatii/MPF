#pragma once
#include "core.h"

NS_MPF
NS_INTERN

namespace Hash
{
	///<summary>BKDR Hash Function</summary>
	///<description>���㷨������Brian Kernighan��Dennis Ritchie�ġ�The C Programming Language��һ�鱻չʾ����
	/// ������һ�ּ򵥿�ݵ�hash�㷨��Ҳ��JavaĿǰ���õ��ַ�����Hash�㷨���۳�����Ϊ31����</description>
	template<class T>
	size_t BKDRHash(const T *str)
	{
		register size_t hash = 0;
		while (size_t ch = (size_t)*str++)
		{
			hash = hash * 131 + ch;       
		}
		return hash;
	}
}

NS_ED
NS_ED