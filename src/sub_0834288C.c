#include "global.h"
#include "functions.h"
#include "variables.h"



void sub_0834288C(u32 a)
{
    if (gUnk_020392C4 == 0)
    {
        if (gUnk_020390EC == 0)
            /* sub_0833EF0C: this file's old local prototype differs from
               functions.h; call through the old signature (solved-walls 31). */
            ((void (*)(u32, u32, u32, u32))sub_0833EF0C)(sub_0833BD94(4), 0xA, 3, 1);
        if (--*(u32 *)(a + 0x18) == 0)
        {
            sub_0833FFA8(a);
            sub_0833FF84(a);
            if (gUnk_0203916C[0] != 4)
            {
                sub_0833D288(0xA, 0);
                sub_08339B18();
                *(volatile u16 *)0x04000000 &= 0xEFFF;
            }
            gUnk_020391F0 = 2;
        }
    }
}
