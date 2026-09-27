#include "global.h"
extern u16 gKeysPressed;
extern u8 gOptions[];
extern s8 sub_08016634(void);
extern s8 sub_08013878(void);
extern void sub_08011C9C(u8 a, u16 *dst);
extern void sub_08013908(u32 a);
extern void FadeToBrightenedPalette(u32 a, u32 b);
extern void SaveSeason(void);
extern void ReadKeys(void);
extern void WaitForVBlank(void);
extern void m4aSongNumStart(u16 a);
extern void FadeToColor(u32 a, u32 b);
s8 sub_08013964(void)
{
    u8 buf[0x200];
    s8 sel;
    /* Keep this signed-byte local: its allocation reproduces the saved registers. */
    s8 v = 0;
    if (sub_08016634() != 0) {
        if (sub_08013878() == 0)
            return;
    }
    sub_08011C9C(6, (u16 *)buf);
    sub_08013908(0);
    FadeToBrightenedPalette((u32)buf, 0x0F);
    SaveSeason();
    sub_08013908(1);
    sel = 0x40;
    do {
        ReadKeys();
        if (gKeysPressed & 9)
            sel = v;
        WaitForVBlank();
    } while (sel == 0x40);
    if (gOptions[3] != 0)
        m4aSongNumStart(9);
    FadeToColor(0, 0x0F);
    return sel;
}
