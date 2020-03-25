#pragma once
#include <entry/input.h>

namespace JSEngine
{
    class InputClass
    {
    public:

        InputClass();

        void Init();
        void Update();

    private:
        entry::MouseState m_mouseState;
    };

   
}