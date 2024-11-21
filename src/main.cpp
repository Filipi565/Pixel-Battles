#include <pblib.h>

namespace PixelBattle
{
    const char *executable = nullptr;
    bool on_start_menu = true;

    void Clean(void);
}

using namespace PixelBattle;

int main(int argc, const char *argv[])
{
    HideConsole();
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
        if (!IsCursorOnScreen() && GetTime() >= 5 && !IsWindowMinimized())
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

        player.Load();

        EndDrawing();
    }

    delete[] assets;

    Clean();

    CloseAudioDevice();
    CloseWindow();

    return 0;
}