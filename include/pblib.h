#ifndef _PBLIB_H_
#define _PBLIB_H_

#include <raylib.h>

namespace PixelBattle
{
    extern bool on_start_menu;

    void DrawStartMenu(void);

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

        Entity();
        Entity(int x, int y);

        virtual void Draw(void);

        Vector2 pos;
        Color color;
        unsigned int speed;
        Action action = IDLE;
        unsigned char health = 100;
    };
}

#endif