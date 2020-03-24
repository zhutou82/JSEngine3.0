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
		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
		-- "%{IncludeDir.GLFW}"
	}

	-- links 
	-- { 
		-- "GLFW",
    -- "opengl32.lib"
	-- }

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
