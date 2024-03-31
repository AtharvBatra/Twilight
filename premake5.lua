workspace "Twilight"
  architecture "x64"

  configurations
  {
    "Debug",
    "Release",
    "Dist"
  }

  outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

  project "Sky"
    location "Sky"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir)
    objdir ("bin-int/" .. outputdir)

    files
    {
      "%{prj.name}/src/**.h",
      "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
      "Twilight/deplibs/spdlog/include",
      "Twilight/src"
    }

    links
    {
      "Twilight"
    }

    filter "system:windows"
      cppdialect "C++17"
      staticruntime "On"
      systemversion "latest"

      defines
      {
        "TWI_PLATFORM_WINDOWS",
      }

    filter "configurations:Debug"
      defines "TWI_DEBUG"
      symbols "On"

    filter "configurations:Release"
      defines "TWI_RELEASE"
      optimize "On"

    filter "configurations:Dist"
      defines "TWI_DIST"
      optimize "On"

  project "Twilight"
    location "Twilight"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir)
    objdir ("bin-int/" .. outputdir)

    pchheader "twipch.h"
    pchsource "%{prj.name}/src/twipch.cpp"

    files
    {
      "%{prj.name}/src/**.h",
      "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
      "%{prj.name}/deplibs/spdlog/include",
      "%{prj.name}/src"
    }

    filter "system:windows"
      cppdialect "C++17"
      staticruntime "On"
      systemversion "latest"

      defines
      {
        "TWI_PLATFORM_WINDOWS",
        "TWI_BUILD_DLL"
      }

    filter "configurations:Debug"
      defines "TWI_DEBUG"
      symbols "On"

    filter "configurations:Release"
      defines "TWI_RELEASE"
      optimize "On"

    filter "configurations:Dist"
      defines "TWI_DIST"
      optimize "On"
