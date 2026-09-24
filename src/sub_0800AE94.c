#include "global.h"
#include "gba/io_reg.h"

extern u8 gUnk_0806C948[];
extern u8 gUnk_0806C954[];
extern u16 gKeysHeld;
extern u8 gUnk_020021E0;

extern void sub_0800649C(u8 *str, u32 x, u32 y);
extern void ReadKeys(void);
extern void BeginFadeToColor(s32 a, u32 b);
extern void WaitForVBlank(void);
extern void RemoveTask(u32 a);
extern void FreeTask(u32 a);

void sub_0800AE94(u32 a)
{
    if (*(u32 *)(a + 0x18) & 0x10)
        sub_0800649C(gUnk_0806C948, 0xB, 0xA);
    else
        sub_0800649C(gUnk_0806C954, 0xB, 0xA);
    --*(u32 *)(a + 0x18);
    ReadKeys();
    if ((gKeysHeld & 0x3FF) != 0 || *(u32 *)(a + 0x18) == 0)
    {
        BeginFadeToColor(0xA, 0);
        WaitForVBlank();
        REG_DISPCNT &= ~DISPCNT_OBJ_ON;
        gUnk_020021E0 = 2;
        RemoveTask(a);
        FreeTask(a);
    }
}
