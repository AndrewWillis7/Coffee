#pragma once

#ifdef CF_PLATFORM_WINDOWS
	#ifdef COFFEE_BUILD_DLL
		#define COFFEE_API __declspec(dllexport)
	#else
		#define COFFEE_API __declspec(dllimport)
	#endif // CF_BUILD_DLL
#else
	#error Windows Support Only
#endif // CF_PLATFORM_WINDOWS
