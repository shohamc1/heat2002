#include "global.h"

extern const u8 gText_MpOkWaitingScreen[];

u32 sub_08012384(u32 r0, u32 r1, u32 r2);

u8 sub_080145E4(void)
{
    return sub_08012384((u32)gText_MpOkWaitingScreen, 0x20, 0x4C);
}
