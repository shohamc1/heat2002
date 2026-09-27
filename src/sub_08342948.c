#include "global.h"
#include "gba/io_reg.h"
#include "functions.h"
#include "variables.h"

extern u8 gUnk_0203E000;


void sub_08342948(u32 a)
{
    gUnk_0203E000 = 1;
    if (gUnk_020392C4 == 0)
    {
        sub_08343148((u8 *)(sub_0833BD94(0x05)), 0x4C, 0x18);
        if (--*(u32 *)(a + 0x18) == 0)
        {
            sub_0833FFA8(a);
            sub_0833FF84(a);
            sub_0833D288(0xA, 0);
            sub_08339B18();
            REG_DISPCNT &= ~DISPCNT_OBJ_ON;
            gUnk_020391F0 = 2;
        }
    }
}
