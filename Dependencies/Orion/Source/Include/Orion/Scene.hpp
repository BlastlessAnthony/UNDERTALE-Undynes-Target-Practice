#pragma once
#include <vector>
#include "GameObject.hpp"
namespace OrionFramework {
    class Scene {
        public:
            std::vector<GameObject*> *entities;

            Scene() {
                entities = new std::vector<GameObject*>();
            }

            inline void Update() const {
                for (auto & entity : *entities) {
                    entity->Update();
                    entity->Draw();
                }

            }

            ~Scene() {
                delete entities;
            }

            inline void AddInstance(GameObject *entity) const { 
                entity->setID(entities->size()+1);
                entities->push_back(entity);
            }
    };
}