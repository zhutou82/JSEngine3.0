workspace "JSEngine3.0"
	architecture "x64"
	startproject "JSEngine3.0"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}
  
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
vendordir = "vendor"

vendorIncludeDir = {}
vendorIncludeDir["bgfx"] = "vendor/bgfx"


project "JSEngine3.0"
	location "JSEngine3.0"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	-- pchheader "JSpch.h"
	-- pchsource "JSEngine2.0/src/JSpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	defines
	{
    "__STDC_LIMIT_MACROS",
    "__STDC_FORMAT_MACROS",
    "__STDC_CONSTANT_MACROS",
    "_DEBUG",
    "WIN32",
    "_WIN32",
    "_HAS_EXCEPTIONS",
    "_SCL_SECURE",
    "_SECURE_SCL",
    "_SCL_SECURE_NO_WARNINGS",
    "_CRT_SECURE_NO_WARNINGS",
    "_CRT_SECURE_NO_DEPRECATE",
    "_WIN64",
    "ENTRY_CONFIG_IMPLEMENT_MAIN=1"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include",
    "%{vendorIncludeDir.bgfx}/bx/include/compat/msvc",
    "%{vendorIncludeDir.bgfx}/bx/include",
    "%{vendorIncludeDir.bgfx}/bimg/include",
    "%{vendorIncludeDir.bgfx}/bgfx/include",
    "%{vendorIncludeDir.bgfx}/bgfx/3rdparty",
    "%{vendorIncludeDir.bgfx}/bgfx/examples/common"
    
	}
	links 
	{ 
    "DelayImp.lib",
    "gdi32.lib",
    "psapi.lib"
	}

	filter "system:windows"
		systemversion "latest"
    
		defines
		{
			"JSENGINE_PLATFORM_WINDOWS",
      "JSENGINE_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

	filter "configurations:Debug"
		defines "JS_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "JS_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "JS_DIST"
		runtime "Release"
		optimize "on"
