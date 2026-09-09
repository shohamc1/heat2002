#include "global.h"

extern u32 gUnk_03007FF0[];
extern u8 gCallback_08000B69[];   /* Thumb entry: function address | 1 */

void sub_08001534(u32 r0);

void sub_08001888(u32 r0, u32 r1, u32 r2)
{
    u32 r7 = r0;
    u32 r6 = r1;
    u8 r4 = (u8)r2;
    u32 r5;

    if (r4 == 0)
        return;
    if (r4 > 0x10)
        r4 = 0x10;
    r5 = gUnk_03007FF0[0];
    if (*(u32 *)r5 != 0x68736D53)
        return;
    *(u32 *)r5 = *(u32 *)r5 + 1;
    sub_08001534(r7);
    *(u32 *)(r7 + 0x2C) = r6;
    *(u8 *)(r7 + 8) = r4;
    *(u32 *)(r7 + 4) = 0x80 << 0x18;
    while (r4 != 0)
    {
        *(u8 *)r6 = 0;
        r4--;
        r6 += 0x50;
    }
    if (*(u32 *)(r5 + 0x20) != 0)
    {
        *(u32 *)(r7 + 0x38) = *(u32 *)(r5 + 0x20);
        *(u32 *)(r7 + 0x3C) = *(u32 *)(r5 + 0x24);
        *(u32 *)(r5 + 0x20) = 0;
    }
    *(u32 *)(r5 + 0x24) = r7;
    *(u32 *)(r5 + 0x20) = (u32)gCallback_08000B69;
    *(u32 *)r5 = 0x68736D53;
    *(u32 *)(r7 + 0x34) = 0x68736D53;
}
