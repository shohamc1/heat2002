#include "global.h"
#include "gba/io_reg.h"
#include "functions.h"
#include "variables.h"

extern u8 gModule_DemoMode[];
extern u8 gModule_OutOfTime[];


void sub_083427DC(u32 a)
{
    if (*(u32 *)(a + 0x18) & 0x10)
        sub_0833EF0C(gModule_DemoMode, 0xB, 0xA);
    else
        sub_0833EF0C(gModule_OutOfTime, 0xB, 0xA);
    --*(u32 *)(a + 0x18);
    sub_08339B4C();
    if ((gUnk_02037618 & 0x3FF) != 0 || *(u32 *)(a + 0x18) == 0)
    {
        sub_0833D288(0xA, 0);
        sub_08339B18();
        REG_DISPCNT &= ~DISPCNT_OBJ_ON;
        gModule_RaceEndState = 2;
        sub_0833FFA8(a);
        sub_0833FF84(a);
    }
}
