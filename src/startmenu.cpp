#include <pblib.h>
#include <string>

using std::string;

namespace PixelBattle
{
    namespace StartMenu
    {
        extern Button *settings_button;
        extern Button *extras_button;
        extern Texture2D *background;
        Button *play_button = nullptr;
        extern Sound *sound;

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
        #pragma region Load Items

        static void CreatePlayButton(void)
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

        #pragma endregion
    }

    void LoadStartMenu(void)
    {
        using namespace StartMenu;
        ClearBackground(BLACK);

        if (play_button == nullptr)
        {
            CreatePlayButton();
        }

        Rectangle source, dest;

        source = {0.0f, 0.0f, (float)background->width, (float)background->height};
        dest = {0.0f, 0.0f, (float)GetScreenWidth(), (float)GetScreenHeight()};

        DrawTexturePro(*background, source, dest, {0, 0}, 0, WHITE);

        settings_button->Update();
        extras_button->Update();
        play_button->Update();

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