#ifndef __ORION_FRAMEWORK_MISCELLANEOUS_APPLICATION_HPP__
#define __ORION_FRAMEWORK_MISCELLANEOUS_APPLICATION_HPP__
#pragma once

#include "Window.hpp"
#include "TextureUnmanaged.hpp"
#include "RenderTexture.hpp"
class Application {
    protected:
        raylib::Window *window;
        raylib::RenderTexture2D *frame_buffer;

    public:
        
        Application() {
            window = new raylib::Window(640, 480, "Undyne's Target Practice");
            frame_buffer = new raylib::RenderTexture2D(640, 480);
        }

        ~Application() {

        }

        void InitWindowConfig() {
            window->SetState(FLAG_WINDOW_RESIZABLE | FLAG_WINDOW_TOPMOST | FLAG_WINDOW_HIGHDPI);
            window->SetTargetFPS(60);
            window->SetMinSize(640, 480);
        }
};

#endif //__ORION_FRAMEWORK_MISCELLANEOUS_APPLICATION_HPP__