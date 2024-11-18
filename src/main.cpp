#include <iostream>
#include <pblib.h>

namespace PixelBattle
{
    const int WinWidth = 800;
    const int WinHeight = 600;
    bool on_start_menu = true;
}

using namespace PixelBattle;

int main(void)
{
    InitWindow(WinWidth, WinHeight, "Pixel Battle");

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