#pragma once
#include "Core/PCH.h"
#include "Core/SingletonBaseClass.h"
#include "imgui/imgui.h"

namespace JSEngine
{
#define g_ImGUI Singleton<UIWrapper>::GetInstance()
    class UIWrapper : public Singleton<UIWrapper>
    {
    public:
        friend class Singleton<UIWrapper>;

        void Init();
        void Update(entry::AppI* _app);
        void Shutdown();

    private:

        UIWrapper() {}

    };


}