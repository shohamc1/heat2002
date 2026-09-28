#include "global.h"

extern const u8 gText_SingleRaceReward[];

u32 sub_08012384(u32 r0, u32 r1, u32 r2);

u8 sub_08014FD0(void)
{
    return sub_08012384((u32)gText_SingleRaceReward, 0x30, 0x4C);
}
