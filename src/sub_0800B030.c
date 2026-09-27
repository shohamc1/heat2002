#include "global.h"
#include "gba/io_reg.h"
#include "functions.h"
#include "variables.h"

extern u8 gUnk_0202EDCC;


void sub_0800B030(u32 a)
{
    gUnk_0202EDCC = 1;
    if (gFadeActive == 0)
    {
        DrawSpriteText((u8 *)(GetString(0x9B)), 0x4C, 0x18);
        if (--*(u32 *)(a + 0x18) == 0)
        {
            RemoveTask(a);
            FreeTask(a);
            BeginFadeToColor(0xA, 0);
            WaitForVBlank();
            REG_DISPCNT &= ~DISPCNT_OBJ_ON;
            gRaceEndState = 2;
        }
    }
}
