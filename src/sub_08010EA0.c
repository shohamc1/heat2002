#include "global.h"
#include "gba/io_reg.h"
#include "gba/defines.h"
#include "data.h"
extern u16 gKeysPressed;
extern volatile u8 gUnk_020020C0;
extern u8 gOptions[];
extern void sub_080045D8(void);
extern void InitGfxCaches(void);
extern void AgeGfxCaches(void);
extern void ClearOamBuffer(void);
extern void sub_080047DC(void);
extern void WaitForVBlank(void);
extern void ZeroTextLayer(void);
extern void sub_0800F4FC(void);
extern void sub_0800F328(u32 src, u16 *dst);
extern void sub_08010E04(u8 a);
extern void FadeToBrightenedPalette(u32 a, u32 b);
extern void ReadKeys(void);
extern s16 MenuMoveHorizontal(u16 keys, s16 v, s16 lo, s16 hi);
extern void m4aSongNumStart(u16 a);
extern void FadeToColor(u32 a, u32 b);

u8 sub_08010EA0(void)
{
    u8 buf[0x200];
    s8 v;
    s8 sel;
    u8 t;
    v = 0;
    sub_080045D8();
    InitGfxCaches();
    AgeGfxCaches();
    ClearOamBuffer();
    sub_080047DC();
    gUnk_020020C0 = 0;
    WaitForVBlank();
    ZeroTextLayer();
    sub_0800F4FC();
    sub_0800F328((u32)gUnk_082E4328, (u16 *)buf);
    sub_08010E04(0);
    FadeToBrightenedPalette((u32)buf, 0x0F);
    REG_DISPCNT = 0xA8 << 3;
    WaitForVBlank();
    REG_DISPCNT = 0xAA << 5;
    sel = 0x40;
    do {
        ClearOamBuffer();
        t = v;
        sub_08010E04(t);
        ReadKeys();
        if (gKeysPressed & 1)
            sel = t;
inner:
        v = MenuMoveHorizontal(gKeysPressed, v, 0, 0x0B);
        if (v == 6 || v == 7 || v == 10 || v == 11) {
            if ((gKeysPressed & 0x30) == 0)
                gKeysPressed |= 0x10;
            goto inner;
        }
        if (gKeysPressed & 2)
            sel = 0;
        sub_080047DC();
        gUnk_020020C0 = 0;
wait:
        if (gUnk_020020C0 == 0)
            goto wait;
        WaitForVBlank();
        WaitForVBlank();
    } while (sel == 0x40);
    WaitForVBlank();
    REG_DISPCNT = 0xA8 << 3;
    WaitForVBlank();
    if (gOptions[3] != 0)
        m4aSongNumStart(9);
    FadeToColor(0, 0x0F);
    return sel != 0 ? v : 0;
}
