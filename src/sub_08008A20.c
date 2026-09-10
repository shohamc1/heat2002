#include "global.h"

struct Unk0202A550
{
    u8 filler0[0x162];
    u8 unk162;
    u8 filler163[400 - 0x163];
};

extern struct Unk0202A550 gUnk_0202A550[];

extern u8 sub_080025FC(void);

void sub_08008A20(void)
{
    u32 i;
    u8 v;
    u8 dup;
    u8 j;

    for (i = 1; i != 0x18; i++)
        gUnk_0202A550[i].unk162 = 99;
    i = 1;
    for (;;)
    {
        v = 0x1F & sub_080025FC();
        if (v > 0x1D)
            continue;
        dup = 0;
        j = 0;
        do
        {
            if (v == gUnk_0202A550[j].unk162)
                dup = 1;
            j++;
        } while (j != 0x18);
        if (dup != 0)
            continue;
        gUnk_0202A550[i].unk162 = v;
        i++;
        if (i == 0x18)
            break;
    }
}
