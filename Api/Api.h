// Instead of using conditional __declspec(dllexport)/dllimport way of defining exports
// we define those unconditionally. This library is supposed to be used with 
// LoadLibrary/GetProcAddress way, so no importing required.

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
#include <windows.h>
#include <winver.h>

#define DLLEXPORT __declspec(dllexport)

#include "Common/Common.h"

#ifdef __cplusplus
extern "C" {
#endif

DLLEXPORT int APIENTRY LoadTrueCryptDriver(void);

#ifdef __cplusplus
}
#endif