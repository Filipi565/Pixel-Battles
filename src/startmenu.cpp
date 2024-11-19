#include <pblib.h>
#include <cwalk.h>
#include <string>

using std::string;

namespace PixelBattle
{
    static Texture2D *__background = nullptr;
    void LoadStartMenu(const char *assets)
    {
        if (__background == nullptr)
        {
            string result = assets;
            result += "/backgrounds/StartMenu.png";

            Image image = LoadImage(result.data());

            __background = new Texture2D();
            (*__background) = LoadTextureFromImage(image);

            UnloadImage(image);
        }

        Rectangle source, dest;

        source = {0.0f, 0.0f, (float)__background->width, (float)__background->height};
        dest = {0.0f, 0.0f, (float)GetScreenWidth(), (float)GetScreenHeight()};

        DrawTexturePro(*__background, source, dest, {0, 0}, 0, WHITE);
    }
}