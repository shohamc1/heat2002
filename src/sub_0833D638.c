#include "global.h"
#include "gba/defines.h"
#include "variables.h"


void sub_0833D638(void)
{
    gUnk_0203ACD8 = (u32 *)(EWRAM_START + 0x3ACE0);
    gUnk_0203B0E0 = EWRAM_START + 0x3B400;
    gUnk_0203ACD0 = (u32 *)(EWRAM_START + 0x3B0F0);
    gUnk_0203B600 = 0;
    gUnk_0203B604 = 0;
    gUnk_0203ACD4 = 0;
}
