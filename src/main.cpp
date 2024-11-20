#include <pblib.h>

namespace PixelBattle
{
    const char *executable = nullptr;
    bool on_start_menu = true;
}

using namespace PixelBattle;

int main(int, const char *argv[])
{
    InitWindow(0, 0, "Pixel Battle");

    executable = argv[0];
    char *assets = GetAssetsPath();

    ToggleFullscreen();

    Entity player;
    player.speed = 10;
    player.color = WHITE;
    player.pos = {GetScreenWidth()/2.0f, GetScreenHeight()/2.0f};

    SetTargetFPS(60);

    InitAudioDevice();

    while (!WindowShouldClose())
    {
        if (!IsCursorOnScreen() && GetTime() >= 5)
        {
            MinimizeWindow();
        }

        BeginDrawing();

        if (on_start_menu)
        {
            LoadStartMenu(assets);
            EndDrawing();
            continue;
        }

        ClearBackground(BLACK);

        if (IsKeyDown(KEY_A))
        {
            player.pos.x -= player.speed;
        }
        else if (IsKeyDown(KEY_D))
        {
            player.pos.x += player.speed;
        }

        player.Draw();

        EndDrawing();
    }

    if (StartMenu::sound != nullptr)
    {
        UnloadSound(*StartMenu::sound);
        delete StartMenu::sound;
    }

    if (StartMenu::background != nullptr)
    {
        UnloadTexture(*StartMenu::background);
        delete StartMenu::background;
    }

    if (StartMenu::play_button != nullptr)
    {
        delete StartMenu::play_button;
    }

    CloseAudioDevice();
    CloseWindow();

    return 0;
}