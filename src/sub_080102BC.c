#include "global.h"

extern volatile u16 gKeysPressed; /* 0x020005CC */

void WaitForVBlank(void);
void ReadKeys(void);

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
