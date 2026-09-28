#include "global.h"

extern const u8 gText_MpTeamSelect[];

u32 sub_08012384(u32 r0, u32 r1, u32 r2);

u8 sub_0801459C(void)
{
    return sub_08012384((u32)gText_MpTeamSelect, 0x40, 0x4C);
}
