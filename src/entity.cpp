#include <pblib.h>

namespace PixelBattle
{
    Entity::Entity()
    {
        pos = {0, 0};
    }

    Entity::Entity(int x, int y)
    {
        pos = {(float)x, (float)y};
    }

    void Entity::Draw(void)
    {
        Vector2 size = {GetScreenHeight()/20.0f, GetScreenWidth()/20.0f};
        DrawRectangleV(pos, size, color);
    }
}