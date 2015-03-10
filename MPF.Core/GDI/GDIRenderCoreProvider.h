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

	virtual size_t GetBackBufferWidth() const noexcept { return backBufferSurface->GetWidth(); }
	virtual size_t GetBackBufferHeight() const noexcept { return backBufferSurface->GetHeight(); }

	//��ȡ����
	DECLARE_GETTYPE(GDIRenderCoreProvider)
protected:
	//�����߶�
	virtual void DrawLine(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2, color_t color);
	//�����߶�
	virtual void DrawLine(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2,
		float u1, float v1, float u2, float v2, const MPF::Visual::Brush& brush);
	//����������
	virtual void DrawTriangle(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2, uint32_t x3, uint32_t y3, color_t color);
	//����������
	virtual void DrawTriangle(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2, uint32_t x3, uint32_t y3,
		float u1, float v1, float u2, float v2, float u3, float v3, const MPF::Visual::Brush& brush);
	//���������
	virtual void FillTriangle(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2, uint32_t x3, uint32_t y3, color_t color);
	//���������
	virtual void FillTriangle(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2, uint32_t x3, uint32_t y3,
		float u1, float v1, float u2, float v2, float u3, float v3, const MPF::Visual::Brush& brush);
	//�����ı���
	virtual void DrawQuad(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2, uint32_t x3, uint32_t y3, uint32_t x4, uint32_t y4,
		float u1, float v1, float u2, float v2, float u3, float v3, float u4, float v4,
		const MPF::Visual::Brush& brush);
	//����ı���
	virtual void FillQuad(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2, uint32_t x3, uint32_t y3, uint32_t x4, uint32_t y4,
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