#pragma once
#include "../Type.h"
#include "NativeWindow.h"
#include "Line.h"
#include "Triangle.h"
#include "Brush.h"

NS_MPF
NS_VSL

//��Ⱦ�����ṩ����
class RenderCoreProvider : public Object
{
public:
	//���� RenderCoreProvider ����ʵ��
	MPF_API RenderCoreProvider(std::shared_ptr<NativeWindow> window);
	MPF_API virtual ~RenderCoreProvider(){}

	//��ʼ����
	MPF_API virtual void BeginDraw() = 0;
	//��������
	MPF_API virtual void EndDraw() = 0;

	MPF_API void DrawLine(const Line& line, color_t color);
	MPF_API void DrawLine(const Line& line, const Brush& brush);

	MPF_API void DrawTriangle(const Triangle& triangle, color_t color);
	MPF_API void DrawTriangle(const Triangle& triangle, const Brush& brush);

	MPF_API void FillTriangle(const Triangle& triangle, color_t color);
	MPF_API void FillTriangle(const Triangle& triangle, const Brush& brush);

	//����
	MPF_API virtual void Present() = 0;

	//��ȡ����
	MPF_API DECLARE_GETTYPE(RenderCoreProvider)
protected:
	//�����߶�
	MPF_API virtual void DrawLine(uint x1, uint y1, uint x2, uint y2, color_t color) = 0;
	//�����߶�
	MPF_API virtual void DrawLine(uint x1, uint y1, uint x2, uint y2, 
		float u1, float v1, float u2, float v2, const Brush& brush) = 0;

	//����������
	MPF_API virtual void DrawTriangle(uint x1, uint y1, uint x2, uint y2, uint x3, uint y3, color_t color) = 0;
	//����������
	MPF_API virtual void DrawTriangle(uint x1, uint y1, uint x2, uint y2, uint x3, uint y3,
		float u1, float v1, float u2, float v2, float u3, float v3, const Brush& brush) = 0;
	//���������
	MPF_API virtual void FillTriangle(uint x1, uint y1, uint x2, uint y2, uint x3, uint y3, color_t color) = 0;
	//���������
	MPF_API virtual void FillTriangle(uint x1, uint y1, uint x2, uint y2, uint x3, uint y3, 
		float u1, float v1, float u2, float v2, float u3, float v3, const Brush& brush) = 0;

	std::shared_ptr<NativeWindow> window;
private:
	void InitializeDPIScale();
	std::pair<uint, uint> LogicalPointToDevicePoint(const Point& point) const;
private:
	float dpiScaleX;
	float dpiScaleY;

	DECLARE_TYPE(RenderCoreProvider)
};

NS_ED
NS_ED