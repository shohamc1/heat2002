#include "global.h"
#include "variables.h"

extern u8 gTrackCountdownExtraSeconds[];

void sub_080055B0(void)
{
    u32 v;
    u32 n;
    u8 *base;
    u8 *p;

    gCountdownMs = 0;
    gCountdownSeconds = gDefaultCountdownSeconds;
    gUnk_02025238 = 1;
    v = gGameMode[0];
    if (v == 0xA)
        gCountdownSeconds = 0x14;
    if (v == 0) {
        n = (u8)(3 - gOptions[0]);
        base = gTrackCountdownExtraSeconds;
        p = base + gTrackId;
        n += 3;
        gCountdownSeconds = *p + n;
    }
}
