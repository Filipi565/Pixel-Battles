#include <cwalk.h>
#include <pblib.h>

#if defined(_WIN32)
#define SEP '\\'
#else
#define SEP '/'
#endif

#define IS_SEP(o) ((o) == '/' || (o) == SEP)

namespace PixelBattle
{
    int PathAbsolute(char *buff, unsigned long int buffsize, const char *path)
    {
        const char *base = nullptr;

        // True if the path starts with "./" or "../"
        bool need_cwd = (
            path[0] == '.' && (IS_SEP(path[1]) ||
            path[1] == '.' && IS_SEP(path[2]))
        );

        if (need_cwd)
        {
            base = GetWorkingDirectory();
        }

        cwk_path_get_absolute(base, path, buff, buffsize);
        return 0;
    }
}