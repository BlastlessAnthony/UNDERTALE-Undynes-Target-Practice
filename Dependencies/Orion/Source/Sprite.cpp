#include "Orion/Sprite.hpp"

namespace OrionFramework {

    Sprite::Sprite() {
        textures = new std::vector <raylib::Texture2DUnmanaged*>();
    }

    Sprite::~Sprite() {
        delete textures;
    }

    void Sprite::AddTexture(raylib::Texture2DUnmanaged *texture2D) {
        textures->push_back(std::move(texture2D));
    }

    void Sprite::AddTexture(raylib::Image image) {
        AddTexture(new raylib::Texture2DUnmanaged(image));
    }

    void Sprite::AddTexture(std::string file) {
        AddTexture(new raylib::Texture2DUnmanaged(file));
    }

    void Sprite::AddTextures(raylib::Texture2DUnmanaged *textures, uint32_t texture_count) {
        for (int i = 0; i < texture_count; i++) {
            AddTexture(textures[i]);
        }
    }
    
    void Sprite::AddTextures(std::vector<raylib::Texture2DUnmanaged> textures) {
        for (int i = 0; i < textures.size(); i++) {
            AddTexture(textures[i]);
        }
    }
}