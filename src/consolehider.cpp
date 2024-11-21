#ifdef _WIN32
#include <windows.h>
#endif

namespace PixelBattle
{
    void HideConsole(void)
    {
        #ifdef _WIN32
        ShowWindow(GetConsoleWindow(), SW_HIDE);
        #else
        #endif
    }
}