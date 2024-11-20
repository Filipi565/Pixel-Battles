#include <pblib.h>
#include <string>

using std::string;

namespace PixelBattle
{
    namespace StartMenu
    {
        Button *settings_button = nullptr;
        Button *extras_button = nullptr;
        Texture2D *background = nullptr;
        Button *play_button = nullptr;
        Sound *sound = nullptr;

        static bool sound_played = false;
        static char frames = 0;

        static void PlayButtonCallback(void)
        {
            on_start_menu = false;
            sound_played = false;

            UnloadTexture(*background);
            UnloadSound(*sound);

            delete play_button;
            delete background;
            delete sound;

            play_button = nullptr;
            background = nullptr;
            sound = nullptr;
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
            play_button->OnClick = &PlayButtonCallback;
            Vector2 size = {GetScreenWidth()/5.0f, GetScreenHeight()/9.0f};
            play_button->pos = {
                (GetScreenWidth()-size.x)/2,
                (GetScreenHeight()-size.y)/2 - size.y - 10
            };
            play_button->size = size;

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
                frames = 0;

                PlaySound(*sound);
            }
            else
            {
                frames++;
            }
        }
    }
}