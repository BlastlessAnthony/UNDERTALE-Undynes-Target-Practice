#ifndef __ORION_FRAMEWORK_SPRITE_HPP__
#define __ORION_FRAMEWORK_SPRITE_HPP__
#pragma once

#include <string>
#include <vector>
#include <cstdint>
#include <Texture.hpp>
#include <TextureUnmanaged.hpp>
#include <Image.hpp>

namespace OrionFramework {
    class Sprite {
        protected:
        
            std::vector <raylib::Texture2DUnmanaged*> *textures;

        public:
            Sprite();
            ~Sprite();

            //The master function for adding textures.

            /// @brief Add a texture to the sprite.
            /// @param texture2D 
            void AddTexture(raylib::Texture2DUnmanaged *texture2D);

            /// @brief Adds a texture to the sprite via an image.
            /// @param image 
            void AddTexture(raylib::Image image);

            /// @brief Adds a texture to the sprite via loading a texture from disk.
            /// @param file 
            void AddTexture(std::string file);
            
            /// @brief Adds multiple textures to a sprite via an array of textures.
            /// @param textures The array of textures, as a pointer. Obviously.
            /// @param texture_count The amount of textures in the array. Needed since you can't tell the size.
            void AddTextures(raylib::Texture2DUnmanaged *textures, uint32_t texture_count);

            /// @brief 
            /// @param textures 
            void AddTextures(std::vector<raylib::Texture2DUnmanaged> textures);

            inline raylib::Texture2DUnmanaged *GetFrame(uint32_t frame) {
                return textures->at(frame);
            }

            
    };
}

#endif //__ORION_FRAMEWORK_SPRITE_HPP__
