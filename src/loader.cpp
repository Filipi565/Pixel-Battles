#include <pblib.h>
#include <string>

using std::string;

namespace PixelBattle
{
    namespace StartMenu
    {
        Texture2D bird_sprite[3];
        Button *settings_button;
        Button *extras_button;
        Texture2D background;
        Button *play_button;
        Sound bg_music;

        #pragma region Sprites
        static Image *bird_sprite_images;
        #pragma endregion

        #pragma region Images
        static Image *background_image;
        static Image *settings_image;
        static Image *extras_image;
        static Image *play_image;
        #pragma endregion
    }

    bool is_assets_loaded = false;
    Sound button_click_effect;

    namespace Loader
    {
        using namespace StartMenu;

        static void LoadButtonClickEffect(void)
        {
            string result = assets;
            result += "/sounds/ButtonClick.wav";

            button_click_effect = LoadSound(result.data());
        }

        static Image LoadSettingsButton(void)
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

            return LoadImage(result.data());
        }

        static void LoadBackgroundSound(void)
        {
            string result = assets;
            result += "/sounds/StartMenu.mp3";

            bg_music = LoadSound(result.data());
        }

        static Image LoadBackgound(void)
        {
            string result = assets;
            result += "/backgrounds/StartMenu.png";

            return LoadImage(result.data());
        }

        static Image LoadExtrasButton(void)
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

            return LoadImage(result.data());
        }

        static Image LoadPlayButton(void)
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

            return LoadImage(result.data());
        }

        static Image *LoadBirdSprite(void)
        {
            Image *frames = new Image[3]; // 3 frames

            string result = assets;
            result += "/sprites/bird/";

            string frame1_p = result + "0.png";
            string frame2_p = result + "1.png";
            string frame3_p = result + "2.png";

            frames[0] = LoadImage(frame1_p.data());
            frames[1] = LoadImage(frame2_p.data());
            frames[2] = LoadImage(frame3_p.data());

            return frames;
        }
    }

    void LoadAssets(void)
    {
        using namespace Loader;
        LoadButtonClickEffect();
        LoadBackgroundSound();

        background_image = new Image(LoadBackgound());
        settings_image = new Image(LoadSettingsButton());
        extras_image = new Image(LoadExtrasButton());
        play_image = new Image(LoadPlayButton());

        bird_sprite_images = LoadBirdSprite();

        is_assets_loaded = true;
    }

    void LoadTextures(void)
    {
        using namespace Loader;
        background = LoadTextureFromImage(*background_image);
        settings_button->texture = LoadTextureFromImage(*settings_image);
        extras_button->texture = LoadTextureFromImage(*extras_image);
        play_button->texture = LoadTextureFromImage(*play_image);

        for (int i = 0; i < 3; i++)
        {
            bird_sprite[i] = LoadTextureFromImage(bird_sprite_images[i]);
        }

        delete[] bird_sprite_images;
        delete background_image;
        delete settings_image;
        delete extras_image;
        delete play_image;
    }
}