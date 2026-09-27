#include "global.h"
#include "variables.h"
#include "car.h"

void sub_083416DC(u8 *a, u8 b);

void sub_083419D8(void)
{
    u32 i;
    u32 limit;
    u8 *p;

    limit = gModule_NumCars[0];
    if (gModule_IsLinkRace != 0)
        limit = gModule_NumLinkPlayers[0];
    p = (u8 *)gModule_Cars;
    for (i = 0; i != limit; i++, p += 0x190)
    {
        if (gModule_GameMode[0] != 2 || i == 0)
            sub_083416DC(p, i);
    }
}
