#include "global.h"
#include "gba/defines.h"
#include "variables.h"

extern u32 gUnk_02024820;

void ResetSpriteQueues(void)
{
    gUnk_02024828 = EWRAM_START + 0x24830;
    gUnk_02024C30 = EWRAM_START + 0x24F50;
    gUnk_02024820 = EWRAM_START + 0x24C40;
    gUnk_02025150 = 0;
    gUnk_02025154 = 0;
    gUnk_02024824 = 0;
}
