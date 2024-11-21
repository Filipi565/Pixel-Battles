#include <pblib.h>

namespace PixelBattle
{
    TextureObject::TextureObject()
    {
        texture = new Texture2D();
    }

    TextureObject::~TextureObject()
    {
        if (texture == nullptr)
        {
            return;
        }

        if (IsTextureValid(*texture))
        {
            UnloadTexture(*texture);
        }
        delete texture;

        texture = nullptr;
    }
}