#ifndef REMA_LOG_H
#define REMA_LOG_H

#include "Core.h"

#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace remaEngine
{
	class REMA_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core logger macroses
#define REMA_CORE_TRACE(...)	::remaEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define REMA_CORE_INFO(...)		::remaEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define REMA_CORE_WARNING(...)	::remaEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define REMA_CORE_ERROR(...)	::remaEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define REMA_CORE_FATAL(...)	::remaEngine::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// CLient logger macroses
#define REMA_TRACE(...)		::remaEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define REMA_INFO(...)		::remaEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define REMA_WARNING(...)	::remaEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define REMA_ERROR(...)		::remaEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define REMA_FATAL(...)		::remaEngine::Log::GetClientLogger()->fatal(__VA_ARGS__)

#endif // !REMA_LOG_H

