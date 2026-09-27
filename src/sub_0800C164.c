#include "global.h"
#include "variables.h"

extern u8 gCars[][0x190];

void WorldToCarLocal(s32 *a, s32 b, s32 c, s32 *d);

u8 CheckDrafting(u8 *a)
{
    s32 d1[2];
    s32 d2[2];
    u8 count;
    u8 i;
    u8 *e;

    count = gNumCars[0];
    if (gIsLinkRace != 0)
        count = gNumLinkPlayers[0];
    e = gCars;
    for (i = 0; i != count; i++, e += 0x190) {
        if (e == a)
            continue;
        WorldToCarLocal((s32 *)a, *(s32 *)&e[0], *(s32 *)&e[8], d1);
        if ((u32)(d1[1] + 100) > 100)
            continue;
        {
            s32 dx = d1[0];
            s32 lim = -16;

            if (dx < lim || dx > 16)
                continue;
            WorldToCarLocal((s32 *)e, *(s32 *)&a[0], *(s32 *)&a[8], d2);
            if (d2[1] < 0)
                continue;
            if (d2[0] < lim || d2[0] > 16)
                continue;
        }
        a[0x176] = 15;
        return 1;
    }
    return 0;
}
