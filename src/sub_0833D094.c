#include "global.h"
#include "gba/defines.h"

void sub_0833D040(u32 a, u32 b);

void sub_0833D094(void)
{
    sub_0833D040(IWRAM_START, (u32)BG_SCREEN_ADDR(29));
    sub_0833D040(IWRAM_START + 0x800, (u32)BG_SCREEN_ADDR(30));
}
