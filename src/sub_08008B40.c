#include "global.h"

struct Car
{
    u8 pad00[0x50];
    volatile u32 unk50;
};

extern s32 gUnk_0202CB14;
extern struct Car gUnk_0202A550[];

u8 sub_08008B40(s32 v)
{
    if (gUnk_0202CB14 > v)
        return 0;
    if ((gUnk_0202A550[0].unk50 & 0xFFFF) < (u32)v)
        return 0;
    return 1;
}
