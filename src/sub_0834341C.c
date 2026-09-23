#include "global.h"

extern u32 gUnk_020390AC; /* 0x0200209C */

u8 sub_08343464(s32 x, s32 y);

u8 sub_0834341C(u8 *a1, s32 a2, s32 a3)
{
    if (gUnk_020390AC == *(u32 *)(a1 + 0x138))
        return *(u8 *)(a1 + 0x134);
    *(u32 *)(a1 + 0x134) = sub_08343464(a2, a3);
    *(u32 *)(a1 + 0x138) = gUnk_020390AC;
    return *(u8 *)(a1 + 0x134);
}
