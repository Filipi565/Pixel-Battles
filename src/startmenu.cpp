#include <pblib.h>
#include <cwalk.h>
#include <string>

using std::string;

namespace PixelBattle
{
    namespace StartMenu
    {
        static bool sound_played = false;
        Texture2D *background = nullptr;
        Button *play_button = nullptr;
        static char frames = 0;
        Sound *sound = nullptr;
    }

    void LoadStartMenu(const char *assets)
    {
        using namespace StartMenu;
        ClearBackground(BLACK);

        if (background == nullptr)
        {
            string result = assets;
            result += "/backgrounds/StartMenu.png";

            Image image = LoadImage(result.data());

            background = new Texture2D();
            (*background) = LoadTextureFromImage(image);

            UnloadImage(image);
        }

        if (sound == nullptr)
        {
            string result = assets;
            result += "/sounds/StartMenu.mp3";

            sound = new Sound();
            (*sound) = LoadSound(result.data());
        }

        Rectangle source, dest;

        source = {0.0f, 0.0f, (float)background->width, (float)background->height};
        dest = {0.0f, 0.0f, (float)GetScreenWidth(), (float)GetScreenHeight()};

        DrawTexturePro(*background, source, dest, {0, 0}, 0, WHITE);

        if (!sound_played)
        {
            if (frames >= 120)
            {
                sound_played = true;

                PlaySound(*sound);
            }
            else
            {
                frames++;
            }
        }
    }
}