#include "global.h"

extern u32 gUnk_020375D0;
extern u32 gUnk_03007FFC;
extern u32 gUnk_020375E0[];
extern volatile u32 gUnk_040000D4[];

void sub_08339AF0(void);

void sub_08339A40(void)
{
    sub_08339AF0();
    gUnk_020375D0 = 0x0200106D;
    gUnk_040000D4[0] = 0x02000D44;
    gUnk_040000D4[1] = 0x02037620;
    gUnk_040000D4[2] = 0x80000400;
    (void)gUnk_040000D4[2];
    gUnk_03007FFC = 0x02037620;
    *(volatile u16 *)0x04000204 = 0x00004014;
    gUnk_020375E0[1] = 0x02001051;
    gUnk_020375E0[0] = 0x0200106D;
    gUnk_020375E0[2] = 0x0200106D;
    gUnk_020375E0[3] = 0x0200106D;
    gUnk_020375E0[4] = 0x0200106D;
    gUnk_020375E0[5] = 0x0200106D;
    gUnk_020375E0[6] = 0x0200106D;
    gUnk_020375E0[7] = 0x0200106D;
    gUnk_020375E0[8] = 0x0200106D;
    gUnk_020375E0[9] = 0x0200106D;
    gUnk_020375E0[10] = 0x0200106D;
    gUnk_020375E0[11] = 0x0200106D;
    gUnk_020375E0[12] = 0x0200106D;
    gUnk_020375E0[13] = 0x0200106D;
}
