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

#ifdef TWI
	#define TWI_ASSERT(x, ...) (if(!(x)) { TWI_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); })
	#define TWI_CORE_ASSERT(x, ...) (if(!(x)) { TWI_CORE_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); })
#else
	#define TWI_ASSERT(x, ...)
	#define TWI_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)