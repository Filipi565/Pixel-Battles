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
    ConfigWindowSize();

    ToggleFullscreen();

    while (!WindowShouldClose())
    {
        BeginDrawing();

        if (on_start_menu)
        {
            DrawStartMenu();
            EndDrawing();
            continue;
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}