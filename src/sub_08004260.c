#include "global.h"

extern u32 gUnk_02002100[];

void sub_08004260(u32 x, u32 y)
{
    gUnk_02002100[0] = x;
    gUnk_02002100[1] = y;
    gUnk_02002100[2] = x;
    gUnk_02002100[3] = y;
    gUnk_02002100[4] = 0;
    gUnk_02002100[5] = 0;
}
