#ifndef _PBLIB_H_
#define _PBLIB_H_

#include <raylib.h>

namespace PixelBattle
{
    extern const char *executable;
    extern const char *assets;
    extern bool on_start_menu;

    void LoadAssets(void);
    void HideConsole(void);
    void UnloadAssets(void);
    void LoadStartMenu(void);
    char *GetAssetsPath(void);
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
        TextureObject();

        virtual ~TextureObject();

        Texture2D *texture;
    };

    class Entity: public Object
    {
        public:
        enum class Action
        {
            IDLE = 0x0,
            WALK = 0x1,
            JUMP = 0x2,
            DIE = 0x4,
            HURT = 0x8,
            ATACK = 0x16
        };

        Entity();

        virtual void Update(void);

        unsigned int speed;
        unsigned char health = 100;
        Action action = Action::IDLE;

        unsigned long int current_frame;
        unsigned long int frames_count;
        Texture2D *frames;

        private:
        Vector2 size;
    };

    class Button: public TextureObject
    {
        public:
        Button();
        virtual void Update(void);

        void (*OnClick)(void);
        bool visible;

        protected:
        static void _M_NoPointer(void) {}
    };
    
    namespace StartMenu
    {
        extern Button *settings_button;
        extern Button *extras_button;
        extern Texture2D background;
        extern Button *play_button;
        extern Sound sound;
    }
}

#endif