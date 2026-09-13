/* sub_0800CB18 -- quarantined draft. Instruction stream and branch layout match the ROM
   except two coupled register/block-order diffs (see parked notes style):
   1) the x loop-local: ROM keeps it in r2, every C shape tried allocates r3
      (single local, double local, u32, temp reassignments -- all r3).
   2) tail: ROM loads the table address FIRST into r0 and builds the index
      in r1 (adds r1,#0x80; lsls r1,#8; adds r1,#0x80; adds r1,r2,r1;
      adds r1,r1,r0; ldrb r0,[r1]); reachable shapes load the table last
      or into r2 with index in r0.
   Loop body/conditions match byte-for-byte otherwise. */
#include "global.h"

extern u8 gUnk_0806C97C[];

u8 sub_0800CB18(s32 x, s32 y)
{
    s32 a;

    a = x;
    for (;;)
    {
        if ((u32)(a + 0x7F) > 0xFE)
        {
            a = (a + (a >> 31)) >> 1;
            y = (y + (y >> 31)) >> 1;
            continue;
        }
        if (y < -0x7F)
        {
            a = (a + (a >> 31)) >> 1;
            y = (y + (y >> 31)) >> 1;
            continue;
        }
        if (y > 0x7F)
        {
            a = (a + (a >> 31)) >> 1;
            y = (y + (y >> 31)) >> 1;
            continue;
        }
        break;
    }
    if (y < -0x7F)
        goto zero;
    if (y > 0x7F)
        goto zero;
    return gUnk_0806C97C[((y + 0x80) << 8) + 0x80 + a];
zero:
    return 0;
}
