#include <pblib.h>

namespace PixelBattle
{
    Button::Button()
    {
        texture = {0, 0, 0, 0, 0};
        _m_functions = nullptr;
        visible = false;
        size = {0, 0};
        pos = {0, 0};
        _m_count = 0;

        _Allocate(0);
    }

    void Button::Load(void)
    {
        Rectangle rec;
        rec = {pos.x, pos.y, size.x, size.y};
        bool in_colision = CheckCollisionPointRec(GetMousePosition(), rec);

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && in_colision)
        {
            for (unsigned long int i = 0; i < _m_count; i++)
            {
                function_t func = _m_functions[i];
                func();
            }
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
    }
}