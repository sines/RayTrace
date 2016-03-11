#pragma once
#ifdef RAYTRACELIB_EXPORTS
#define RAYTRACELIB _API__declspec(dllexport)
#else
#define RAYTRACELIB_API __declspec(dllimport)
#endif
