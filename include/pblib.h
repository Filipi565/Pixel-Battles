#ifndef _PBLIB_H_
#define _PBLIB_H_

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
        enum State
        {
            IDLE = 0x0,
            WALKING = 0x1,
            JUMPING = 0x2,
            DYING = 0x4,
            HURT = 0x8,
            DEAD = 0x16,
            ATACK = 0x32
        };

        PB_API Entity();
        PB_API Entity(float x, float y);

        Vector2 pos;
        State state;
    };
}

#endif