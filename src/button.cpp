#include <stdlib.h>
#include <stdio.h>
#include <pblib.h>
#include <string>

using std::string;

namespace PixelBattle
{
    Sound *button_click_effect = nullptr;

    Button::Button() : TextureObject()
    {
        visible = false;
        size = {0, 0};
        pos = {0, 0};

        // Commit f5b71c9b: Add a button click sound effect to the game
        if (button_click_effect == nullptr)
        {
            string result = assets;
            result += "/sounds/ButtonClick.wav";

            button_click_effect = new Sound();
            (*button_click_effect) = LoadSound(result.data());
        }

        OnClick = &_M_NoPointer;
    }

    void Button::Update(void)
    {
        Rectangle rec;
        rec = {pos.x, pos.y, size.x, size.y};
        bool in_colision = CheckCollisionPointRec(GetMousePosition(), rec);

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && in_colision && visible)
        {
            this->OnClick();
            PlaySound(*button_click_effect);
        }

        Rectangle source = {0, 0, (float)texture->width, (float)texture->height};
        if (visible && texture != nullptr)
        {
            DrawTexturePro(*texture, source, rec, {0, 0}, 0, color);
        }
        else if (visible)
        {
            DrawRectangleV(pos, size, color);
        }
    }
}
