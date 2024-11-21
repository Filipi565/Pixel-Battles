#include <pblib.h>

namespace PixelBattle
{
    Entity::Entity()
    {
        pos = {0, 0};
        color = {0, 0, 0, 0};
        speed = 0;
        size = {GetScreenHeight()/20.0f, GetScreenWidth()/20.0f};
    }

    void Entity::Update(void)
    {
        DrawRectangleV(pos, size, color);
    }
}