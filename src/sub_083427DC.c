#include "global.h"
#include "gba/io_reg.h"

extern u8 gUnk_0200D0F4[];
extern u8 gUnk_0200D100[];
extern u16 gUnk_02037618;
extern u8 gUnk_020391F0;

extern void sub_0833EF0C(u8 *str, u32 x, u32 y);
extern void sub_08339B4C(void);
extern void sub_0833D288(u32 a, u32 b);
extern void sub_08339B18(void);
extern void sub_0833FFA8(u32 a);
extern void sub_0833FF84(u32 a);

void sub_083427DC(u32 a)
{
    if (*(u32 *)(a + 0x18) & 0x10)
        sub_0833EF0C(gUnk_0200D0F4, 0xB, 0xA);
    else
        sub_0833EF0C(gUnk_0200D100, 0xB, 0xA);
    --*(u32 *)(a + 0x18);
    sub_08339B4C();
    if ((gUnk_02037618 & 0x3FF) != 0 || *(u32 *)(a + 0x18) == 0)
    {
        sub_0833D288(0xA, 0);
        sub_08339B18();
        REG_DISPCNT &= ~DISPCNT_OBJ_ON;
        gUnk_020391F0 = 2;
        sub_0833FFA8(a);
        sub_0833FF84(a);
    }
}
