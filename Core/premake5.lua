project "Core"
    language "C++"
    cppdialect "C++17"
    kind "StaticLib"

    targetdir ("%{wks.location}/bin/" .. OutputDir .. "/%{prj.name}")
    objdir ("%{wks.location}/obj/" .. OutputDir .. "/%{prj.name}")

    files {
        "Source/**.h",
        "Source/**.cpp"
    }

    includedirs {
        "Source/"
    }

    filter "system:Windows"
        systemversion "latest"
        defines { 
            "SPOON_PLATFORM_WINDOWS",
            "WIN32_LEAN_AND_MEAN" 
        }

    filter "action:vs*"
        defines { "SPOON_TOOLSET_MSVC" }

    filter "configurations:Debug"
        runtime "Debug"
        symbols "On"
        defines { "SPOON_DEBUG" }

    filter "configurations:Release"
        runtime "Release"
        optimize "On"
        defines { "SPOON_RELEASE" }