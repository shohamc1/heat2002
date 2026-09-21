#include "global.h"

struct RegInfo
{
    u32 pad0;
    u16 f4;
    u16 pad6;
    u8 f8;
};

extern struct RegInfo *gUnk_0202F240;
extern struct RegInfo *gUnk_0202F240x;

void sub_08016F80(u32 a, u32 b, u16 c);

u16 sub_08017000(u16 v, u16 *dest)
{
    u16 buf[0x44];
    u16 *p;
    struct RegInfo **pp;
    u8 i, j, k;
    u16 acc;

    if (v >= gUnk_0202F240->f4)
        return 0x80FF;
    pp = &gUnk_0202F240x;
    p = &buf[(*pp)->f8 + 1];
    for (i = 0; i < (*pp)->f8; i++) {
        *p-- = v;
        v >>= 1;
    }
    *p-- = 1;
    *p = 1;
    sub_08016F80((u32)buf, 0x0D000000, ((gUnk_0202F240x->f8 << 16) + 0x30000) >> 16);
    sub_08016F80(0x0D000000, (u32)buf, 0x44);
    p = &buf[4];
    dest += 3;
    j = 0;
    do {
        acc = 0;
        k = 0;
        do {
            acc = (acc * 2) | (*p++ & 1);
            k++;
        } while (k <= 0xF);
        *dest-- = acc;
        j++;
    } while (j <= 3);
    return 0;
}
