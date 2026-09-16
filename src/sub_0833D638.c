#include "global.h"
#include "gba/defines.h"

extern u32 gUnk_0203ACD8;
extern u32 gUnk_0203B0E0;
extern u32 gUnk_0203ACD0;
extern u8 gUnk_0203B600;
extern u8 gUnk_0203B604;
extern u8 gUnk_0203ACD4;

void sub_0833D638(void)
{
    gUnk_0203ACD8 = EWRAM_START + 0x3ACE0;
    gUnk_0203B0E0 = EWRAM_START + 0x3B400;
    gUnk_0203ACD0 = EWRAM_START + 0x3B0F0;
    gUnk_0203B600 = 0;
    gUnk_0203B604 = 0;
    gUnk_0203ACD4 = 0;
}
