#include <pblib.h>

namespace PixelBattle
{
    void Clean(void)
    {
        if (StartMenu::sound != nullptr)
        {
            UnloadSound(*StartMenu::sound);
            delete StartMenu::sound;
        }

        if (StartMenu::background != nullptr)
        {
            UnloadTexture(*StartMenu::background);
            delete StartMenu::background;
        }

        if (StartMenu::play_button != nullptr)
        {
            delete StartMenu::play_button;
        }
    }
}