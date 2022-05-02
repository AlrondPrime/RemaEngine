include "Dependencies.lua"

workspace "RemaEngine"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

group "Dependencies"
    include "RemaEngine/thirdparty/ogg"
    include "RemaEngine/thirdparty/vorbis"
    include "RemaEngine/thirdparty/GLFW"
    include "RemaEngine/thirdparty/Glad"
group ""

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

        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.spdlog}",
        "%{IncludeDir.freealut}",
        "%{IncludeDir.openal_soft}",
        "%{IncludeDir.ogg}",
        "%{IncludeDir.vorbis}",
    }

    links
    {
        "GLFW",
        "Glad",
        "opengl32.lib",

        "openal32",
        "alut",
        "ogg",
        "vorbis"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "REMA_PLATFORM_WINDOWS",
            "REMA_BUILD_DLL",
            "GLFW_INCLUDE_NONE"
        }

        postbuildcommands
        {
            ("{MKDIR} %{wks.location}bin/" .. outputdir .. "/NovelGame/"),
            ("{COPYFILE} %{cfg.buildtarget.abspath} %{wks.location}bin/" .. outputdir .. "/NovelGame/%{cfg.buildtarget.name}")
        }

    filter "configurations:Debug"
        defines "REMA_DEBUG"
        buildoptions "/MDd"
        symbols "On"
    
    filter "configurations:Release"
        defines "REMA_RELEASE"
        buildoptions "/MD"
        optimize "On"
    
    filter "configurations:Dist"
        defines "REMA_DIST"
        buildoptions "/MD"
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
        "%{IncludeDir.spdlog}",
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

    filter "configurations:Debug"
        defines "REMA_DEBUG"
        buildoptions "/MDd"
        symbols "On"
    
    filter "configurations:Release"
        defines "REMA_RELEASE"
        buildoptions "/MD"
        optimize "On"
    
    filter "configurations:Dist"
        defines "REMA_DIST"
        buildoptions "/MD"
        optimize "On"