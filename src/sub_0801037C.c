#include "global.h"
#include "gba/compat.h"

extern u8 gUnk_0833338C[];
extern u32 gUnk_0600C000[];
extern u32 gUnk_082B76F0[];
extern vu32 gUnk_08364B08[];
extern u32 gUnk_082B731C[];

void WaitForVBlank(void);
void FadeToBrightenedPalette(u32 a, u32 b);
void WaitFrames(s32 n);
void FadeToColor(u32 a, u32 b);
void sub_08010714(void);

void sub_0801037C(void)
{
    u16 buf[0x100];
    volatile u16 *r;
    u16 i;
    vu32 *p;
    u16 v;

    sub_08016E10((u32)gUnk_0833338C, (u32)gUnk_0600C000, 0x1000);
    WaitForVBlank();
    r = &REG_BG2CNT;
    *r = 0x1081;
    r = &REG_BG0CNT;
    *r = 0x1C0D;
    r = &REG_DISPCNT;
    *r = 0x540;
    sub_08016E10((u32)gUnk_082B76F0, VRAM, 0x4000);
    sub_08010714();
    i = 0;
    p = gUnk_08364B08;
    v = 0;
    do {
        *(u16 *)(p[0] + i * 2) = v;
        i++;
    } while (i != 0x380);
    sub_08016E10((u32)gUnk_082B731C, (u32)buf, 0x100);
    FadeToBrightenedPalette((u32)buf, 0xF);
    WaitFrames(0xB4);
    FadeToColor(0, 0xF);
}
