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
            Sprite() {
                textures = new std::vector <raylib::Texture2DUnmanaged*>();
            }

            ~Sprite() {
                delete textures;
            }

            //The master function for adding textures.

            /// @brief Add a texture to the sprite.
            /// @param texture2D 
            inline void AddTexture(raylib::Texture2DUnmanaged *texture2D) const {
                textures->push_back(std::move(texture2D));
            }

            inline void AddTexture(raylib::Image image) const {
                AddTexture(new raylib::Texture2DUnmanaged(image));
            }

            inline void AddTexture(std::string file) const {
                AddTexture(new raylib::Texture2DUnmanaged(file));
            }

            inline void AddTextures(raylib::Texture2DUnmanaged *textures, uint32_t texture_count) const {
                for (int i = 0; i < texture_count; i++) {
                    AddTexture(textures[i]);
                }
            }

            inline void AddTextures(std::vector<raylib::Texture2DUnmanaged> textures) const {
                for (int i = 0; i < textures.size(); i++) {
                    AddTexture(textures[i]);
                }
            }

            inline raylib::Texture2DUnmanaged *GetFrame(uint32_t frame) {
                return textures->at(frame);
            }
    };
}

#endif //__ORION_FRAMEWORK_SPRITE_HPP__
