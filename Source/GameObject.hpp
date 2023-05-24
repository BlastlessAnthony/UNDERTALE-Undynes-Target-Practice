#pragma once
#include <cstdint>

uint64_t object_count = 0;

class GameObject {

    public:
        uint64_t id;
        uint64_t uuid;

        virtual void OnCreation() = 0;
        virtual void OnUpdate() = 0;
        virtual void OnDraw() = 0;
        virtual void OnDestuction() = 0;
        virtual ~GameObject() = default;
        GameObject() {};

};