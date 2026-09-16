#include "global.h"

void sub_08000DC8(u32, u32);

void sub_080019B4(u32 r0)
{
    u32 r6 = r0;
    s32 r4;
    u32 r5;

    if (*(u32 *)(r6 + 0x34) != 0x68736D53)
        return;
    *(u32 *)(r6 + 0x34) = *(u32 *)(r6 + 0x34) + 1;
    *(u32 *)(r6 + 0x04) = *(u32 *)(r6 + 0x04) | (u32)0x80 << 0x18;
    r4 = *(u8 *)(r6 + 0x08);
    r5 = *(u32 *)(r6 + 0x2C);
    while (r4 > 0)
    {
        sub_08000DC8(r6, r5);
        r4--;
        r5 += 0x50;
    }
    *(u32 *)(r6 + 0x34) = 0x68736D53;
}
