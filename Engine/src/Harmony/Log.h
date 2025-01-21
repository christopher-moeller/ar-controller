#pragma once

#include <memory>
#include "spdlog/spdlog.h"

namespace Harmony {

    class Log
    {
    public:
        
        static void Init();

        inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; };
        inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; };

    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;

    };
    

}


#define HY_CORE_TRACE(...)   ::Harmony::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define HY_CORE_INFO(...)    ::Harmony::Log::GetCoreLogger()->info(__VA_ARGS__)
#define HY_CORE_ERROR(...)   ::Harmony::Log::GetCoreLogger()->error(__VA_ARGS__)
#define HY_CORE_FATAL(...)   ::Harmony::Log::GetCoreLogger()->fatal(__VA_ARGS__)


#define HY_TRACE(...)   ::Harmony::Log::GetClientLogger()->trace(__VA_ARGS__)
#define HY_INFO(...)    ::Harmony::Log::GetClientLogger()->info(__VA_ARGS__)
#define HY_ERROR(...)   ::Harmony::Log::GetClientLogger()->error(__VA_ARGS__)
#define HY_FATAL(...)   ::Harmony::Log::GetClientLogger()->fatal(__VA_ARGS__)

