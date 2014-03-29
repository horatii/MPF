#pragma once
#include "Geometry.h"

NS_MPF
NS_VSL

//三角形
class Triangle : public Geometry
{
public:
	//创建一个三角形
	MPF_API explicit Triangle(const Point& pointA, const Point& pointB, const Point& pointC);

	//获取顶点数据
	MPF_API virtual std::vector<Point> GetPoints() const;

	//获取类型
	DECLARE_GETTYPE(Triangle)
private:
	Point pointA;
	Point pointB;
	Point pointC;

	DECLARE_TYPE(Triangle)
};

NS_ED
NS_ED