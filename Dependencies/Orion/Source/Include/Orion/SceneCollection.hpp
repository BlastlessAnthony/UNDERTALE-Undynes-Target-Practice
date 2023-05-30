#pragma once
#include <vector>
#include "Scene.hpp"
namespace OrionFramework {

    class SceneCollection {
        public:
            std::vector<Scene*> *scenes;

            inline void AddScenes () {
                
            }

            SceneCollection() {
                scenes = new std::vector<Scene*>();
                AddScenes();
            }

            
    };
}