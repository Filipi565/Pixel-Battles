#include <pblib.h>

namespace PixelBattle
{
    TextureObject::TextureObject()
    {
        texture = new Texture2D();
    }

    TextureObject::~TextureObject()
    {
        if (IsTextureValid(*texture))
        {
            UnloadTexture(*texture);
        }

        if (texture != nullptr)
        {
            delete texture;
        }

        texture = nullptr;
    }
}