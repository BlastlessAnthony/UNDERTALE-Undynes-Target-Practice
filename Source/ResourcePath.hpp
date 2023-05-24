#ifndef __ORION_FRAMEWORK_UTILITY_RESOURCEPATH_HPP__
#define __ORION_FRAMEWORK_UTILITY_RESOURCEPATH_HPP__
#pragma once

#include <iostream>
#include <string>
#include <raylib.h>
#include "OperatingSystem.hpp"
#include "IsDebug.hpp"
#include "IsOperatingSystem.hpp"

namespace OrionFramework {

    std::string getResourcePath()
    {
        
        //Yeah, this looks a fucking mess... but its required since a function is used to check per platform.
        if (isOperatingSystem(OS_WINDOWS)) {

            return std::string(TextFormat("%sResources", GetApplicationDirectory()));

        } else if (isOperatingSystem(OS_MACOSX)) {

            if (isInDebugMode()) {return std::string(TextFormat("%sResources", GetApplicationDirectory()));}

            return std::string(TextFormat("%s../Resources", GetApplicationDirectory()));

        } else if (isOperatingSystem(OS_LINUX)) {

            if (isInDebugMode()) {return std::string(TextFormat("%sres", GetApplicationDirectory()));}
            return std::string(TextFormat("%s../share/res", GetApplicationDirectory()));

        } else { std::cout << "ORION FRAMEWORK [ERROR]: That platform doesn't have a specified resource path." << std::endl; exit(EXIT_FAILURE); }
    }
}

#endif //__ORION_FRAMEWORK_UTILITY_RESOURCEPATH_HPP__
