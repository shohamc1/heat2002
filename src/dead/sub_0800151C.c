#include "global.h"

/* SoundGetJumpList: the MP2000-era BIOS call the sound driver uses to copy
 * the 32-byte jump table to the area passed in r0. Not in pokeemerald's
 * newer SDK; agbcc emits no swi from C, so it is inline asm in a normal
 * leaf function and the compiler adds the bx lr. */

void sub_0800151C(u32 *jumpTable)
{
    asm("swi 0x2A");
}
