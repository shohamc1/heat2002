#include "global.h"

struct Car
{
    u8 pad00[0x50];
    volatile u32 unk50;
};

extern s32 gUnk_0203DD34;
extern struct Car gUnk_0203D520[];

u8 sub_08340CB0(s32 v)
{
    if (gUnk_0203DD34 > v)
        return 0;
    if ((gUnk_0203D520[0].unk50 & 0xFFFF) < (u32)v)
        return 0;
    return 1;
}
