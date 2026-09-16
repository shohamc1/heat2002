/* sub_0800C0FC -- quarantined draft. Remaining diff vs ROM (84/88 bytes):
   1) ROM materializes i=((-(a[0x96>>1]>>11))&0x1F)<<3 ONCE and scales at use:
      sin: lsls r5,r4,#1; adds r5,r5,r6 -- cos: adds r4,#0x40; lsls r4,#1; adds r4,r4,r6.
      Every reachable shape reassociates to ang<<4 + const (<<4/+0x80 or /+0x40), losing
      the single-scale-at-use form. Tried: u16/s16 table externs, pointer locals,
      element-index vs byte-offset, 4..6 locals, ROM-order -(x>>11).
   2) registers: ROM holds the sin table address via r6+mov r8, ours folds to a single
      register with different assignment. muls/epilogue/order all match. */
#include "global.h"

extern s16 gUnk_0801CD08[];

void sub_0800C0FC(s32 *a, s32 b, s32 c, s32 *d)
{
    s16 *t;
    s32 i;
    s32 dx;
    s32 dy;
    s32 relx;
    s32 rely;

    t = gUnk_0801CD08;
    i = ((-(a[0x96 >> 1] >> 11)) & 0x1F) << 3;
    dx = t[i];
    dy = t[i + 0x40];
    relx = (b - a[0]) >> 16;
    rely = (c - a[2]) >> 16;
    d[0] = (relx * dy - dx * rely) >> 8;
    d[1] = (dx * relx + rely * dy) >> 8;
}
