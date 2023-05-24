#include "Sprite.hpp"

namespace OrionFramework {
    Sprite::Sprite() {
        textures = new std::vector <raylib::Texture2D *>();
    }
}