#include <iostream>
#include <pblib.h>

namespace PixelBattle
{
    const int WinWidth = 800;
    const int WinHeight = 600;
}

using namespace PixelBattle;

int main(void)
{
    InitWindow(WinWidth, WinHeight, "Pixel Battle");

    while (!WindowShouldClose())
    {
        BeginDrawing();

        

        EndDrawing();
    }

    CloseWindow();

    return 0;
}