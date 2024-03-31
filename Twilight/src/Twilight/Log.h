#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Twilight {

	class TWI_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_core_logger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_client_logger; }

	private:
		static std::shared_ptr<spdlog::logger> s_core_logger;
		static std::shared_ptr<spdlog::logger> s_client_logger;

	};

}

#define TWI_CORE_ERROR(...) ::Twilight::Log::GetCoreLogger()->error(__VA_ARGS__)
#define TWI_CORE_WARN(...) ::Twilight::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define TWI_CORE_INFO(...) ::Twilight::Log::GetCoreLogger()->info(__VA_ARGS__)
#define TWI_CORE_TRACE(...) ::Twilight::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define TWI_CORE_FATAL(...) ::Twilight::Log::GetCoreLogger()->critical(__VA_ARGS__)

#define TWI_ERROR(...) ::Twilight::Log::GetClientLogger()->error(__VA_ARGS__)
#define TWI_WARN(...) ::Twilight::Log::GetClientLogger()->warn(__VA_ARGS__)
#define TWI_INFO(...) ::Twilight::Log::GetClientLogger()->info(__VA_ARGS__)
#define TWI_TRACE(...) ::Twilight::Log::GetClientLogger()->trace(__VA_ARGS__)
#define TWI_FATAL(...) ::Twilight::Log::GetClientLogger()->critical(__VA_ARGS__)