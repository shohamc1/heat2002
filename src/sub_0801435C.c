#include "global.h"

extern const u8 gText_QualifyingResults[];

u32 sub_08012384(u32 r0, u32 r1, u32 r2);

u8 sub_0801435C(void)
{
    return sub_08012384((u32)gText_QualifyingResults, 0x30, 0x4C);
}
