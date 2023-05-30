#ifndef __ORION_FRAMEWORK_UTILITY_GETASPECTRATIO_HPP__
#define __ORION_FRAMEWORK_UTILITY_GETASPECTRATIO_HPP__
#pragma once

#include <cstdint>
#include "Window.hpp"

#define MAX(a, b) ((a)>(b)? (a) : (b))
#define MIN(a, b) ((a)<(b)? (a) : (b))
namespace OrionFramework {
    static float GetAspectRatio(raylib::Window *window, uint32_t resolution_width, uint32_t resolution_height)
    {
        return MIN((float)window->GetWidth() / (float)resolution_width, (float)window->GetHeight() / (float)resolution_height);
    }
}

#endif //__ORION_FRAMEWORK_UTILITY_GETASPECTRATIO_HPP__