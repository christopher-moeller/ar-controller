workspace "ARController"
    platforms { "x64" }

    configurations
    { 
        "Debug", 
        "Release",
        "Dist" 
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}"

include "Engine/vendor/Glad"
include "Engine/vendor/ImGui"

project "Engine"
    location "Engine"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    defines {
        "GLFW_INCLUDE_NONE"
    }

    files 
    { 
        "%{prj.name}/src/**.h", 
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor/GLFW/include",
        "%{prj.name}/vendor/spdlog/include",
        "%{prj.name}/vendor/GLM/include",
        "%{prj.name}/vendor/Glad/include",
        "%{prj.name}/vendor/ImGui/ImGui", 
        "%{prj.name}/vendor/ImGui/ImGui/backends"
    }

    externalincludedirs { 
        "%{prj.name}/vendor/spdlog/include", 
        "%{prj.name}/vendor/GLM/include",
        "%{prj.name}/vendor/GLFW/include",
        "%{prj.name}/vendor/Glad/include",
        "%{prj.name}/vendor/ImGui/ImGui", 
        "%{prj.name}/vendor/ImGui/ImGui/backends"
    } -- This is needed for XCode

    libdirs {
        "%{prj.name}/vendor/GLFW/lib",
        "%{prj.name}/vendor/GLM/lib",
    }

    links {
        "GLFW",
        "Glad",
        "ImGui",
        "GLM",
        "OpenGL.framework"            -- OpenGL on macOS
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
        "%{prj.name}/src/**.cpp",
    }

    includedirs
    {
        "Engine/vendor/spdlog/include",
        "Engine/vendor/Glad/include",
        "Engine/vendor/GLM/include",
        "Engine/src",
        "Engine/vendor/ImGui/ImGui", 
        "Engine/vendor/ImGui/ImGui/backends"
    }

    externalincludedirs { 
        "Engine/vendor/spdlog/include",
        "Engine/vendor/GLM/include",
        "Engine/vendor/Glad/include",
        "Engine/vendor/ImGui/ImGui", 
        "Engine/vendor/ImGui/ImGui/backends"
      } -- This is needed for XCode

    libdirs { 
        "bin/" .. outputdir .. "/Engine",
        "Engine/vendor/GLFW/lib",
        "Engine/vendor/GLM/lib",
     }
    links
    {
        "Engine",
        "GLFW",
        "GLM",
        "OpenGL.framework"            -- OpenGL on macOS
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