#include "global.h"
#include "variables.h"

extern u8 gModule_02025220[]; /* 0x02025220 */

void sub_0833E0AC(void)
{
    int v;
    u8 *e;

    gModule_CountdownMs = 0;
    gModule_CountdownSeconds = gUnk_0203B6F0;
    gUnk_0203B6E8 = 1;
    if (gModule_GameMode[0] == 0xA)
        gModule_CountdownSeconds = 0x14;
    if (gModule_GameMode[0] == 0)
    {
        v = (u8)(3 - gModule_Options[0]);
        e = gModule_02025220;
        e += gModule_TrackId;
        v += 3;
        gModule_CountdownSeconds = *e + v;
    }
}
