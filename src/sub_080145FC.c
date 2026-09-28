#include "global.h"

extern const u8 gText_RaceSummary[];

u32 sub_08012384(u32 r0, u32 r1, u32 r2);

u8 sub_080145FC(void)
{
    return sub_08012384((u32)gText_RaceSummary, 0x48, 0x4C);
}
