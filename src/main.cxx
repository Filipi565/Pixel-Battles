#include <iostream>
#include <pblib.h>

namespace PixelBattle
{
    const int WinWidth = 800;
    const int WinHeight = 600;
}

int main(void)
{
    InitWindow(PixelBattle::WinWidth, PixelBattle::WinHeight, "Pixel Battle");

    while (!WindowShouldClose())
    {
        BeginDrawing();

        

        EndDrawing();
    }

    CloseWindow();

    return 0;
}