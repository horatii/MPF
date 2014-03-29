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
	GDIRenderCoreProvider(std::shared_ptr<MPF::Visual::NativeWindow> window);
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
private:
	//��ʼ�� GDI
	void InitializeGDI();
private:
	//������
	std::shared_ptr<DeviceContext> frontBuffer;
	//�󱳻������
	std::shared_ptr<Bitmap> backBufferSurface;
	//�󱳻���
	std::shared_ptr<DeviceContext> backBuffer;

	DECLARE_TYPE(GDIRenderCoreProvider)
};

NS_ED
NS_ED