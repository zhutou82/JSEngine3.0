#include "JSEngine.h"
#include "Graphics/Graphics.h"
#include "UI.h"

namespace JSEngine
{
    void JSApp::init(int32_t _argc, const char* const* _argv, uint32_t _width, uint32_t _height)
	{		
		JS_CORE_INFO("Welcome to JSEngine3.0");
		g_GraphicsWrapper.Init(_argc, _argv, _width, _height);
		g_ImGUI.Init();
	}

	int JSApp::shutdown()
	{
		g_GraphicsWrapper.Shutdown();
		g_ImGUI.Shutdown();
		return 0;
	}

	bool JSApp::update()
	{
		g_GraphicsWrapper.Update(this);
		return true;
	}


}