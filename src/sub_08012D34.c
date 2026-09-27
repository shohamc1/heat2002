#include "global.h"
#include "gba/io_reg.h"
#include "gba/defines.h"

extern u16 gKeysPressed;
extern volatile u8 gUnk_020020C0;

extern void sub_080045D8(void);
extern void InitGfxCaches(void);
extern void AgeGfxCaches(void);
extern void sub_08011C9C(u8 a, u16 *dst);
extern void ClearOamBuffer(void);
extern void sub_08012C4C(u8 a);
extern void sub_080047DC(void);
extern void WaitForVBlank(void);
extern void FadeToBrightenedPalette(u32 a, u32 b);
extern void ReadKeys(void);
extern void FadeToColor(u32 a, u32 b);

u8 sub_08012D34(u8 a)
{
    u8 buf[0x200];
    s8 sel;
    u8 v;

    v = 0;
    sub_080045D8();
    InitGfxCaches();
    AgeGfxCaches();
    sub_08011C9C(6, (u16 *)buf);
    ClearOamBuffer();
    sub_08012C4C(a);
    sub_080047DC();
    gUnk_020020C0 = v;
    WaitForVBlank();
    FadeToBrightenedPalette((u32)buf, 0x0F);
    WaitForVBlank();
    REG_DISPCNT = 0xAA << 5;
    sel = 0x40;
    do
    {
        ClearOamBuffer();
        ReadKeys();
        sub_08012C4C(a);
        if (gKeysPressed & 1)
            sel = v;
        sub_080047DC();
        gUnk_020020C0 = 0;
        WaitForVBlank();
    } while (sel != 0);
    FadeToColor(0, 0x0F);
    return sel;
}
