//------------------------------------------------------------------------------
// <copyright file="stdafx.h" company="Microsoft">
//     Copyright (c) Microsoft Corporation.  All rights reserved.
// </copyright>
//------------------------------------------------------------------------------

// include file for standard system and project includes

#pragma once

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
#endif

#define _VARIADIC_MAX 6 // Max arguments increased for PCLInputReaderWorkerThread::readCloudData(...)

// Windows Header Files
#include <windows.h>

#include <Shlobj.h>

// Direct2D Header Files
#include <d2d1.h>

// Kinect Header files
#include <Kinect.h>
#include <Kinect.Face.h>

#pragma comment (lib, "d2d1.lib")

#ifdef _UNICODE
#if defined _M_IX86
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_X64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#else
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#endif
#endif

#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif

// Safe release for interfaces
template<class Interface>
inline void SafeRelease(Interface *& pInterfaceToRelease)
{
    if (pInterfaceToRelease != nullptr)
    {
        pInterfaceToRelease->Release();
        pInterfaceToRelease = nullptr;
    }
}

template<class T>
inline void SafeDelete(T*& ptr)
{
    if(ptr)
    {
        delete ptr;
        ptr = nullptr;
    }
}

// Safe delete array
template<class T>
inline void SafeDeleteArray(T*& pArray)
{
    if(pArray)
    {
        delete[] pArray;
        pArray = nullptr;
    }
}


enum KinectVersionType{
	KinectV1,
	KinectV2,
	KINECT_VERSION_TYPE_COUNT
};


#define WM_STREAMEVENT_COLOR   WM_USER + 1
#define WM_STREAMEVENT_DEPTH   WM_USER + 2

#pragma warning ( disable: 4996 )
#pragma warning ( disable: 4503 )

#include <memory>
#undef max
#undef min
#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
#include <boost/signal.hpp>
#include <boost/signals2.hpp>
#include <boost/bind.hpp>
#include <iomanip>
