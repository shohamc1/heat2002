#include "global.h"
#include "functions.h"
#include "variables.h"

void WaitFrames(s32 n)
{
    s32 i;

    if (n > 0) {
        for (i = n; i != 0; i--)
            WaitForVBlank();
    }
}

void WaitFramesOrKey(s32 count)
{
    s32 i;

    for (i = 0; i < count; i++)
    {
        WaitForVBlank();
        ReadKeys();
        if (gKeysPressed & 0x3FF)
            return;
    }
}
