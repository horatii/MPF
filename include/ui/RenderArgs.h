#pragma once
#include "../Type.h"
#include "../visual/Quad.h"

NS_MPF
NS_UI

//��Ⱦ����
struct RenderArgs
{
	float ElapsedTime;
};

//���²���
struct UpdateArgs
{
	MPF::Visual::Point ParentOffset;
	float ElapsedTime;
};

NS_ED
NS_ED