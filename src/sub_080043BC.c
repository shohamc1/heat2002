#include "global.h"

extern u32 gUnk_02002100[];
extern u8 gUnk_020020E0;

void sub_080043BC(void)
{
    s32 x = gUnk_02002100[2] - gUnk_02002100[0];
    s32 y = gUnk_02002100[3] - gUnk_02002100[1];

    if (gUnk_020020E0 != 0) {
        gUnk_02002100[0] += x;
        gUnk_02002100[1] += y;
    } else {
        gUnk_02002100[0] += x >> 4;
        gUnk_02002100[1] += y >> 4;
    }
}
