#ifndef _PBLIB_H_
#define _PBLIB_H_

#include <raylib.h>

namespace PixelBattle
{
    extern const char *executable;
    extern bool on_start_menu;

    void DrawStartMenu(void);
    char *GetAssetsPath(void);
    int MemoryCopy(void *, unsigned long int, const void *);
    int PathAbsolute(char *, unsigned long int, const char *);

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

        virtual void Draw(void);

        Vector2 pos;
        Color color;
        unsigned int speed;
        Action action = IDLE;
        unsigned char health = 100;
    };
}

#endif