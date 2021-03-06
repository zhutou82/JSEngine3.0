#include "Graphics.h"
static const uint8_t s_logo[2] = { 1, 2 };

namespace JSEngine
{
    void GraphicsWrapper::Init(int32_t _argc, const char* const* _argv, uint32_t _width, uint32_t _height)
    {
		Args args(_argc, _argv);
		m_WindowWidth = _width;
		m_WindowHeight = _height;
		m_Debug = BGFX_DEBUG_TEXT;
		m_Reset = BGFX_RESET_VSYNC;

		bgfx::Init init;
		init.type = args.m_type;
		init.vendorId = args.m_pciId;
		init.resolution.width = m_WindowWidth;
		init.resolution.height = m_WindowHeight;
		init.resolution.reset = m_Reset;
		bgfx::init(init);

		// Enable debug text.
		bgfx::setDebug(m_Debug);

		// Set view 0 clear state.
		bgfx::setViewClear(0
			, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH
			, 0x303030ff
			, 1.0f
			, 0
			);

		JS_CORE_TRACE("Initialized Graphics Wrapper Class");
    }

    void GraphicsWrapper::Update(entry::AppI* app)
    {
		if (!entry::processEvents(m_WindowWidth, m_WindowHeight, m_Debug, m_Reset, &m_mouseState))
		{
			imguiBeginFrame(m_mouseState.m_mx
							, m_mouseState.m_my
							, (m_mouseState.m_buttons[entry::MouseButton::Left] ? IMGUI_MBUT_LEFT : 0)
							| (m_mouseState.m_buttons[entry::MouseButton::Right] ? IMGUI_MBUT_RIGHT : 0)
							| (m_mouseState.m_buttons[entry::MouseButton::Middle] ? IMGUI_MBUT_MIDDLE : 0)
							, m_mouseState.m_mz
							, uint16_t(m_WindowWidth)
							, uint16_t(m_WindowHeight)
							);

			showExampleDialog(app);
			

			imguiEndFrame();

			// Set view 0 default viewport.
			bgfx::setViewRect(0, 0, 0, uint16_t(m_WindowWidth), uint16_t(m_WindowHeight));

			// This dummy draw call is here to make sure that view 0 is cleared
			// if no other draw calls are submitted to view 0.
			bgfx::touch(0);

			// Use debug font to print information about this example.
			bgfx::dbgTextClear();
			bgfx::dbgTextImage(
				bx::max<uint16_t>(uint16_t(m_WindowWidth / 2 / 8), 20) - 20
				, bx::max<uint16_t>(uint16_t(m_WindowHeight / 2 / 16), 6) - 6
				, 40
				, 12
				, s_logo
				, 160
				);
			bgfx::dbgTextPrintf(0, 1, 0x0f, "Color can be changed with ANSI \x1b[9;me\x1b[10;ms\x1b[11;mc\x1b[12;ma\x1b[13;mp\x1b[14;me\x1b[0m code too.");

			bgfx::dbgTextPrintf(80, 1, 0x0f, "\x1b[;0m    \x1b[;1m    \x1b[; 2m    \x1b[; 3m    \x1b[; 4m    \x1b[; 5m    \x1b[; 6m    \x1b[; 7m    \x1b[0m");
			bgfx::dbgTextPrintf(80, 2, 0x0f, "\x1b[;8m    \x1b[;9m    \x1b[;10m    \x1b[;11m    \x1b[;12m    \x1b[;13m    \x1b[;14m    \x1b[;15m    \x1b[0m");

			const bgfx::Stats* stats = bgfx::getStats();
			bgfx::dbgTextPrintf(0, 2, 0x0f, "Backbuffer %dW x %dH in pixels, debug text %dW x %dH in characters."
				, stats->width
				, stats->height
				, stats->textWidth
				, stats->textHeight
				);

			// Advance to next frame. Rendering thread will be kicked to
			// process submitted rendering primitives.
			bgfx::frame();
		}
    }

	void GraphicsWrapper::Shutdown()
	{
		// Shutdown bgfx.
		bgfx::shutdown();
	}

}