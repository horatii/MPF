#pragma once
#include "../Type.h"
#include "Point.h"

NS_MPF
NS_VSL

//ͼԪ
class Geometry : public Object
{
public:
	//���� Geometry ����ʵ��
	explicit Geometry() { }

	//��ȡ��������
	virtual std::vector<Point> GetPoints() const = 0;

	//��ȡ����
	DECLARE_GETTYPE(Geometry)
private:
	DECLARE_TYPE(Geometry)
};

NS_ED
NS_ED