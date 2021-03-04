workspace "SpoonEngine"
    architecture "x86_64"
    startproject "Sandbox"

    OutputDir = "%{cfg.system}/%{cfg.buildcfg}-%{cfg.architecture}"

    configurations {
        "Debug",
        "Release"
    }

    include "Engine"
    include "Sandbox"