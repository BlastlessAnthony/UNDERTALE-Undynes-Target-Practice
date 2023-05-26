#ifndef __ORION_FRAMEWORK_UTILITY_ISOPERATINGSYSTEM_HPP__
#define __ORION_FRAMEWORK_UTILITY_ISOPERATINGSYSTEM_HPP__
#include <string>
#include "OperatingSystem.hpp"
namespace OrionFramework {
    static bool isOperatingSystem(std::string OS)
    {
        #if defined(_WIN32)

            return _stricmp(OS_PLATFORM, OS.c_str()) == 0 ? 1 : 0;
        #else
            
            return std::string(OS_PLATFORM).compare(OS);
        #endif
    }
}
#endif //__ORION_FRAMEWORK_UTILITY_ISOPERATINGSYSTEM_HPP__