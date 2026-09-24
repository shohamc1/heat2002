#include "global.h"

extern void sub_08011C9C(u32 a, void *b);
extern void sub_08011F78(s32 a);
extern void FadeToBrightenedPalette(void *a, u32 b);

void sub_08012354(void)
{
    u8 buf[0x200];

    sub_08011C9C(4, buf);
    sub_08011F78(0);
    FadeToBrightenedPalette(buf, 0x0F);
}
