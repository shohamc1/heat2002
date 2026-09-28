#include "global.h"
#include "functions.h"

void sub_08012354(void)
{
    u8 buf[0x200];

    LoadMenuScreen(4, (u16 *)buf);
    DrawMultiplayerMenu(0);
    FadeToBrightenedPalette((u32)buf, 0x0F);
}

void sub_08012384(void)
{
}

void sub_08012388(void)
{
}
