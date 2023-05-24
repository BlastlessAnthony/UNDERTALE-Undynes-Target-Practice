#ifndef __ORION_FRAMEWORK_SPRITE_HPP__
#define __ORION_FRAMEWORK_SPRITE_HPP__
#pragma once

#include <string>
#include <vector>
#include <Texture.hpp>
#include <Image.hpp>

namespace OrionFramework {
    class Sprite {
        std::vector <raylib::Texture2D *> *textures;
        Sprite();
        void AddFrame(raylib::Texture2D texture);
        void AddFrame(raylib::Image image);
        void AddFrame(std::string filename);
    };
}

#endif //__ORION_FRAMEWORK_SPRITE_HPP__