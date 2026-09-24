#include "global.h"
#include "gba/io_reg.h"

extern u16 gKeysPressed;
extern u8 gOptions[];
extern void ZeroTextLayer(void);
extern void sub_0800F498(void);
extern void sub_0800F328(u32 a, void *b);
extern void SortCarsByTime(void);
extern void sub_08013B64(u8 a);
extern void FadeToBrightenedPalette(void *a, u32 b);
extern void ReadKeys(void);
extern void m4aSongNumStart(u16 a);
extern u8 MenuMoveVertical(u16 keys, s8 v, u32 lo, u32 hi);
extern void WaitForVBlank(void);
extern void FadeToColor(u32 a, u32 b);

u8 sub_08013D5C(void)
{
    u8 buf[0x200];
    s8 v;
    s8 sel;
    u8 x;
    x = v = 0;
    ZeroTextLayer();
    sub_0800F498();
    sub_0800F328(0x082EE104, buf);
    SortCarsByTime();
    sub_08013B64(0);
    FadeToBrightenedPalette(buf, 0x0F);
    sel = 0x40;
    do {
        ReadKeys();
        sub_08013B64(x);
        if (gKeysPressed & A_BUTTON)
            sel = v;
        if ((gKeysPressed & DPAD_UP) && x == 1) {
            x = 0;
            if (gOptions[3] != 0)
                m4aSongNumStart(8);
        }
        if ((gKeysPressed & DPAD_DOWN) && x == 0) {
            x = 1;
            if (gOptions[3] != 0)
                m4aSongNumStart(8);
        }
        v = MenuMoveVertical(gKeysPressed, v, 0, 0);
        WaitForVBlank();
    } while (sel == 0x40);
    if (gOptions[3] != 0)
        m4aSongNumStart(9);
    FadeToColor(0, 0x0F);
    return sel;
}
