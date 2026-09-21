#include "global.h"

struct UnkF240
{
    u8 filler0[4];
    u16 unk4;
    u8 filler6[8 - 6];
    u8 unk8;
};

#define Q ((struct UnkF240 *)*(volatile u32 *)0x0202F240)
extern u8 gUnk_02000498;
extern u8 gUnk_08339404[];

void sub_08016F80(u32 a, u32 b, u16 c);
void sub_08016ED8(u32 a);
void sub_08016F3C(void);

u16 sub_080170B8(u16 v, u16 *src)
{
    u16 buf[0x52];
    u16 *p;
    u8 i, j, k;
    u16 *s;
    u16 w;
    struct UnkF240 * volatile *pp;

    if (v >= Q->unk4)
        return 0x80FF;
    s = src;
    p = buf + Q->unk8;
    p += 0x42;
    *p-- = 0;
    j = 0;
    do {
        w = *s++;
        i = 0;
        do {
            *p-- = w;
            w >>= 1;
            i++;
        } while (i <= 0xF);
        j++;
    } while (j <= 3);
    pp = (struct UnkF240 * volatile *)0x0202F240;
    for (k = 0; k < (*pp)->unk8; k++) {
        *p-- = v;
        v >>= 1;
    }
    *p-- = 0;
    *p = 1;
    sub_08016F80((u32)buf, 0x0D000000, (((u32)Q->unk8 << 16) + 0x430000) >> 16);
    sub_08016ED8((u32)gUnk_08339404);
    v = 0;
    for (;;) {
        if ((*(volatile u16 *)0x0D000000 & 1) != 0)
            break;
        if (gUnk_02000498 != 0) {
            if ((*(volatile u16 *)0x0D000000 & 1) == 0)
                v = 0xC001;
            break;
        }
    }
    sub_08016F3C();
    return v;
}
