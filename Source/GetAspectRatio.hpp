#ifndef __ORION_FRAMEWORK_UTILITY_GETASPECTRATIO_HPP__
#define __ORION_FRAMEWORK_UTILITY_GETASPECTRATIO_HPP__
#pragma once

#include <cstdint>
#include "Window.hpp"
namespace OrionFramework {
    static float GetAspectRatio(Vector2 resolution)
    {
        #define MAX(a, b) ((a)>(b)? (a) : (b))
        #define MIN(a, b) ((a)<(b)? (a) : (b))
        return MIN((float)GetScreenWidth() / resolution.x, (float)GetScreenHeight() / resolution.y);
    }

    static float GetAspectRatio(uint32_t resolution_width, uint32_t resolution_height)
    {
        #define MAX(a, b) ((a)>(b)? (a) : (b))
        #define MIN(a, b) ((a)<(b)? (a) : (b))
        return MIN((float)GetScreenWidth() / (float)resolution_width, (float)GetScreenHeight() / (float)resolution_height);
    }
}

#endif //__ORION_FRAMEWORK_UTILITY_GETASPECTRATIO_HPP__