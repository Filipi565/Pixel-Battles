#include <stdlib.h>
#include <stdio.h>
#include <pblib.h>
#include <string>

using std::string;

namespace PixelBattle
{
    extern Sound button_click_effect;

    Button::Button() : TextureObject()
    {
        visible = false;
        size = {0, 0};
        pos = {0, 0};

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
            PlaySound(button_click_effect);
        }

        Rectangle source = {0, 0, (float)texture.width, (float)texture.height};
        if (visible && IsTextureValid(texture))
        {
            DrawTexturePro(texture, source, rec, {0, 0}, 0, color);
        }
        else if (visible)
        {
            DrawRectangleV(pos, size, color);
        }
    }
}
