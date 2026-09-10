#include "global.h"

struct Unk0202A550
{
    u8 filler0[0x16C];
    u32 unk16C;
    u8 filler170[400 - 0x170];
};

extern struct Unk0202A550 gUnk_0202A550[];
extern struct Unk0202A550 *gUnk_0202EFC0[];

void sub_0800F3C0(void)
{
    u8 i;
    struct Unk0202A550 **p;
    struct Unk0202A550 *a;
    struct Unk0202A550 *b;
    u32 ka;
    u32 kb;
    u32 swapped;

    i = 0;
    do
    {
        gUnk_0202EFC0[i] = &gUnk_0202A550[i];
        i++;
    } while (i != 0x18);
    do
    {
        swapped = 0;
        p = gUnk_0202EFC0;
        i = 0;
        do
        {
            a = p[0];
            b = p[1];
            ka = a->unk16C;
            kb = b->unk16C;
            if (ka > kb)
            {
                p[0] = b;
                p[1] = a;
                swapped = 1;
            }
            p++;
            i++;
        } while (i != 0x17);
    } while (swapped != 0);
}
