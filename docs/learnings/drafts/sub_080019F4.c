#include "global.h"

void sub_08000DC8(u32, u32);

void sub_080019F4(u32 r0)
{
    u32 r6 = r0;
    s32 r1;
    s32 temp1;
    s32 raw;
    s16 temp2;
    s32 r5;
    u32 r4;
    u8 r7;
    u8 mask;
    u8 code;
    u8 flags;

    r1 = *(u16 *)(r6 + 0x24);
    if (r1 == 0)
        return;

    temp1 = *(u16 *)(r6 + 0x26) - 1;
    *(u16 *)(r6 + 0x26) = temp1;
    if ((s16)temp1 != 0)
        return;

    raw = *(u16 *)(r6 + 0x28) - 0x10;
    *(u16 *)(r6 + 0x28) = raw;
    temp2 = raw;
    if (temp2 > 0)
    {
        *(u16 *)(r6 + 0x26) = r1;
        r5 = *(u8 *)(r6 + 0x08);
        r4 = *(u32 *)(r6 + 0x2C);
        if (r5 > 0)
        {
            mask = 0x80;
            code = 3;
            do
            {
                flags = *(u8 *)(r4 + 0x00);
                if ((mask & flags) != 0)
                {
                    r7 = *(u16 *)(r6 + 0x28) >> 2;
                    *(u8 *)(r4 + 0x13) = r7;
                    *(u8 *)(r4 + 0x00) = flags | code;
                }
                r5--;
                r4 += 0x50;
            } while (r5 > 0);
        }
    }
    else
    {
        r5 = *(u8 *)(r6 + 0x08);
        r4 = *(u32 *)(r6 + 0x2C);
        if (r5 > 0)
        {
            r7 = 0;
            do
            {
                sub_08000DC8(r6, r4);
                *(u8 *)(r4 + 0x00) = r7;
                r5--;
                r4 += 0x50;
            } while (r5 > 0);
        }
    }
}
