#include "global.h"

extern const u8 gText_ChampReward[];

u32 sub_08012384(u32 r0, u32 r1, u32 r2);

u8 sub_08014FE8(void)
{
    return sub_08012384((u32)gText_ChampReward, 0x6C, 0x4C);
}
