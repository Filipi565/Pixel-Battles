#include <pblib.h>
#include <string>
#include <thread>

namespace PixelBattle
{
    const char *executable = nullptr;
    const char *assets = nullptr;
    extern bool is_game_loaded;
    bool on_start_menu = true;
}

using namespace PixelBattle;
using std::string;

namespace Application
{
    int Run(int &argc, const char *argv[]);
}

// On my pc using WinMain does not work propely
int main(int argc, const char *argv[])
{
    return Application::Run(argc, argv);
}

int Application::Run(int &argc, const char *argv[])
{
    if (!(argc >= 2 && argv[1] == string("--hide-console=off")))
    {
        HideConsole();
    }

    InitWindow(0, 0, "Pixel Battle");

    executable = argv[0];
    char *assets_path = GetAssetsPath();
    assets = assets_path; // Set it globaly

    InitAudioDevice();

    ToggleFullscreen();

    Entity player;
    player.speed = 10;
    player.color = WHITE;
    player.pos = {GetScreenWidth()/2.0f, GetScreenHeight()/2.0f};

    SetTargetFPS(60);

    // Load all Assets
    std::thread _loader = std::thread(LoadAssets);

    while (!is_game_loaded)
    {
        BeginDrawing();
        ClearBackground(BLACK);
        DrawText("Loading...", 10, 20, 30, WHITE);
        EndDrawing();
    }

    // Load all Textures from the images
    // Note: textures can not be loaded outside the main thread
    LoadTextures();

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

        player.Update();

        EndDrawing();
    }

    delete[] assets_path;

    UnloadAssets();

    CloseAudioDevice();
    CloseWindow();

    return 0; 
}