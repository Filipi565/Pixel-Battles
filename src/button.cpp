#include <stdlib.h>
#include <stdio.h>
#include <pblib.h>

namespace PixelBattle
{
    Button::Button() : TextureObject()
    {
        visible = false;
        size = {0, 0};
        pos = {0, 0};

        OnClick = &_M_NoPointer;
    }

    void Button::Load(void)
    {
        Rectangle rec;
        rec = {pos.x, pos.y, size.x, size.y};
        bool in_colision = CheckCollisionPointRec(GetMousePosition(), rec);

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && in_colision && visible)
        {
            this->OnClick();
        }

        if (visible)
        {
            Rectangle source = {0, 0, (float)texture->width, (float)texture->height};

            DrawTexturePro(*texture, source, rec, {0, 0}, 0, WHITE);
        }
    }
}
