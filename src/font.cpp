#include <pblib.h>
#include <cwalk.h>

namespace PixelBattle
{
    Font font;

    void LoadGlobalFont(const char *executable)
    {
        char absolute[4096];
        PathAbsolute(absolute, 4096, executable);

        char font_path[4096];

        cwk_path_join(absolute, "Assets/fonts/dpcomic.ttf", font_path, 4096);

        font = LoadFont(font_path);
    }
}