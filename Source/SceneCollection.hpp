#pragma once
#include <vector>
#include "Scene.hpp"
#include "DummyScene.hpp"
namespace OrionFramework {

    class SceneCollection {
        public:
            std::vector<Scene*> *scenes;

            inline void AddScenes () {
                scenes->push_back(new DummyScene());
            }

            SceneCollection() {
                scenes = new std::vector<Scene*>();
                AddScenes();
            }

            
    };
}