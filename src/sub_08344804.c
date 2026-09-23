#include "global.h"

struct Unk0202A550
{
    u8 filler0[0x16C];
    u32 unk16C;
    u8 filler170[400 - 0x170];
};

extern struct Unk0202A550 gUnk_0203D520[];
extern struct Unk0202A550 *gUnk_02039200[];

void sub_08344804(void)
{
    u8 i;
    struct Unk0202A550 **p;
    struct Unk0202A550 *a;
    struct Unk0202A550 *b;
    u32 swapped;

    i = 0;
    do
    {
        gUnk_02039200[i] = &gUnk_0203D520[i];
        i++;
    } while (i != 0x5);
    /* A goto keeps the field-offset setup inside each sort pass. */
outer:
    {
        swapped = 0;
        p = gUnk_02039200;
        i = 0;
        do
        {
            a = p[0];
            b = p[1];
            if (a->unk16C > b->unk16C)
            {
                p[0] = b;
                p[1] = a;
                swapped = 1;
            }
            p++;
            i++;
        } while (i != 0x4);
    }
    if (swapped != 0) goto outer;
}
