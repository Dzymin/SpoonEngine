project "Core"
    language "C++"
    cppdialect "C++17"
    kind "StaticLib"

    targetdir ("%{wks.location}/bin/" .. OutputDir .. "/%{prj.name}")
    objdir ("%{wks.location}/obj/" .. OutputDir .. "/%{prj.name}")

    pchheader "spch.h"
    pchsource "Source/spch.cpp"

    files {
        "Source/**.h",
        "Source/**.cpp"
    }

    includedirs {
        "Source/",
        "Vendor/spdlog/include/"
    }

    filter "system:Windows"
        systemversion "latest"
        defines { 
            "SP_PLATFORM_WINDOWS",
            "WIN32_LEAN_AND_MEAN" 
        }

    filter "action:vs*"
        defines { "SP_TOOLSET_MSVC" }

    filter "configurations:Debug"
        runtime "Debug"
        symbols "On"
        defines { "SP_DEBUG" }

    filter "configurations:Release"
        runtime "Release"
        optimize "On"
        defines { "SP_RELEASE" }