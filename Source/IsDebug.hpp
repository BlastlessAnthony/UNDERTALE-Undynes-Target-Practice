#ifndef __ORION_UTILITY_ISDEBUGMODE_HPP__
#define __ORION_UTILITY_ISDEBUGMODE_HPP__

namespace OrionFramework {
    static bool isInDebugMode(void)
    {
        #if defined(NDEBUG)
            return false;
        #endif

        return true;
    }
}

#endif //__ORION_UTILITY_ISDEBUGMODE_HPP__
