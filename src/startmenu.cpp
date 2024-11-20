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

            delete background;
            delete sound;

            background = nullptr;
            sound = nullptr;

            settings_button->visible = false;
            play_button->visible = false;
        }

        static void SettingsButtonCallback(void)
        {
            fprintf(stdout, "Settings\n");
        }

        static void ExtrasButtonCallback(void)
        {
            fprintf(stdout, "Extras\n");
        }

        static void CreateBackground(const char *assets)
        {
            string result = assets;
            result += "/backgrounds/StartMenu.png";

            Image image = LoadImage(result.data());

            background = new Texture2D();
            (*background) = LoadTextureFromImage(image);

            UnloadImage(image);
        }

        static void CreateBackgroundSound(const char *assets)
        {
            string result = assets;
            result += "/sounds/StartMenu.mp3";

            sound = new Sound();
            (*sound) = LoadSound(result.data());
        }

        static void CreatePlayButton(const char *assets)
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

        static void CreateSettingsButton(const char *assets)
        {
            settings_button = new Button();
            settings_button->color = WHITE;
            settings_button->visible = true;
            settings_button->OnClick = &SettingsButtonCallback;
            Vector2 size = {GetScreenWidth()/5.0f, GetScreenHeight()/9.0f};
            settings_button->pos = {
                (GetScreenWidth()-size.x)/2,
                (GetScreenHeight()-size.y)/2
            };
            settings_button->size = size;

            string result = assets;
            result += "/buttons/Settings.png";

            Image image = LoadImage(result.data());
            (*settings_button->texture) = LoadTextureFromImage(image);
            UnloadImage(image);
        }

        static void CreateExtrasButton(const char *assets)
        {
            extras_button = new Button();
            extras_button->color = WHITE;
            extras_button->visible = true;
            extras_button->OnClick = &ExtrasButtonCallback;
            Vector2 size = {GetScreenWidth()/5.0f, GetScreenHeight()/9.0f};
            extras_button->pos = {
                (GetScreenWidth()-size.x)/2,
                (GetScreenHeight()-size.y)/2 + size.y + 10
            };
            extras_button->size = size;

            string result = assets;
            result += "/buttons/Extras.png";

            Image image = LoadImage(result.data());
            (*extras_button->texture) = LoadTextureFromImage(image);
            UnloadImage(image);
        }
    }

    void LoadStartMenu(const char *assets)
    {
        using namespace StartMenu;
        ClearBackground(BLACK);

        if (background == nullptr)
        {
            CreateBackground(assets);
        }

        if (sound == nullptr)
        {
            CreateBackgroundSound(assets);
        }

        if (play_button == nullptr)
        {
            CreatePlayButton(assets);
        }

        if (settings_button == nullptr)
        {
            CreateSettingsButton(assets);
        }

        if (extras_button == nullptr)
        {
            CreateExtrasButton(assets);
        }

        Rectangle source, dest;

        source = {0.0f, 0.0f, (float)background->width, (float)background->height};
        dest = {0.0f, 0.0f, (float)GetScreenWidth(), (float)GetScreenHeight()};

        DrawTexturePro(*background, source, dest, {0, 0}, 0, WHITE);

        settings_button->Load();
        extras_button->Load();
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