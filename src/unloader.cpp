#include <pblib.h>

namespace PixelBattle
{
    extern Sound button_click_effect;

    void UnloadAssets(void)
    {
        using namespace StartMenu;

        UnloadSound(button_click_effect);
        UnloadTexture(background);
        UnloadMusicStream(sound);

        delete settings_button;
        delete extras_button;
        delete play_button;
    }
}