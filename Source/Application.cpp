#include "Application.hpp"

namespace UndynesTargetPractice {
    Application::Application(int32_t window_width=1024, int32_t window_height=768, int32_t framebuffer_width=1024, int32_t framebuffer_height=768, std::string window_caption="Raylib Window", uint32_t window_flags=(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT)) {
        window = new raylib::Window(window_width, window_height, window_caption);
        SetConfigFlags(window_flags);
    }
    
    Application::Application(int32_t window_width, int32_t window_height, int32_t framebuffer_width, int32_t framebuffer_height, std::string window_caption)
    {
        Application(window_width, window_height, framebuffer_width, framebuffer_height, window_caption, (FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT));
    }
}