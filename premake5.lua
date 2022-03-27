workspace "RemaEngine"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "RemaEngine/thirdparty/GLFW/include"

include "RemaEngine/thirdparty/GLFW"

project "RemaEngine"
    location "RemaEngine"
    kind "SharedLib"
    language "C++"
    toolset "v142"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("int/" .. outputdir .. "/%{prj.name}")

    pchheader "remapch.h"
    pchsource "RemaEngine/sources/remapch.cpp"

    files
    {
        "%{prj.name}/sources/**.h",
        "%{prj.name}/sources/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/sources",
        "%{prj.name}/thirdparty/spdlog/include",
        "%{IncludeDir.GLFW}"
    }

    links
    {
        "GLFW",
        "opengl32.lib"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "REMA_PLATFORM_WINDOWS",
            "REMA_BUILD_DLL"
        }

        postbuildcommands
        {
            ("{MKDIR} %{wks.location}bin/" .. outputdir .. "/NovelGame/"),
            ("{COPYFILE} %{cfg.buildtarget.abspath} %{wks.location}bin/" .. outputdir .. "/NovelGame/%{cfg.buildtarget.name}")
        }

    filter "configurations:Debug"
        defines "REMA_DEBUG"
        symbols "On"
    
    filter "configurations:Release"
        defines "REMA_RELEASE"
        optimize "On"
    
    filter "configurations:Dist"
        defines "REMA_DIST"
        optimize "On"

project "NovelGame"
    location "NovelGame"
    kind "ConsoleApp"
    language "C++"
    toolset "v142"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/sources/**.h",
        "%{prj.name}/sources/**.cpp"
    }

    includedirs
    {
        "RemaEngine/thirdparty/spdlog/include",
        "RemaEngine/sources"
    }

    links
    {
        "RemaEngine"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "REMA_PLATFORM_WINDOWS"
        }
        
        postbuildcommands
        {
           --("{COPYFILE} ../bin/" .. outputdir .. "/RemaEngine/RemaEngine.dll ../bin/" .. outputdir .. "/%{prj.name}/")
        }

    filter "configurations:Debug"
        defines "REMA_DEBUG"
        symbols "On"
    
    filter "configurations:Release"
        defines "REMA_RELEASE"
        optimize "On"
    
    filter "configurations:Dist"
        defines "REMA_DIST"
        optimize "On"