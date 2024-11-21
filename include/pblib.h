#ifndef _PBLIB_H_
#define _PBLIB_H_

#include <raylib.h>

namespace PixelBattle
{
    
    extern const char *executable;
    extern bool on_start_menu;

    char *GetAssetsPath(void);
    void LoadStartMenu(const char *);
    int MemoryCopy(void *, unsigned long int, const void *);

    struct Object
    {
        Vector2 size;
        Vector2 pos;
        Color color;
    };

    class TextureObject: public Object
    {
        public:
        TextureObject() {texture = new Texture2D();}

        virtual ~TextureObject()
        {
            if (texture != nullptr)
            {
                UnloadTexture(*texture);
                delete texture;
            }

            texture = nullptr;
        }

        Texture2D *texture;
    };

    class Entity: public Object
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

        virtual void Load(void);

        unsigned int speed;
        Action action = IDLE;
        unsigned char health = 100;
    };

    class Button: public TextureObject
    {
        public:
        Button();
        virtual void Load(void);

        void (*OnClick)(void);
        bool visible;

        protected:
        static void _M_NoPointer(void) {}
    };
    
    namespace StartMenu
    {
        extern Button *settings_button;
        extern Texture2D *background;
        extern Button *extras_button;
        extern Button *play_button;
        extern Sound *sound;
    }
}

#endif