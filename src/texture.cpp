#include <pblib.h>

namespace PixelBattle
{
    TextureObject::~TextureObject()
    {
        if (IsTextureValid(texture))
        {
            UnloadTexture(texture);
        }
    }
}