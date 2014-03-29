#pragma once
#include "../Type.h"

NS_MPF
NS_VSL

//��
class Point : public Object
{
public:
	//���� Point ����ʵ��
	explicit Point(float x = 0.f, float y = 0.f, float u = 0.f, float v = 0.f)
		:x(x), y(y), u(u), v(v)
	{

	}

	//��ȡ X ����
	float GetX() const mnoexcept
	{
		return x;
	}

	//��ȡ Y ����
	float GetY() const mnoexcept
	{
		return y;
	}

	//���� X ����
	void SetX(float x) mnoexcept
	{
		this->x = x;
	}

	//���� Y ����
	void SetY(float y) mnoexcept
	{
		this->y = y;
	}

	//��ȡ U ����
	float GetU() const mnoexcept
	{
		return u;
	}

	//��ȡ V ����
	float GetV() const mnoexcept
	{
		return v;
	}

	//���� U ����
	void SetU(float u) mnoexcept
	{
		this->u = u;
	}

	//���� V ����
	void SetV(float v) mnoexcept
	{
		this->v = v;
	}

	//��ȡ����
	DECLARE_GETTYPE(Point)
private:
	float x;
	float y;
	float u;
	float v;

	DECLARE_TYPE(Point)
};

NS_ED
NS_ED