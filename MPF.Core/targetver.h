﻿#pragma once

// 包括 SDKDDKVer.h 将定义可用的最高版本的 Windows 平台。

// 如果要为以前的 Windows 平台生成应用程序，请包括 WinSDKVer.h，并将
// WIN32_WINNT 宏设置为要支持的平台，然后再包括 SDKDDKVer.h。

#include <winsdkver.h>
#define WIN32_WINNT 0x0501	//最低平台为 Windows XP
#include <SDKDDKVer.h>
