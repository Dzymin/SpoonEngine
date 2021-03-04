project "Sandbox"
    language "C++"
    cppdialect "C++17"
    kind "WindowedApp"

    targetdir ("%{wks.location}/bin/" .. OutputDir .. "/%{prj.name}")
    objdir ("%{wks.location}/obj/" .. OutputDir .. "/%{prj.name}")

    links {
        "Engine"
    }

    files {
        "Source/**.h",
        "Source/**.cpp"
    }

    includedirs {
        "Source/",
        "%{wks.location}/Engine/Source/",
        "%{wks.location}/Engine/Vendor/spdlog/include"
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