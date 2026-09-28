#include "global.h"
#include "functions.h"
#include "variables.h"



void sub_08342A14(u32 a)
{
    s32 t;

    if (gModule_PaletteFadeActive == 0)
    {
        t = *(s32 *)(a + 0x18);
        if (t > 0x2D)
        {
            if (gModule_GameMode[0] == 9)
                gModule_GameMode[0] = 6;
            if (gModule_GameMode[0] == 0xD)
                gModule_GameMode[0] = 0xC;
            if (gModule_GameMode[0] == 0xE)
                gModule_GameMode[0] = 2;
            if (gModule_GameMode[0] == 0xF)
                gModule_GameMode[0] = 0x10;
            if (gModule_GameMode[0] == 0x11)
                gModule_GameMode[0] = 5;
            gModule_RaceStarted = 1;
        }
        *(s32 *)(a + 0x18) = t + 1;
        if (t + 1 == 0x7A)
        {
            sub_0833FFA8(a);
            sub_0833FF84(a);
        }
        if (gModule_RaceStarted == 0)
            sub_08339B18();
    }
}
