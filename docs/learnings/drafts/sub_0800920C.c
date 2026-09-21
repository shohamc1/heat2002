/*
 * NEAR-MISS (256/256 bytes, 2 instructions differ): everything matches
 * except the stack frame: target reserves 44 bytes (11 reload slots) and
 * spills the A-branch index to [sp,#0x28]; we reserve 4 bytes and spill to
 * [sp,#0].  Tried: u16 v / u32 off / t7 / hi-lo pointer locals, a u16* base
 * variable, do{}while(0) wrappers, and a 98k-iteration permuter run; the
 * instruction stream is byte-identical in every variant, only alter_reg's
 * slot count differs (the retail source must create ~10 more pseudos that
 * end up unallocated).  Residual: sub sp,#0x2C + str [sp,#0x28].
 */

#include "global.h"

extern u32 gUnk_08364B08[];
extern u16 gUnk_08334DCC[];
extern u16 gUnk_08335A8C[];

void sub_0800920C(u8 arg)
{
    u16 *dest;
    u8 row;
    u8 ctr;

    dest = (u16 *)(gUnk_08364B08[0] + 0x290);
    *dest = (0xE0 << 8) | gUnk_08335A8C[gUnk_08334DCC[0x398]];
    dest = (u16 *)(gUnk_08364B08[0] + 0x292);
    row = 0;
    ctr = 0;
    do {
        if (arg > (u8)(row + 7)) {
            *dest = (0xE0 << 8) | gUnk_08335A8C[gUnk_08334DCC[0x3A1]];
            dest++;
        }
        if (arg < row) {
            *dest = (0xE0 << 8) | gUnk_08335A8C[gUnk_08334DCC[0x399]];
            dest++;
        } else if (arg <= (u8)(row + 7)) {
            *dest = (0xE0 << 8) | gUnk_08335A8C[gUnk_08334DCC[0x39A + (u8)(arg - row)]];
            dest++;
        }
        row += 8;
        ctr++;
    } while (ctr != 0x0C);
    *dest = (0xE0 << 8) | gUnk_08335A8C[gUnk_08334DCC[0x3A2]];
}
