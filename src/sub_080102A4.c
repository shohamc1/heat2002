#include "global.h"

extern void WaitForVBlank(void);

void WaitFrames(s32 n)
{
    s32 i;

    if (n > 0) {
        for (i = n; i != 0; i--)
            WaitForVBlank();
    }
}
