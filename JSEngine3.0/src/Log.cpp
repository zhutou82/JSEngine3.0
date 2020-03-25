#include "Log.h"

namespace JSEngine
{
    void Log::Init()
    {
        spdlog::set_pattern("%^[%T] %n: %v%$");
        m_EngineLogger = spdlog::stdout_color_mt("JSEngine3.0");
        m_EngineLogger->set_level(spdlog::level::trace);
        
        JS_CORE_TRACE("Initialized Log Class");
    }
}