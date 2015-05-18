#pragma once
#include "../Type.h"
#include "Line.h"
#include "Triangle.h"
#include "Brush.h"
#include "Quad.h"
#include "Matrix2D.h"

NS_MPF
NS_VSL

class NativeWindow;

//��Ⱦ�����ṩ����
class RenderCoreProvider
{
public:
	//���� RenderCoreProvider ����ʵ��
	RenderCoreProvider(NativeWindow& window);
	virtual ~RenderCoreProvider() {}

	//��ʼ����
	MPF_API virtual void BeginDraw() = 0;
	//��������
	MPF_API virtual void EndDraw() = 0;

	MPF_API virtual void Clear(color_t color) = 0;
	MPF_API void DrawLine(const Line& line, color_t color);
	MPF_API void DrawLine(const Line& line, const Brush& brush);

	MPF_API void DrawTriangle(const Triangle& triangle, color_t color);
	MPF_API void DrawTriangle(const Triangle& triangle, const Brush& brush);

	MPF_API void FillTriangle(const Triangle& triangle, color_t color);
	MPF_API void FillTriangle(const Triangle& triangle, const Brush& brush);

	MPF_API void DrawQuad(const Quad& quad, const Brush& brush);
	MPF_API void DrawQuad(const Quad& quad, const Brush& brush, const Matrix2D<>& transform);
	MPF_API void FillQuad(const Quad& quad, const Brush& brush);

	MPF_API virtual size_t GetBackBufferWidth() const noexcept = 0;
	MPF_API virtual size_t GetBackBufferHeight() const noexcept = 0;

	//����
	MPF_API virtual void Present() = 0;
protected:
	//�����߶�
	MPF_API virtual void DrawLine(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2, color_t color) = 0;
	//�����߶�
	MPF_API virtual void DrawLine(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2,
		float u1, float v1, float u2, float v2, const Brush& brush) = 0;

	//����������
	MPF_API virtual void DrawTriangle(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2, uint32_t x3, uint32_t y3, color_t color) = 0;
	//����������
	MPF_API virtual void DrawTriangle(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2, uint32_t x3, uint32_t y3,
		float u1, float v1, float u2, float v2, float u3, float v3, const Brush& brush) = 0;
	//���������
	MPF_API virtual void FillTriangle(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2, uint32_t x3, uint32_t y3, color_t color) = 0;
	//���������
	MPF_API virtual void FillTriangle(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2, uint32_t x3, uint32_t y3,
		float u1, float v1, float u2, float v2, float u3, float v3, const Brush& brush) = 0;
	//�����ı���
	MPF_API virtual void DrawQuad(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2, uint32_t x3, uint32_t y3, uint32_t x4, uint32_t y4,
		float u1, float v1, float u2, float v2, float u3, float v3, float u4, float v4, const Brush& brush) = 0;
	//����ı���
	MPF_API virtual void FillQuad(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2, uint32_t x3, uint32_t y3, uint32_t x4, uint32_t y4,
		float u1, float v1, float u2, float v2, float u3, float v3, float u4, float v4, const Brush& brush) = 0;
protected:
	NativeWindow& window;
};

NS_ED
NS_ED