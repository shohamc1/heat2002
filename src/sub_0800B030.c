#include "global.h"
#include "gba/io_reg.h"

extern u8 gUnk_0202EDCC;
extern u8 gUnk_02022E14;
extern u8 gUnk_020021E0;

extern u32 sub_08016558(u16 idx);
extern void sub_0800BB58(u8 *a, u32 b, u32 c);
extern void sub_08007950(u32 a);
extern void sub_0800792C(u32 a);
extern void sub_08003F84(s32 a, u32 b);
extern void sub_08000458(void);

void sub_0800B030(u32 a)
{
    gUnk_0202EDCC = 1;
    if (gUnk_02022E14 == 0)
    {
        sub_0800BB58(sub_08016558(0x9B), 0x4C, 0x18);
        if (--*(u32 *)(a + 0x18) == 0)
        {
            sub_08007950(a);
            sub_0800792C(a);
            sub_08003F84(0xA, 0);
            sub_08000458();
            REG_DISPCNT &= ~DISPCNT_OBJ_ON;
            gUnk_020021E0 = 2;
        }
    }
}
