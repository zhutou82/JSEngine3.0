#include "UI.h"
namespace JSEngine
{
    
    void UIWrapper::Init()
    {
        imguiCreate();
        JS_CORE_TRACE("Initialized UI Class");
    }

    void UIWrapper::Update(entry::AppI* _app)
    {


    }

    void UIWrapper::Shutdown()
    {
        imguiDestroy();
    }

}
