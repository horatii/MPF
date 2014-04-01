#pragma once
#include "ContentElement.h"

NS_MPF
NS_UI

//���� Button �Ļ���
class ButtonBase : public ContentElement
{
public:
	MPF_API ButtonBase();
	MPF_API virtual ~ButtonBase();

	//��ȡ����
	MPF_API DECLARE_GETTYPE(ButtonBase);
	MPF_API DECLARE_GETINSTANTTYPE(ButtonBase);
protected:

	DECLARE_UI_FUNCS
private:
	DECLARE_UI_VALUES
	DECLARE_TYPE(ButtonBase);
};

NS_ED
NS_ED