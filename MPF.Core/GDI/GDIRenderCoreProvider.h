#pragma once
#include "../../include/visual/RenderCoreProvider.h"
#include "DeviceContext.h"
#include "Bitmap.h"

NS_MPF
NS_GDI

//GDI ��Ⱦ�ṩ����
class GDIRenderCoreProvider : public MPF::Visual::RenderCoreProvider
{
public:
	//���� GDIRenderCoreProvider ����ʵ��
	GDIRenderCoreProvider(MPF::Visual::NativeWindow& window);
	virtual ~GDIRenderCoreProvider();

	//��ʼ����
	virtual void BeginDraw();
	//��������
	virtual void EndDraw();

	//����
	virtual void Present();

	//��ȡ����
	DECLARE_GETTYPE(GDIRenderCoreProvider)
protected:
	//�����߶�
	virtual void DrawLine(uint x1, uint y1, uint x2, uint y2, color_t color);
	//�����߶�
	virtual void DrawLine(uint x1, uint y1, uint x2, uint y2,
		float u1, float v1, float u2, float v2, const MPF::Visual::Brush& brush);
	//����������
	virtual void DrawTriangle(uint x1, uint y1, uint x2, uint y2, uint x3, uint y3, color_t color);
	//����������
	virtual void DrawTriangle(uint x1, uint y1, uint x2, uint y2, uint x3, uint y3,
		float u1, float v1, float u2, float v2, float u3, float v3, const MPF::Visual::Brush& brush);
	//���������
	virtual void FillTriangle(uint x1, uint y1, uint x2, uint y2, uint x3, uint y3, color_t color);
	//���������
	virtual void FillTriangle(uint x1, uint y1, uint x2, uint y2, uint x3, uint y3,
		float u1, float v1, float u2, float v2, float u3, float v3, const MPF::Visual::Brush& brush);
	//�����ı���
	virtual void DrawQuad(uint x1, uint y1, uint x2, uint y2, uint x3, uint y3, uint x4, uint y4,
		float u1, float v1, float u2, float v2, float u3, float v3, float u4, float v4,
		const MPF::Visual::Brush& brush);
	//����ı���
	virtual void FillQuad(uint x1, uint y1, uint x2, uint y2, uint x3, uint y3, uint x4, uint y4,
		float u1, float v1, float u2, float v2, float u3, float v3, float u4, float v4, 
		const MPF::Visual::Brush& brush);
private:
	//��ʼ�� GDI
	void InitializeGDI();
private:
	//������
	std::unique_ptr<DeviceContext> frontBuffer;
	//�󱳻������
	std::unique_ptr<Bitmap> backBufferSurface;
	//�󱳻���
	std::unique_ptr<DeviceContext> backBuffer;

	DECLARE_TYPE(GDIRenderCoreProvider)
};

NS_ED
NS_ED