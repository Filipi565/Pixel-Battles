#include <pblib.h>

namespace PixelBattle
{
    Entity::Entity()
    {
        pos = {0, 0};
        color = {0, 0, 0, 0};
        speed = 0;
    }

    void Entity::Draw(void)
    {
        Vector2 size = {GetScreenHeight()/20.0f, GetScreenWidth()/20.0f};
        DrawRectangleV(pos, size, color);
    }
}