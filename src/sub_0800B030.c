#include "global.h"
#include "gba/io_reg.h"

extern u8 gUnk_0202EDCC;
extern u8 gUnk_02022E14;
extern u8 gUnk_020021E0;

extern u32 GetString(u16 idx);
extern void DrawSpriteText(u8 *a, u32 b, u32 c);
extern void RemoveTask(u32 a);
extern void FreeTask(u32 a);
extern void BeginFadeToColor(s32 a, u32 b);
extern void WaitForVBlank(void);

void sub_0800B030(u32 a)
{
    gUnk_0202EDCC = 1;
    if (gUnk_02022E14 == 0)
    {
        DrawSpriteText(GetString(0x9B), 0x4C, 0x18);
        if (--*(u32 *)(a + 0x18) == 0)
        {
            RemoveTask(a);
            FreeTask(a);
            BeginFadeToColor(0xA, 0);
            WaitForVBlank();
            REG_DISPCNT &= ~DISPCNT_OBJ_ON;
            gUnk_020021E0 = 2;
        }
    }
}
