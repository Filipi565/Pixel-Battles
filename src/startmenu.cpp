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

        static void PlayButtonCallback(void)
        {
            fprintf(stdout, "Testing");
        }
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

        if (play_button == nullptr)
        {
            play_button = new Button();
            play_button->color = WHITE;
            play_button->visible = true;
            play_button->texture = new Texture2D();
            play_button->OnClick(PlayButtonCallback);
            play_button->pos = {GetScreenWidth()/2.0f, GetScreenHeight()/2.0f};
            play_button->size = {GetScreenWidth()/20.0f, GetScreenHeight()/20.0f};

            string result = assets;
            result += "/buttons/Play.png";

            Image image = LoadImage(result.data());
            (*play_button->texture) = LoadTextureFromImage(image);
            UnloadImage(image);
        }

        Rectangle source, dest;

        source = {0.0f, 0.0f, (float)background->width, (float)background->height};
        dest = {0.0f, 0.0f, (float)GetScreenWidth(), (float)GetScreenHeight()};

        DrawTexturePro(*background, source, dest, {0, 0}, 0, WHITE);
        play_button->Load();

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