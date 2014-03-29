#pragma once
#include "../Type.h"

NS_MPF
NS_VSL

//ͼƬ
class Image : public Object
{
public:
	//���� Image ����ʵ��
	MPF_API Image(std::istream& stream);
	//���� Image ����ʵ��
	MPF_API Image(const std::vector<byte>& data);

	//��ȡ����
	MPF_API DECLARE_GETTYPE(Image)
	MPF_API DECLARE_GETINSTANTTYPE(Image)
private:
	DECLARE_TYPE(Image)
};

NS_ED
NS_ED