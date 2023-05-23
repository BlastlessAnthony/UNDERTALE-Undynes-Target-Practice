#pragma once
#include <string>
#include <cstdint>
#include <raylib-cpp.hpp>

namespace UndynesTargetPractice {
    class Application {
        protected:
            raylib::Window *window;
            raylib::RenderTexture2D frame_buffer;

        public:
            Application();
            Application(int32_t window_width, int32_t window_height, std::string window_caption);
            Application(int32_t window_width, int32_t window_height, std::string window_caption, uint32_t window_flags);
            Application(int32_t window_width, int32_t window_height, int32_t framebuffer_width, int32_t framebuffer_height, std::string window_caption);
            Application(int32_t window_width=1024, int32_t window_height=768, int32_t framebuffer_width=1024, int32_t framebuffer_height=768, std::string window_caption="Raylib Window", uint32_t window_flags=(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT));
            Application(raylib::Vector2 window_size, std::string window_caption);
            Application(raylib::Vector2 window_size, raylib::Vector2 framebuffer_size, std::string window_caption);
    };
}
