#include "global.h"

extern u8 gUnk_020392C4;
extern u8 gUnk_020390EC;
extern u8 gUnk_0203916C;
extern u8 gUnk_020391F0;

u32 sub_0833BD94(u16 a);
void sub_0833EF0C(u32 a, u32 b, u32 c, u32 d);
void sub_0833D288(u32 a, u32 b);
void sub_08339B18(void);
void sub_0833FFA8(u32 a);
void sub_0833FF84(u32 a);

void sub_0834288C(u32 a)
{
    if (gUnk_020392C4 == 0)
    {
        if (gUnk_020390EC == 0)
            sub_0833EF0C(sub_0833BD94(4), 0xA, 3, 1);
        if (--*(u32 *)(a + 0x18) == 0)
        {
            sub_0833FFA8(a);
            sub_0833FF84(a);
            if (gUnk_0203916C != 4)
            {
                sub_0833D288(0xA, 0);
                sub_08339B18();
                *(volatile u16 *)0x04000000 &= 0xEFFF;
            }
            gUnk_020391F0 = 2;
        }
    }
}
