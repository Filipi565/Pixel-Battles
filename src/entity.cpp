#include "pbconfig.h"
#include <pblib.h>

namespace PixelBattle
{
    PB_API void DrawStartMenu(void)
    {
        
    }

    PB_API Entity::Entity()
    {
        pos = {0, 0};
    }

    PB_API Entity::Entity(float x, float y)
    {
        pos = {x, y};
    }
}