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
#include "variables.h"


void sub_08341180(u8 arg)
{
    u8 pad[0x28];
    u16 *dest;
    u8 row;
    u8 ctr;
    u8 lim;
    u32 off;

    dest = (u16 *)(gUnk_020251B8[0] + 0x290);
    off = 0x730;
    *dest = (0xE0 << 8) | gUnk_02022254[*(u16 *)((u8 *)gUnk_02021594 + off)];
    dest = (u16 *)(gUnk_020251B8[0] + 0x292);
    row = 0;
    ctr = 0;
    do {
        lim = row + 7;
        if (arg > lim) {
            off = 0x742;
            *dest = (0xE0 << 8) | gUnk_02022254[*(u16 *)((u8 *)gUnk_02021594 + off)];
            dest++;
        }
        if (arg < row) {
            off = 0x732;
            *dest = (0xE0 << 8) | gUnk_02022254[*(u16 *)((u8 *)gUnk_02021594 + off)];
            dest++;
        } else if (arg <= lim) {
            off = 0x734 + 2 * (u8)(arg - row);
            *dest = (0xE0 << 8) | gUnk_02022254[*(u16 *)((u8 *)gUnk_02021594 + off)];
            dest++;
        }
        row += 8;
        ctr++;
    } while (ctr != 0x0C);
    off = 0x744;
    *dest = (0xE0 << 8) | gUnk_02022254[*(u16 *)((u8 *)gUnk_02021594 + off)];
}
