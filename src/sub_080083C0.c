#include "global.h"
#include "variables.h"

extern u32 gTireGripDefaults[];

void sub_080083C0(u32 a, u8 b)
{
    if (gIsLinkRace != 0)
    {
        gTireGripSlow = gTireGripDefaults[0];
        gTireGripFast = gTireGripDefaults[1];
        gFrontTireGripSlow = gTireGripDefaults[2];
        gFrontTireGripFast = gTireGripDefaults[3];
        gTireSlipLimitBase = gTireGripDefaults[4];
    }
    else if (b == 0)
    {
        gTireGripSlow = gTireGripDefaults[0];
        gTireGripFast = gTireGripDefaults[1];
        gFrontTireGripSlow = gTireGripDefaults[2];
        gFrontTireGripFast = gTireGripDefaults[3];
        gTireSlipLimitBase = gTireGripDefaults[4];
    }
    else
    {
        gTireGripSlow = 0xA0;
        gTireGripFast = 0xFF;
        gFrontTireGripSlow = 0x80;
        gFrontTireGripFast = 0x80;
        gTireSlipLimitBase = 0x0000B060;
    }
}
