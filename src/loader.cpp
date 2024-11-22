#include <pblib.h>
#include <string>

using std::string;

namespace PixelBattle
{
    namespace StartMenu
    {
        Button *settings_button = nullptr;
    }

    namespace Loader
    {
        using namespace StartMenu;

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
    }

    void LoadAssets(void)
    {
        using namespace Loader;
        LoadSettingsButton();
    }
}