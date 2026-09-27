#include "global.h"
#include "functions.h"


void sub_08012354(void)
{
    u8 buf[0x200];

    sub_08011C9C(4, (u16 *)buf);
    sub_08011F78(0);
    FadeToBrightenedPalette((u32)buf, 0x0F);
}
