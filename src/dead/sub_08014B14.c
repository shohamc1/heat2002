#include "global.h"
#include "gba/io_reg.h"
#include "gba/defines.h"
#include "functions.h"
#include "variables.h"

extern u8 gUnk_0202EDB4;
extern u32 gUnk_0202EDC0;
extern u8 gUnk_0202EDE0;
extern u8 gUnk_0202EEF0;
extern u8 gUnk_0202EEE0;
extern u8 gUnk_0202F02C;
extern u8 gUnk_0202CDB0[];

void sub_08014B14(void)
{
    u8 *p;
    u8 *q0;
    u8 *q1;
    u8 *q2;
    u8 *q3;
    s32 r;

    gUnk_0202EDB4 = 0;
    gUnk_0202EDC0 = 0;
    q0 = &gUnk_0202F02C;
    q1 = &gUnk_0202EEE0;
    q2 = &gUnk_0202EEF0;
    q3 = &gUnk_0202EDE0;
    *q3 = 0;
    *q2 = 0;
    *q1 = 0;
    *q0 = 0;
    p = gUnk_0202CDB0;
    r = p[0] * 100 / p[1];
    p[2] = r;
    p[5] = p[3] * 100 / p[4];
    p[8] = p[6] * 100 / p[7];
    if ((u8)r > 100)
        p[2] = 100;
    *(s32 *)&p[0xC] = (p[2] + p[5] + p[8] + p[9]) >> 2;
}

void sub_08014BA0(void)
{
}

u8 sub_08014BA4(void)
{
    u8 buf[0x200];
    s8 v;
    s8 sel;
    s8 w;

    v = 0;
    LoadMenuScreen(12, (u16 *)buf);
    REG_DISPCNT = 0x1341;
    sub_08014B14();
    ResetSpriteOrderTable();
    InitGfxCaches();
    AgeGfxCaches();
    ClearOamBuffer();
    /* sub_08014BA0: this file's old local prototype differs from
       functions.h; call through the old signature (solved-walls 31). */
    ((void (*)(u8))sub_08014BA0)(0);
    UpdateSprites();
    gVBlankWorkDone = v;
    WaitForVBlank();
    FadeToBrightenedPalette((u32)buf, 0x0F);
    sel = 0x40;
    w = 0;
    do {
        AgeGfxCaches();
        ClearOamBuffer();
        ((void (*)(u8))sub_08014BA0)(w);
        UpdateSprites();
        ReadKeys();
        if (gKeysPressed & 1)
            sel = w;
        gVBlankWorkDone = 0;
        WaitForVBlank();
    } while (sel != 0);
    FadeToColor(0, 0x0F);
    return sel;
}

extern const u8 gText_ChampPenalised[];

u32 sub_08012384(u32 r0, u32 r1, u32 r2);

u8 sub_08014C48(void)
{
    return sub_08012384((u32)gText_ChampPenalised, 0x38, 0x4C);
}
