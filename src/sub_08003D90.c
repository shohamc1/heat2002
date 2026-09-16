#include "global.h"
#include "gba/defines.h"

void sub_08003D3C(u32 a, u32 b);

void sub_08003D90(void)
{
    sub_08003D3C(IWRAM_START, BG_SCREEN_ADDR(29));
    sub_08003D3C(IWRAM_START + 0x800, BG_SCREEN_ADDR(30));
}
