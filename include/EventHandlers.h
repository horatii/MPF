#pragma once
#include "core.h"

NS_MPF

//δ�����쳣�¼�������
using UncaughtExceptionEventHandler = std::function<void(bool&)>;
//�����¼�
using PaintEventHandler = std::function<void()>;

NS_ED