#pragma once
#include "ResourcePath.hpp"
#include "GameObject.hpp"
#include "Texture.hpp"
#include "Color.hpp"
using namespace OrionFramework;
class DumbObject : public GameObject {
    public:
        DumbObject() : GameObject() {
            sprite->AddTexture(getResourcePath() + "/icon.png");
        };

        void Update () override {
            
        }

        void Draw() override {
            sprite->GetFrame(0)->Draw((Vector2){0, 0}, (Color){255, 255, 255, 255});
        }
};