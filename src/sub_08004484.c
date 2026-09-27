#include "global.h"
#include "variables.h"


void ResetSpriteQueues(void);

void ClearOamBuffer(void)
{
    u32 r1;
    u32 r2;
    u32 *r0;

    r1 = 0;
    r2 = 0xAA;
    r0 = (u32 *)gUnk_02024830;
    while (r1 != 0x80)
    {
        *r0 = r2;
        r0 += 2;
        r1++;
    }
    ResetSpriteQueues();
}
