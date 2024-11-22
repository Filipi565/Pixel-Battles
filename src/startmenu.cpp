#include <pblib.h>
#include <string>

using std::string;

namespace PixelBattle
{
    namespace StartMenu
    {
        static char frames = 0;
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

        if (!IsMusicStreamPlaying(sound))
        {
            if (frames >= 120)
            {
                frames = 0;

                PlayMusicStream(sound);
            }
            else
            {
                frames++;
            }
        }
    }
}