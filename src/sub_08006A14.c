#include "global.h"

extern u32 gUnk_020253D0[];
extern u32 gUnk_083671C0[];
extern u8 gUnk_02025240;

void sub_08006A14(u32 arg0)
{
    gUnk_020253D0[0] = gUnk_083671C0[arg0];
    gUnk_02025240 = 0x14;
}
