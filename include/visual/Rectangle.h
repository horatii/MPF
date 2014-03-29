#pragma once
#include "Geometry.h"

NS_MPF
NS_VSL

//����
class Rectangle : public Geometry
{
public:
	//����һ������
	MPF_API explicit Rectangle(const Point& pointA, const Point& pointB);

	//��ȡ��������
	MPF_API virtual std::vector<Point> GetPoints() const;

	//��ȡ����
	MPF_API DECLARE_GETTYPE(Rectangle)
	MPF_API DECLARE_GETINSTANTTYPE(Rectangle)
private:
	Point pointA;
	Point pointB;

	DECLARE_TYPE(Rectangle)
};

NS_ED
NS_ED