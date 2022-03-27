#ifndef REMA_CORE_H
#define REMA_CORE_H

#ifdef REMA_PLATFORM_WINDOWS
	#ifdef REMA_BUILD_DLL
		#define REMA_API __declspec(dllexport)
	#else
		#define REMA_API __declspec(dllimport)
	#endif
#else
	#error Rema only supports windows now
#endif

#ifdef REMA_ENABLE_ASSERT
	#define REMA_ASSERT(x, ...) { if(!(x)) { REMA_ERROR("Assertion filed: {0}", __VA_ARGS__); __debugbreak(); }}
	#define REMA_CORE_ASSERT(x, ...) { if(!(x)) { REMA_CORE_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); }}
#else
	#define REMA_ASSERT(x, ...)
	#define REMA_CORE_ASSERT(x, ...)
#endif // REMA_ENABLE_ASSERT


#define BIT(x) (1 << x)
#define ruint unsigned int

#endif // !REMA_CORE_H
