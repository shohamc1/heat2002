#include "global.h"
#include "functions.h"

extern volatile u16 gKeysPressed; /* 0x020005CC */


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
