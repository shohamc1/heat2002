#include "global.h"

void sub_08000DC8(u32, u32);

void sub_080019F4(u32 a0)
{
    u32 m;
    u32 self = a0;
    u32 count;
    s32 t;
    s32 raw;
    s16 v;
    s32 r5;
    u32 r4;
    u8 zero;
    u8 v2;
    u8 mask;
    u8 code;
    u8 flags;

    count = *(u16 *)(self + 0x24);
    if (count == 0)
        return;
    t = *(u16 *)(self + 0x26) - 1;
    *(u16 *)(self + 0x26) = t;
    m = 0xFFFF;
    if ((t & m) != 0)
        return;
    raw = *(u16 *)(self + 0x28) - 0x10;
    *(u16 *)(self + 0x28) = raw;
    raw &= m;
    v = raw;
    if (v <= 0)
    {
        r5 = *(u8 *)(self + 0x08);
        r4 = *(u32 *)(self + 0x2C);
        if (r5 > 0)
        {
            zero = 0;
            do
            {
                sub_08000DC8(self, r4);
                *(u8 *)(r4 + 0x00) = zero;
                r5--;
                r4 += 0x50;
            } while (r5 > 0);
        }
    }
    else
    {
        *(u16 *)(self + 0x26) = count;
        r5 = *(u8 *)(self + 0x08);
        r4 = *(u32 *)(self + 0x2C);
        if (r5 > 0)
        {
            mask = 0x80;
            code = 3;
            do
            {
                flags = *(u8 *)(r4 + 0x00);
                v2 = 0;
                if (mask & flags)
                {
                    v2 = *(u16 *)(self + 0x28) >> 2;
                    *(u8 *)(r4 + 0x13) = v2;
                    *(u8 *)(r4 + 0x00) = flags | code;
                }
                r5--;
                r4 += 0x50;
            } while (r5 > 0);
        }
    }
}
