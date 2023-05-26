#pragma once
#include "Scene.hpp"
#include "DumbObject.hpp"
using namespace OrionFramework;
class DummyScene : public Scene {
    public:
        DummyScene() : Scene() {
            AddInstance((GameObject*)new DumbObject());
        }
};