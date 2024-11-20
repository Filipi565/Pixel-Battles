#include <stdlib.h>
#include <stdio.h>
#include <pblib.h>

namespace PixelBattle
{
    Button::Button()
    {
        _m_functions = nullptr;
        texture = nullptr;
        visible = false;
        size = {0, 0};
        pos = {0, 0};
        _m_count = 0;

        _Allocate(0);
    }

    Button::~Button()
    {
        UnloadTexture(*texture);
        
        MemFree(_m_functions);
        delete texture;
    }

    void Button::Load(void)
    {
        Rectangle rec;
        rec = {pos.x, pos.y, size.x, size.y};
        bool in_colision = CheckCollisionPointRec(GetMousePosition(), rec);

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && in_colision && visible)
        {
            for (unsigned long int i = 0; i < _m_count; i++)
            {
                function_t func = _m_functions[i];
                func();
            }
        }

        if (visible)
        {
            Rectangle source = {0, 0, (float)texture->width, (float)texture->height};

            DrawTexturePro(*texture, source, rec, {0, 0}, 0, WHITE);
        }
    }

    void Button::OnClick(function_t func)
    {
        _m_count++;
        _Allocate(_m_count);

        _m_functions[_m_count-1] = func;
    }

    void Button::_Allocate(unsigned long int s)
    {
        if (_m_functions == nullptr)
        {
            _m_functions = (function_t *)MemAlloc(s*sizeof(function_t *));
        }
        else
        {
            _m_functions = (function_t *)MemRealloc(_m_functions, s);
        }

        if (_m_functions == nullptr)
        {
            fprintf(stderr, "Error while allocating memory\n");
            std::exit(1);
        }
    }
}