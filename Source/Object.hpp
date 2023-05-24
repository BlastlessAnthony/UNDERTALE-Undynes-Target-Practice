#pragma once
#include <cstdint>

namespace OrionFramework {
    class Object {

        private:
            uint64_t id;
            uint64_t uuid;
        
        protected:
            uint64_t getID() {return id;}

        public:
            Object();
            ~Object();

    };
}
