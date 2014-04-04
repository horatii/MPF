#pragma once
#include "Geometry.h"

NS_MPF
NS_VSL

//������
class Triangle : public Geometry
{
public:
	//����һ��������
	MPF_API explicit Triangle(const Point& pointA, const Point& pointB, const Point& pointC);

	//��ȡ��������
	MPF_API virtual std::vector<Point> GetPoints() const;

	MPF_API virtual void Transform(std::function<void(Point&)> func);
	//�ж��������Ƿ�����㣨�����߽磩
	MPF_API bool Contains(const Point& point) const mnoexcept;

	//��ȡ����
	DECLARE_GETTYPE(Triangle)
private:
	Point pointA;
	Point pointB;
	Point pointC;

	DECLARE_TYPE(Triangle)
};

NS_ED
NS_ED