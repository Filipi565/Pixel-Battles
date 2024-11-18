#include <pblib.h>

namespace PixelBattle
{
    int MemoryCopy(void *__dst, unsigned long int size, const void *__src)
    {
        const char *source = reinterpret_cast<const char *>(__src);
        char *dest = reinterpret_cast<char *>(__dst);

        for (unsigned long int i = 0; i < size; i++)
        {
            dest[i] = source[i];
        }

        return 0;
    }
}