#pragma once
#include "Common.h"
#include "Utilities/Console.h"

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

namespace Spoon
{
	class Log
	{
	public:
		static void Init();

		static std::shared_ptr<spdlog::logger>& GetCoreLogger();
		static std::shared_ptr<spdlog::logger>& GetClientLogger();

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

		static ScopePtr<Console> s_Console;
	};
}

#define SP_CORE_TRACE(...)		::Spoon::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SP_CORE_INFO(...)		::Spoon::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SP_CORE_WARN(...)		::Spoon::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SP_CORE_ERROR(...)		::Spoon::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SP_CORE_CRITICAL(...)	::Spoon::Log::GetCoreLogger()->critical(__VA_ARGS__)

#define SP_TRACE(...)		::Spoon::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SP_INFO(...)		::Spoon::Log::GetClientLogger()->info(__VA_ARGS__)
#define SP_WARN(...)		::Spoon::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SP_ERROR(...)		::Spoon::Log::GetClientLogger()->error(__VA_ARGS__)
#define SP_CRITICAL(...)	::Spoon::Log::GetClientLogger()->critical(__VA_ARGS__)