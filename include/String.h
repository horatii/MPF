#pragma once
#include "Object.h"

NS_MPF

class Type;

class String : public Object
{
public:
	//�����յ� String
	MPF_API constexpr String() noexcept;
	//�ͷ���Դ
	MPF_API virtual ~String() noexcept;

	//���ַ�ָ�봴�� String
	MPF_API String(const wchar_t* chars, bool isOwner = false);

	//���������ͳ��ȴ��� String
	MPF_API String(const wchar_t chars[], uint32_t length) noexcept;

	MPF_API String(const String& str);
	MPF_API String(String&& str) noexcept;

	//������������ String
	template<uint32_t N>
	constexpr String(const wchar_t(&chars)[N]) noexcept
		:chars(chars), length(N)
	{

	}

	//��ȡ����
	MPF_API uint32_t GetLength() const noexcept;
	
	//��ȡ����ָ��
	MPF_API const wchar_t* GetDataPointer() const noexcept;

	//��ȡ��ϣֵ
	MPF_API virtual uint32_t GetHashCode() const noexcept;

	//�������
	MPF_API bool operator==(const String& str) const noexcept;
	//���Բ����
	MPF_API bool operator!=(const String& str) const noexcept;

	MPF_API wchar_t operator[](size_t index) const;

	MPF_API const String& operator=(const String& str);
	MPF_API const String& operator=(String&& str) noexcept;

	MPF_API bool IsEmpty() const noexcept;

	//��ȡ���ַ���
	MPF_API static const String& GetEmpty();

	//��ȡ����
	MPF_API DECLARE_GETTYPE(String)
private:
	void Dispose() noexcept;
private:
	static String empty;

	DECLARE_TYPE(String)
	const wchar_t* chars = L"";
	bool isOwner = false;
	uint32_t length = 0;
	mutable uint32_t hashCode = 0;
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