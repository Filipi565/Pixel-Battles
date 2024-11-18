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

    extern bool on_start_menu;

    PB_API void DrawStartMenu(void);

    class Entity
    {
        public:
        enum Action
        {
            IDLE = 0x0,
            WALK = 0x1,
            JUMP = 0x2,
            DIE = 0x4,
            HURT = 0x8,
            ATACK = 0x16
        };

        PB_API Entity();
        PB_API Entity(int x, int y);

        PB_API void Draw(void);

        Vector2 pos;
        Vector2 size;
        Color color;
        Action action = IDLE;
    };
}

#endif