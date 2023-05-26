#ifndef __ORION_FRAMEWORK_ECS_OBJECT_HPP__
#define __ORION_FRAMEWORK_ECS_OBJECT_HPP__
#pragma once

#include <cstdint>
#include <string>
#include "RandomString.hpp"
namespace OrionFramework {
    class Object {

        private:
            uint64_t id = -1;
            std::string uuid = "";
        
        protected:
            uint64_t getID() {return id;}

        public:
            inline Object() {
                uuid = generateRandomString(32);
            }

            inline void setID(uint64_t _id) {id = _id;}

    };
}

#endif //__ORION_FRAMEWORK_ECS_OBJECT_HPP__
