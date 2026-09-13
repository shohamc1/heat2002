#include "global.h"

extern u8 gUnk_02002218;

void sub_08016E0C(u32 src, u32 dest, u32 mode);

void sub_08003D3C(u8 *a, u8 *b)
{
    s32 i;

    if (gUnk_02002218 != 0)
        a += 4;
    for (i = 0; i != 0x18; i++) {
        sub_08016E0C(a, b, 0x10);
        a += 0x48;
        b += 0x40;
    }
}
