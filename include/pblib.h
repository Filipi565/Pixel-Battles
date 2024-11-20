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

        virtual void Load(void);

        Vector2 pos;
        Color color;
        unsigned int speed;
        Action action = IDLE;
        unsigned char health = 100;
    };

    class Button
    {
        public:
        typedef void (*function_t)(void);

        Button();
        virtual ~Button();
        virtual void Load(void);
        virtual void OnClick(function_t);
        virtual Button Clone(bool copy_funcs = false);

        Texture2D *texture;
        Vector2 size;
        bool visible;
        Color color;
        Vector2 pos;

        protected:
        unsigned long int _m_count;
        function_t *_m_functions;

        private:
        void _Allocate(unsigned long int);
    };
    
    namespace StartMenu
    {
        extern Texture2D *background;
        extern Button *play_button;
        extern Sound *sound;
    }
}

#endif