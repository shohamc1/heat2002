#include "global.h"
#include "variables.h"

struct Unk
{
    u32 a;
    u32 b;
    u16 c;
    u16 d;
};

extern struct Unk gUnk_0203B0F0[];

u32 sub_0833D7E8(void)
{
    u32 swapped;
    u32 i;
    u16 x;
    u16 y;

restart:
    swapped = 0;
    i = 0;
    do {
        x = gUnk_0203B610[i];
        y = gUnk_0203B610[i + 1];
        if (gUnk_0203B0F0[x].c < gUnk_0203B0F0[y].c) {
            gUnk_0203B610[i] = y;
            gUnk_0203B610[i + 1] = x;
            swapped = 1;
        }
        i++;
    } while (i != 0x3F);
    if (swapped != 0) goto restart;
}
