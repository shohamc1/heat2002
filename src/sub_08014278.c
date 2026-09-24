#include "global.h"
#include "gba/io_reg.h"

extern u16 gKeysPressed;
extern u8 gOptions[];
extern u8 gUnk_082EE104[];
extern void SortCarsByPoints(void);
extern void ZeroTextLayer(void);
extern void sub_0800F498(void);
extern void sub_0800F328(void *a, void *b);
extern void sub_08014104(u8 a);
extern void FadeToBrightenedPalette(void *a, u32 b);
extern void ReadKeys(void);
extern void m4aSongNumStart(u16 a);
extern u8 MenuMoveVertical(u16 keys, s8 v, u32 lo, u32 hi);
extern void WaitForVBlank(void);
extern void FadeToColor(u32 a, u32 b);
u8 StandingsScreen(void)
{
    void *p;
    u8 buf[0x200];
    u8 mode;
    s8 v;
    s8 sel;
    mode = 0;
    SortCarsByPoints();
    v = 0;
    ZeroTextLayer();
    sub_0800F498();
    p = gUnk_082EE104;
    sub_0800F328(p, buf);
    sub_08014104(0);
    FadeToBrightenedPalette(buf, 0x0F);
    sel = 0x40;
    do {
        ReadKeys();
        sub_08014104(mode);
        if (gKeysPressed & A_BUTTON)
            sel = v;
        if ((gKeysPressed & DPAD_UP) && mode == 1) {
            mode = 0;
            if (gOptions[3] != 0)
                m4aSongNumStart(8);
        }
        if ((gKeysPressed & DPAD_DOWN) && mode == 0) {
            mode = 1;
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
