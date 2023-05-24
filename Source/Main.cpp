#include <cstdlib>
#include <iostream>

#include <Window.hpp>
#include <Texture.hpp>
#include <RenderTexture.hpp>
#include <Color.hpp>
#include "GetAspectRatio.hpp"
int main(int argc, char **argv)
{
    raylib::Window *window = new raylib::Window(640, 480, "Undyne's Target Practice");
    window->SetState(FLAG_WINDOW_RESIZABLE | FLAG_WINDOW_TOPMOST | FLAG_WINDOW_HIGHDPI);
    window->SetTargetFPS(60);
    window->SetMinSize(640, 480);

    SetConfigFlags(FLAG_VSYNC_HINT | FLAG_MSAA_4X_HINT);

    raylib::RenderTexture2D *frame_buffer = new raylib::RenderTexture2D(640, 480);
    SetTextureFilter(frame_buffer->GetTexture(), TEXTURE_FILTER_BILINEAR);

    bool should_close = false;
    while (!should_close) {
        if (window->ShouldClose()) {should_close = true;}

        frame_buffer->BeginMode();

            ClearBackground(raylib::Color::Black());

        frame_buffer->EndMode();

        window->BeginDrawing();

            float aspect_ratio_scale = OrionFramework::GetAspectRatio(640, 480);
            std::cout << aspect_ratio_scale << std::endl;

            ClearBackground(raylib::Color::Black());

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


    

    

    exit(EXIT_SUCCESS);
}