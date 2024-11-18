#include <pblib.h>

namespace PixelBattle
{
    void ConfigWindowSize(void)
    {
        int m = GetCurrentMonitor(); // current monitor
        SetWindowSize(GetMonitorWidth(m), GetMonitorHeight(m));
    }
}