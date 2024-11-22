#include <pblib.h>
#include <string>

using std::string;

namespace PixelBattle
{
    bool is_game_loaded = false;
    Sound button_click_effect;

    namespace Loader
    {
        using namespace StartMenu;

        static void LoadBackgound(void)
        {
            string result = assets;
            result += "/backgrounds/StartMenu.png";

            Image image = LoadImage(result.data());

            background = LoadTextureFromImage(image);

            UnloadImage(image);
        }

        static void LoadSettingsButton(void)
        {
            settings_button = new Button();
            settings_button->color = WHITE;
            settings_button->visible = true;
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

        static void LoadExtrasButton(void)
        {
            extras_button = new Button();
            extras_button->color = WHITE;
            extras_button->visible = true;
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

        static void LoadBackgroundSound(void)
        {
            string result = assets;
            result += "/sounds/StartMenu.mp3";

            sound = LoadSound(result.data());
        }

        static void LoadPlayButton(void)
        {
            play_button = new Button();
            play_button->color = WHITE;
            play_button->visible = true;
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

        static void LoadButtonClickEffect(void)
        {
            string result = assets;
            result += "/sounds/ButtonClick.wav";

            button_click_effect = LoadSound(result.data());
        }
    }

    void LoadAssets(void)
    {
        using namespace Loader;
        LoadButtonClickEffect();
        LoadBackgroundSound();
        LoadSettingsButton();
        LoadExtrasButton();
        LoadPlayButton();
        LoadBackgound();

        is_game_loaded = true;
    }
}