#include "global.h"

/* High-module copy of sub_0800151C (SoundGetJumpList, svc 0x2A). */

void sub_0833ABDC(u32 *jumpTable)
{
    asm("swi 0x2A");
}
