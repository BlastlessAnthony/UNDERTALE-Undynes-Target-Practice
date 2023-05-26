#ifndef __ORION_FRAMEWORK_MISCELLANEOUS_APPLICATION_HPP__
#define __ORION_FRAMEWORK_MISCELLANEOUS_APPLICATION_HPP__
#pragma once

#include <cstdint>
#include "Window.hpp"
#include "RenderTexture.hpp"
#include "ResourcePath.hpp"
#include "OperatingSystem.hpp"
#include "GetAspectRatio.hpp"
#include "Scene.hpp"
#include "SceneCollection.hpp"

namespace OrionFramework {

    class Application {

        protected:
            raylib::Window *window;
            raylib::RenderTexture2D *frame_buffer;
            int32_t window_width = 640;
            int32_t window_height = 480;
            Scene *currentScene = nullptr;
            SceneCollection *scene_collection;

            inline void InitWindow() {
                InitWindowConfig();
                window = new raylib::Window(window_width, window_height, "Undyne's Target Practice");
                InitWindowState();
            }

            inline void InitWindowConfig() const {
                SetConfigFlags(FLAG_WINDOW_HIGHDPI | FLAG_MSAA_4X_HINT);
            }

            inline void InitWindowState() const {
                window->SetState(FLAG_WINDOW_RESIZABLE | FLAG_WINDOW_TOPMOST | FLAG_VSYNC_HINT);
                window->SetTargetFPS(60);
                window->SetMinSize(window_width, window_height);
            }

            inline void InitFrameBuffer() {
                frame_buffer = new raylib::RenderTexture2D(window_width, window_height);
                SetTextureFilter(frame_buffer->texture, TEXTURE_FILTER_BILINEAR);
            }

            inline void UpdateScene() {
                if (currentScene) {
                    currentScene->Update();
                }
            }

        public:
            
            bool should_close = false;
            
            Application() {
                printf("Orion Framework [Info]: Platform is %s\n", OS_PLATFORM);
                printf("Orion Framework [Info]: Resource path is %s\n", getResourcePath().c_str());

                InitWindow();
                InitFrameBuffer();
                scene_collection = new SceneCollection();
                SwitchToScene(0);
            }

            ~Application() {
                delete window;
                delete frame_buffer;
                exit(EXIT_SUCCESS);
            }

            inline void WindowControl() {
                if (window->ShouldClose()) {
                    should_close = true;
                }
            }

            inline void Update() {
                WindowControl();
                Draw();
                Render();
            }

            inline void Draw() {
                frame_buffer->BeginMode();

                    ClearBackground(raylib::Color(0x000000));
                    UpdateScene();

                frame_buffer->EndMode();
            }

            inline void Render() const {
                window->BeginDrawing();

                    float aspect_ratio_scale = GetAspectRatio(640, 480);

                    ClearBackground(raylib::Color(0x000000));

                    DrawTexturePro(
                        frame_buffer->GetTexture(),

                        {
                            0.f, 
                            0.f, 
                            (float)frame_buffer->GetTexture().GetWidth(), 
                            (float)-frame_buffer->GetTexture().GetHeight()
                        },

                        { 
                            (window->GetWidth() - ( (float)window->GetRenderWidth() * aspect_ratio_scale )) * 0.5f,
                            (window->GetHeight() - ((float)window->GetRenderHeight() * aspect_ratio_scale)) * 0.5f,
                            (float)window->GetRenderWidth() * aspect_ratio_scale,
                            (float)window->GetRenderHeight() * aspect_ratio_scale
                        },

                        {0.f, 0.f},
                        0.f,
                        raylib::Color::White()
                    );

                window->EndDrawing();
            }

            inline void SwitchToScene(int32_t index) {
                currentScene = scene_collection->scenes->at(index);
            }
    };

}

#endif //__ORION_FRAMEWORK_MISCELLANEOUS_APPLICATION_HPP__
