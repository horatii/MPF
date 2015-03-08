#pragma once
#include "Geometry.h"

NS_MPF
NS_VSL

//ֱ��
class Line : public Geometry
{
public:
	//����һ��ֱ��
	MPF_API explicit Line(const Point& startPoint, const Point& endPoint);

	//��ȡ��������
	MPF_API virtual std::vector<Point> GetPoints() const;

	//��ȡ��ʼ��
	const Point& GetStartPoint() const noexcept { return startPoint; }
	//��ȡ������
	const Point& GetEndPoint() const noexcept { return endPoint; }

	//ͨ��Y��ֱ���ϵ�X
	float GetX(float y) const noexcept;
	///<summary>ͨ��Y���߶��ϵ�X</summary>
	///<return>���Yֵ���߶����򷵻�true,Xֵ�����򷵻�false,0</return>
	std::pair<bool, float> GetXInSegment(float y) const noexcept;
	//ͨ��Y��ֱ���ϵ�UV
	std::pair<float, float> GetUV(uint32_t y) const noexcept;

	MPF_API virtual void Transform(std::function<void(Point&)> func);

	//��ȡ����
	DECLARE_GETTYPE(Line)
private:
	Point startPoint;
	Point endPoint;

	DECLARE_TYPE(Line)
};

NS_ED
NS_ED