#include <pblib.h>

namespace PixelBattle
{
    extern Sound button_click_effect;

    void UnloadAssets(void)
    {
        using namespace StartMenu;

        UnloadSound(button_click_effect);
        UnloadTexture(background);
        UnloadSound(bg_music);

        delete settings_button;
        delete extras_button;
        delete play_button;
    }
}