#include "global.h"

/* High-module copy of the SoundGetJumpList stub, svc 0x2A -- see
 * sub_0800151C. */

void sub_0833ABDC(u32 *jumpTable)
{
    asm("swi 0x2A");
}
