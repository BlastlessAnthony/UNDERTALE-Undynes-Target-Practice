#include <cstdlib>
#include <iostream>

#include <Window.hpp>
#include <Texture.hpp>
#include <RenderTexture.hpp>
#include <Color.hpp>
#include "GetAspectRatio.hpp"
#include "OperatingSystem.hpp"
#include "ResourcePath.hpp"
#include "Sprite.hpp"
int main(int argc, char **argv)
{
    auto *window = new raylib::Window(640, 480, "Undyne's Target Practice");
    window->SetState(FLAG_WINDOW_RESIZABLE | FLAG_WINDOW_TOPMOST | FLAG_WINDOW_HIGHDPI);
    window->SetTargetFPS(60);
    window->SetMinSize(640, 480);

    SetConfigFlags(FLAG_VSYNC_HINT | FLAG_MSAA_4X_HINT);

    auto *frame_buffer = new raylib::RenderTexture2D(640, 480);
    SetTextureFilter(frame_buffer->texture, TEXTURE_FILTER_BILINEAR);

    bool should_close = false;

    printf("Orion Framework [Info]: Platform is %s\n", OS_PLATFORM);
    printf("Orion Framework [Info]: Resource path is %s\n", OrionFramework::getResourcePath().c_str());

    auto *sprite = new OrionFramework::Sprite();
    sprite->AddTexture(OrionFramework::getResourcePath() + "/icon.png");

    while (!should_close) {

        if (window->ShouldClose()) {should_close = true;}

        frame_buffer->BeginMode();

            ClearBackground(raylib::Color(0x000000));

        frame_buffer->EndMode();

        window->BeginDrawing();

            float aspect_ratio_scale = OrionFramework::GetAspectRatio(640, 480);

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

    delete sprite;
    delete window;
    delete frame_buffer;
    

    exit(EXIT_SUCCESS);
}