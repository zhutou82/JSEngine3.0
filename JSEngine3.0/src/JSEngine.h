#pragma once
#include "Core/PCH.h"
/*
 * Copyright 2011-2020 Branimir Karadzic. All rights reserved.
 * License: https://github.com/bkaradzic/bgfx#license-bsd-2-clause
 */
#include <bx/uint32_t.h>
#include "common.h"
#include "bgfx_utils.h"
#include "imgui/imgui.h"

namespace JSEngine
{
	

	class JSApp : public entry::AppI
	{
	public:
		JSApp(const char* _name, const char* _description, const char* _url)
			: entry::AppI(_name, _description, _url)
		{
			g_Logger.Init();
		}
		void init(int32_t _argc, const char* const* _argv, uint32_t _width, uint32_t _height) override;
		virtual int shutdown() override;
		bool update() override;

	private:
		entry::MouseState m_mouseState;
		uint32_t m_width;
		uint32_t m_height;
		uint32_t m_debug;
		uint32_t m_reset;
	};
}

