#pragma once
#include "Object.h"

NS_MPF

class Type;

class String : public Object
{
public:
	//�����յ� String
	MPF_API String() mnoexcept;
	//�ͷ���Դ
	MPF_API virtual ~String();

	//���ַ�ָ�봴�� String
	MPF_API String(const wchar_t* chars, bool isOwner = false);

	//���������ͳ��ȴ��� String
	MPF_API String(const wchar_t chars[], uint length) mnoexcept;

	MPF_API String(const String& str);
	MPF_API String(String&& str);

	//������������ String
	template<uint N>
	String(const wchar_t(&chars)[N]) mnoexcept
		:chars(chars), length(N)
	{

	}

	//��ȡ����
	MPF_API uint GetLength() const mnoexcept;
	
	//��ȡ����ָ��
	MPF_API const wchar_t* GetDataPointer() const mnoexcept;

	//��ȡ��ϣֵ
	MPF_API virtual uint GetHashCode() const mnoexcept;

	//�������
	MPF_API bool operator==(const String& str) const mnoexcept;
	//���Բ����
	MPF_API bool operator!=(const String& str) const mnoexcept;

	MPF_API wchar_t operator[](size_t index) const;

	MPF_API const String& operator=(const String& str);
	MPF_API const String& operator=(String&& str) mnoexcept;

	MPF_API bool IsEmpty() const mnoexcept;

	//��ȡ���ַ���
	MPF_API static const String& GetEmpty();

	//��ȡ����
	MPF_API DECLARE_GETTYPE(String)
private:
	void Dispose() mnoexcept;
private:
	static String empty;

	DECLARE_TYPE(String)
	const wchar_t* chars = L"";
	bool isOwner = false;
	uint length = 0;
};

NS_ED

namespace std
{
	template<>
	class hash<MPF::String>
	{
	public:
		size_t operator()(const MPF::String& str) const
		{
			return str.GetHashCode();
		}
	};
}