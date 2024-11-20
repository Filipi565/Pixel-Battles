#include <cwalk.h>
#include <pblib.h>

namespace PixelBattle
{
    char *GetAssetsPath()
    {
        const char *paths[] = {
            executable,
            "..",
            "Assets",
            nullptr
        };

        char temp[4096];

        auto size = cwk_path_join_multiple(paths, temp, 4096);

        char *result = new char[size+1];
        TextCopy(result, temp);

        return result;
    }
}