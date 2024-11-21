#include <pblib.h>

namespace PixelBattle
{
    extern Sound *button_click_effect;

    void Clean(void)
    {
        using namespace StartMenu;
        if (sound != nullptr)
        {
            UnloadSound(*sound);
            delete sound;
        }

        if (background != nullptr)
        {
            UnloadTexture(*background);
            delete background;
        }

        if (play_button != nullptr)
        {
            delete play_button;
        }

        if (settings_button != nullptr)
        {
            delete settings_button;
        }

        if (extras_button != nullptr)
        {
            delete extras_button;
        }

        if (button_click_effect != nullptr)
        {
            UnloadSound(*button_click_effect);
            delete button_click_effect;
        }
    }
}