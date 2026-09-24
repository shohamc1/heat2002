#include "global.h"
#include "gba/io_reg.h"

extern u16 gKeysPressed;
extern u8 gOptions[];
extern void SortCarsByTime(void);
extern void sub_08011C9C(u32 a, void *b);
extern void sub_08013E3C(s32 a);
extern void FadeToBrightenedPalette(void *a, u32 b);
extern void ReadKeys(void);
extern u8 MenuMoveVertical(u16 keys, s8 v, u32 lo, u32 hi);
extern void WaitForVBlank(void);
extern void m4aSongNumStart(u16 a);
extern void FadeToColor(u32 a, u32 b);
u8 sub_08014004(void)
{
    u8 buf[0x200];
    s8 v;
    s32 a;
    s8 sel;
    /* The copy and narrowed test below preserve initialization/register order. */
    a = 0;
    v = a;
    SortCarsByTime();
    sub_08011C9C(6, buf);
    sub_08013E3C(0);
    FadeToBrightenedPalette(buf, 0x0F);
    sel = 0x40;
    do {
        ReadKeys();
        sub_08013E3C(a);
        if (gKeysPressed & A_BUTTON)
            sel = v;
        if ((gKeysPressed & DPAD_UP) && a == 1) {
            a = 0;
            if (gOptions[3])
                m4aSongNumStart(8);
        }
        if ((gKeysPressed & DPAD_DOWN) && (u8)a == 0) {
            a = 1;
            if (gOptions[3])
                m4aSongNumStart(8);
        }
        v = MenuMoveVertical(gKeysPressed, v, 0, 0);
        WaitForVBlank();
    } while (sel == 0x40);
    if (gOptions[3])
        m4aSongNumStart(9);
    FadeToColor(0, 0x0F);
    return sel;
}
