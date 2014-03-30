#pragma once
#include "Geometry.h"
#include "Brush.h"

NS_MPF
NS_VSL

//ͼ���㷨
class GraphicAlgorithms
{
public:
	//Bresenham ֱ�������㷨
	MPF_API static void DrawLine_Bresenham(color_t* data, uint stride, int x1, int y1, int x2, int y2, color_t color);

	//��С��ֱ�������㷨
	MPF_API static void DrawLine_WuXiaolin(color_t* data, uint stride, uint x1, uint y1, uint x2, uint y2, color_t color);

	//��С��ֱ�������㷨
	MPF_API static void DrawLine_WuXiaolin(color_t* data, uint stride, uint x1, uint y1, uint x2, uint y2,
		float u1, float v1, float u2, float v2, const Brush& brush);

	//MLAA
	MPF_API static void MLAA(color_t* data, uint width, uint height);

	//��ɫ���������
	MPF_API static void FillTriangle_Solid(color_t* data, uint stride, uint x1, uint y1,
		uint x2, uint y2, uint x3, uint y3, color_t color);
	//���������
	MPF_API static void FillTriangle(color_t* data, uint stride, uint x1, uint y1, uint x2, uint y2,
		uint x3, uint y3, float u1, float v1, float u2, float v2, float u3, float v3, const Brush& brush);
	//����ı���
	MPF_API static void FillQuad(color_t* data, uint stride, uint x1, uint y1, uint x2, uint y2,
		uint x3, uint y3, uint x4, uint y4, float u1, float v1, float u2, float v2, 
		float u3, float v3, float u4, float v4, const Brush& brush);

	static inline argb_color MixColor(argb_color col1, argb_color col2, double p)
	{
		argb_color color;

		color.red = col1.red * p + col2.red * (1 - p);
		color.green = col1.green * p + col2.green * (1 - p);
		color.blue = col1.blue * p + col2.blue * (1 - p);

		return color;
	}
private:
	//���ƺ�������45�ȡ�135��ֱ��
	static bool DrawSpecialLine(color_t* data, uint stride, int x1, int y1, int x2, int y2, color_t color);

	//���ƺ�������45�ȡ�135��ֱ��
	static bool DrawSpecialLine(color_t* data, uint stride, int x1, int y1, 
		int x2, int y2, float u1, float v1, float u2, float v2, const Brush& brush);
};

NS_ED
NS_ED