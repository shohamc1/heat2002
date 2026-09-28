#include "global.h"
#include "gba/io_reg.h"
#include "functions.h"
#include "variables.h"

extern u8 gText_DemoMode[];
extern u8 gText_BlankRow12_3[];


void sub_0800AE94(u32 a)
{
    if (*(u32 *)(a + 0x18) & 0x10)
        sub_0800649C(gText_DemoMode, 0xB, 0xA);
    else
        sub_0800649C(gText_BlankRow12_3, 0xB, 0xA);
    --*(u32 *)(a + 0x18);
    ReadKeys();
    if ((gKeysHeld & 0x3FF) != 0 || *(u32 *)(a + 0x18) == 0)
    {
        BeginFadeToColor(0xA, 0);
        WaitForVBlank();
        REG_DISPCNT &= ~DISPCNT_OBJ_ON;
        gRaceEndState = 2;
        RemoveTask(a);
        FreeTask(a);
    }
}
