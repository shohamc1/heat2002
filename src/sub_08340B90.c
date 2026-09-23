#include "global.h"

struct Unk0202A550
{
    u8 filler0[0x162];
    u8 unk162;
    u8 filler163[400 - 0x163];
};

extern struct Unk0202A550 gUnk_0203D520[];

extern u8 sub_0833BCBC(void);

void sub_08340B90(void)
{
    u32 i;
    u8 v;
    u8 dup;
    u8 j;

    for (i = 1; i != 0x5; i++)
        gUnk_0203D520[i].unk162 = 99;
    i = 1;
    for (;;)
    {
        v = 0x1F & sub_0833BCBC();
        if (v > 0x1D)
            continue;
        dup = 0;
        j = 0;
        do
        {
            if (v == gUnk_0203D520[j].unk162)
                dup = 1;
            j++;
        } while (j != 0x5);
        if (dup != 0)
            continue;
        gUnk_0203D520[i].unk162 = v;
        i++;
        if (i == 0x5)
            break;
    }
}
