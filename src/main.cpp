#include <iostream>
#include <pblib.h>

namespace PixelBattle
{
    bool on_start_menu = true;
}

using namespace PixelBattle;

int main(void)
{
    InitWindow(0, 0, "Pixel Battle");

    ToggleFullscreen();

    Entity player;
    player.speed = 20;
    player.color = WHITE;
    player.pos = {GetScreenWidth()/2.0f, GetScreenHeight()/2.0f};

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(BLACK);

        if (on_start_menu)
        {
            DrawStartMenu();
            EndDrawing();
            continue;
        }

        if (IsKeyDown(KEY_A))
        {
            player.pos.x -= player.speed;
        }
        else if (IsKeyDown(KEY_D))
        {
            player.pos.x += player.speed;
        }
        else if (IsKeyDown(KEY_W))
        {
            player.pos.y -= player.speed;
        }
        else if (IsKeyDown(KEY_S))
        {
            player.pos.y += player.speed;
        }

        player.Draw();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}