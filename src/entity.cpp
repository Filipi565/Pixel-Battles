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
        Vector2 size = {20, 40};
        DrawRectangleV(pos, size, color);
    }
}