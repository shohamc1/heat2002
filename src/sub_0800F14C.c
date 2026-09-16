#include "global.h"

extern u8 gUnk_0202EF20[];

void sub_0800F14C(u8 param)
{
    u8 v;
    register u8 w asm("r3");

    v = param;
    w = v;
    if (v == 0) {
        gUnk_0202EF20[0] = 1;
        gUnk_0202EF20[1] = 1;
        gUnk_0202EF20[2] = 1;
        gUnk_0202EF20[3] = 1;
        gUnk_0202EF20[4] = 1;
        gUnk_0202EF20[5] = 1;
        gUnk_0202EF20[6] = 1;
    }
    if (v == 1) {
        gUnk_0202EF20[7] = v;
        gUnk_0202EF20[8] = v;
        gUnk_0202EF20[9] = v;
        gUnk_0202EF20[10] = v;
        gUnk_0202EF20[11] = v;
    }
    if (w == 2) {
        gUnk_0202EF20[12] = 1;
        gUnk_0202EF20[13] = 1;
        gUnk_0202EF20[14] = 1;
        gUnk_0202EF20[15] = 1;
        gUnk_0202EF20[16] = 1;
    }
}
