#pragma once
#include "Core/PCH.h"
#include "Core/SingletonBaseClass.h"
#include <bx/uint32_t.h>
#include "common.h"
#include "bgfx_utils.h"
#include "imgui/imgui.h"

namespace JSEngine
{

#define g_GraphicsWrapper Singleton<GraphicsWrapper>::GetInstance()

    class GraphicsWrapper : public Singleton<GraphicsWrapper>
    {
    public:
        friend class Singleton<GraphicsWrapper>;
        void Init(int32_t _argc, const char* const* _argv, uint32_t _width, uint32_t _height);
        void Update(entry::AppI* app);
        void Shutdown();

    private:
        GraphicsWrapper() {}

        uint32_t m_WindowWidth;
        uint32_t m_WindowHeight;
        uint32_t m_Debug;
        uint32_t m_Reset;

        bgfx::Init m_bgfxInit;
        entry::MouseState m_mouseState;


    };

}