workspace "CoffeeEngine"
    architecture "x64"
    startproject "Sandbox"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Coffee"
    location "Coffee"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/vendor/spdlog/include"
    }

    buildoptions
    {
        "/utf-8"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "CF_PLATFORM_WINDOWS", 
            "COFFEE_BUILD_DLL"
        }

        postbuildcommands
        {
            {"{COPYFILE} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox"}
        }

    filter "configurations:Debug"
        defines "CF_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "CF_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "CF_DIST"
        optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "Coffee/vendor/spdlog/include",
        "Coffee/src"
    }

    links 
    {
        "Coffee"
    }

    buildoptions
    {
        "/utf-8"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "CF_PLATFORM_WINDOWS",
        }

    filter "configurations:Debug"
        defines "CF_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "CF_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "CF_DIST"
        optimize "On"
    
