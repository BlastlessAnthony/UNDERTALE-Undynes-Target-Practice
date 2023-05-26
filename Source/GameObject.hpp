#ifndef __ORION_FRAMEWORK_ECS_ENTITY_HPP__
#define __ORION_FRAMEWORK_ECS_ENTITY_HPP__
#pragma once

#include <cstdint>
#include "Object.hpp"
#include "Sprite.hpp"
#include "Vector2.hpp"

namespace OrionFramework {
    class GameObject : public Object {
        public:
            Sprite *sprite;
            raylib::Vector2 position;

            GameObject() : Object() {
                sprite = new Sprite();
            }

            virtual void Update() = 0;
            virtual void Draw() = 0;

    };
}

#include "Object.hpp"
#endif //__ORION_FRAMEWORK_ECS_ENTITY_HPP__
