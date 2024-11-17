#ifndef _LIB_H_
#define _LIB_H_

#include <raylib.h>

#ifdef PB_LIB_EXPORT
#define PB_API __declspec(dllexport)
#else
#define PB_API __declspec(dllimport)
#endif

namespace PixelBattle
{
    extern const int WinHeight;
    extern const int WinWidth;

    class Entity
    {
        public:
        PB_API Entity();
        PB_API Entity(float x, float y);

        Vector2 pos;
    };
}

#endif