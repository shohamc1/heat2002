#include "global.h"

extern void sub_08011C9C(u8 a, u16 *dst);
extern void sub_08011F78(s32 a);
extern void FadeToBrightenedPalette(u32 a, u32 b);

void sub_08012354(void)
{
    u8 buf[0x200];

    sub_08011C9C(4, (u16 *)buf);
    sub_08011F78(0);
    FadeToBrightenedPalette((u32)buf, 0x0F);
}
