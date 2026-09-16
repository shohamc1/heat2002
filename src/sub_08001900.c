#include "global.h"

void sub_08000DC8(u32, u32);
void sub_080016E4(u32);

void sub_08001900(u32 r0, u32 r1)
{
    register u32 r4 asm("r4");
    u32 r5 = r0;
    u32 r7 = r1;
    s32 r6;
    u32 r8;
    u16 v;
    u32 t;
    register u32 u asm("r0");

    if (*(u32 *)(r5 + 0x34) != 0x68736D53)
        return;
    *(u32 *)(r5 + 0x34) = *(u32 *)(r5 + 0x34) + 1;
    *(u32 *)(r5 + 0x04) = 0;
    *(u32 *)(r5 + 0x00) = r7;
    *(u32 *)(r5 + 0x30) = *(u32 *)(r7 + 0x04);
    *(u8 *)(r5 + 0x09) = *(u8 *)(r7 + 0x02);
    *(u32 *)(r5 + 0x0C) = 0;
    v = 0x96;
    *(u16 *)(r5 + 0x1C) = v;
    *(u16 *)(r5 + 0x20) = v;
    v = v + 0x6A;
    *(u16 *)(r5 + 0x1E) = v;
    *(u16 *)(r5 + 0x22) = 0;
    *(u16 *)(r5 + 0x24) = 0;
    r6 = 0;
    r4 = *(u32 *)(r5 + 0x2C);
    if (r6 < *(u8 *)(r7 + 0x00) && r6 < *(u8 *)(r5 + 0x08)) {
        r8 = r6;
loopA:
        sub_08000DC8(r5, r4);
        *(u8 *)(r4 + 0x00) = 0xC0;
        *(u32 *)(r4 + 0x20) = r8;
        t = r6 * 4;
        u = r7;
        u = u + 8;
        u = u + t;
        *(u32 *)(r4 + 0x40) = *(u32 *)u;
        r6++;
        r4 += 0x50;
        if (r6 < *(u8 *)(r7 + 0x00) && r6 < *(u8 *)(r5 + 0x08))
            goto loopA;
    }
    if (r6 < *(u8 *)(r5 + 0x08)) {
        r8 = 0;
loopB:
        sub_08000DC8(r5, r4);
        *(u8 *)(r4 + 0x00) = r8;
        r6++;
        r4 += 0x50;
        if (r6 < *(u8 *)(r5 + 0x08))
            goto loopB;
    }
    if (*(u8 *)(r7 + 0x03) & 0x80)
        sub_080016E4(*(u8 *)(r7 + 0x03));
    *(u32 *)(r5 + 0x34) = 0x68736D53;
}
