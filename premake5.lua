workspace "ARController"
    platforms { "x64" }

    configurations
    { 
        "Debug", 
        "Release",
        "Dist" 
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}"

project "Engine"
    location "Engine"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files 
    { 
        "%{prj.name}/src/**.h", 
        "%{prj.name}/src/**.cpp" 
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include"
    }

    externalincludedirs { "%{prj.name}/vendor/spdlog/include"  } -- This is needed for XCode
    
    filter "configurations:Debug"
        defines { "AR_DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "AR_RELEASE" }
        optimize "On"

    filter "configurations:Dist"
        defines { "AR_DIST" }
        optimize "On"



project "Studio"
    location "Studio"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files 
    { 
        "%{prj.name}/src/**.h", 
        "%{prj.name}/src/**.cpp" 
    }

    includedirs
    {
        "Engine/vendor/spdlog/include",
        "Engine/src"
    }

    externalincludedirs { "Engine/vendor/spdlog/include"  } -- This is needed for XCode

    libdirs { "bin/" .. outputdir .. "/Engine" }
    links
    {
        "Engine"
    }
    
    filter "configurations:Debug"
        defines { "AR_DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "AR_RELEASE" }
        optimize "On"

    filter "configurations:Dist"
        defines { "AR_DIST" }
        optimize "On"