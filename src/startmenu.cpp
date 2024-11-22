#include <pblib.h>
#include <string>

using std::string;

namespace PixelBattle
{
    namespace StartMenu
    {
        static bool sound_played = false;
        static char frames = 0;

        #pragma region Callbacks
        static void PlayButtonCallback(void)
        {
            on_start_menu = false;
            sound_played = false;

            settings_button->visible = false;
            play_button->visible = false;
        }

        #pragma endregion
    }

    void LoadStartMenu(void)
    {
        using namespace StartMenu;
        ClearBackground(BLACK);

        Rectangle source, dest;

        source = {0.0f, 0.0f, (float)background.width, (float)background.height};
        dest = {0.0f, 0.0f, (float)GetScreenWidth(), (float)GetScreenHeight()};

        DrawTexturePro(background, source, dest, {0, 0}, 0, WHITE);

        settings_button->Update();
        extras_button->Update();
        play_button->Update();

        if (!sound_played)
        {
            if (frames >= 120)
            {
                sound_played = true;
                frames = 0;

                PlaySound(sound);
            }
            else
            {
                frames++;
            }
        }
    }
}