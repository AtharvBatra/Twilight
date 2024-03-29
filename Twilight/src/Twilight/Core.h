#pragma once

#ifdef TWI_PLATFORM_WINDOWS
	#ifdef TWI_BUILD_DLL
		#define TWI_API __declspec(dllexport)
	#else
		#define TWI_API __declspec(dllimport)
	#endif
#else
	#error Twiwilight only supports windows :(
#endif