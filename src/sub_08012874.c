#include "global.h"

extern u16 gKeysPressed;
extern u8 gUnk_082EE104[];

extern void ZeroTextLayer(void);
extern void sub_0800F498(void);
extern void sub_0800F328(void *a, void *b);
extern void sub_080127E4(u8 a);
extern void FadeToBrightenedPalette(void *a, u32 b);
extern void ReadKeys(void);
extern void WaitForVBlank(void);
extern void FadeToColor(u32 a, u32 b);

void sub_08012874(s8 a)
{
    void *p;
    u8 buf[0x200];
    s8 sel;

    ZeroTextLayer();
    sub_0800F498();
    p = gUnk_082EE104;
    sub_0800F328(p, buf);
    sub_080127E4(a);
    FadeToBrightenedPalette(buf, 0x0F);
    sel = 0x40;
    do {
        ReadKeys();
        sub_080127E4(a);
        if (gKeysPressed & 1)
            sel = a;
        WaitForVBlank();
    } while (sel == 0x40);
    FadeToColor(0, 0x0F);
}
