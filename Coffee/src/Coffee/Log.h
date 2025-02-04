#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Coffee {
	class Log
	{
	public:

		static COFFEE_API void Init();

		inline static COFFEE_API std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static COFFEE_API std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static COFFEE_API std::shared_ptr<spdlog::logger> s_CoreLogger;
		static COFFEE_API std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core Log Macros
#define CF_CORE_ERROR(...)   ::Coffee::Log::GetCoreLogger()->error(__VA_ARGS__)
#define CF_CORE_WARN(...)    ::Coffee::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define CF_CORE_INFO(...)    ::Coffee::Log::GetCoreLogger()->info(__VA_ARGS__)
#define CF_CORE_TRACE(...)   ::Coffee::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define CF_CORE_FATAL(...)   ::Coffee::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log Macros
#define CF_ERROR(...)        ::Coffee::Log::GetClientLogger()->error(__VA_ARGS__)
#define CF_WARN(...)         ::Coffee::Log::GetClientLogger()->warn(__VA_ARGS__)
#define CF_INFO(...)         ::Coffee::Log::GetClientLogger()->info(__VA_ARGS__)
#define CF_TRACE(...)        ::Coffee::Log::GetClientLogger()->trace(__VA_ARGS__)
#define CF_FATAL(...)        ::Coffee::Log::GetClientLogger()->critical(__VA_ARGS__)


