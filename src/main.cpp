#include <pblib.h>
#include <string>

namespace PixelBattle
{
    const char *executable = nullptr;
    const char *assets = nullptr;
    bool on_start_menu = true;

    void Clean(void);
}

using namespace PixelBattle;
using std::string;

int main(int argc, const char *argv[])
{
    if (!(argc >= 2 && argv[1] == string("--hide-console=off")))
    {
        HideConsole();
    }
    
    InitWindow(0, 0, "Pixel Battle");

    executable = argv[0];
    char *temp_assets_path = GetAssetsPath();
    assets = temp_assets_path;

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
            LoadStartMenu();
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

        player.Update();

        EndDrawing();
    }

    delete[] temp_assets_path;

    Clean();

    CloseAudioDevice();
    CloseWindow();

    return 0;
}