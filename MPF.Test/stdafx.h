// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>



// TODO:  �ڴ˴����ó�����Ҫ������ͷ�ļ�
#include "../include/MPF.h"
#include "../include/io/FileStream.h"
#include "../include/media/ImageSource.h"
#include "../include/io/BinaryReader.h"

#ifdef _DEBUG
#pragma comment(lib, "../Debug/MPF.Core.lib")
#pragma comment(lib, "../Debug/MPF.Startup.lib")
#else
#pragma comment(lib, "../Release/MPF.Core.lib")
#pragma comment(lib, "../Release/MPF.Startup.lib")
#endif
//#pragma comment(lib, "../Debug/MPF.Visual.lib")