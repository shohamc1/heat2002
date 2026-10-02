#include "global.h"
#include "functions.h"
#include "data.h"
#include "m4a.h"
#include "variables.h"
#include "car.h"

extern const u8 gText_SingleRaceReward[];

u32 sub_08012384(u32 r0, u32 r1, u32 r2);

u8 sub_08014FD0(void)
{
    return sub_08012384((u32)gText_SingleRaceReward, 0x30, 0x4C);
}

extern const u8 gText_ChampReward[];


u8 sub_08014FE8(void)
{
    return sub_08012384((u32)gText_ChampReward, 0x6C, 0x4C);
}

void sub_08015000(u8 a)
{
    const u8 *v;
    u8 b;

    b = a;
    DummyUiFontLoad(gUiFontTable[0]);
    GetString(0x0A);
    ((void (*)(void))DrawBigText)();
    v = GetString(0x05);
    DrawTextCenteredHighlight(v, 7, a == 0);
    v = GetString(0x07);
    DrawTextCenteredHighlight(v, 9, a == 1);
    v = GetString(0x08);
    DrawTextCenteredHighlight(v, 0xB, b == 2);
}

u8 sub_08015060(void)
{
    u8 buf[0x200];
    s8 v;
    s8 sel;

    v = 0;
    LoadMenuScreen(0, (u16 *)buf);
    sub_08015000(0);
    FadeToBrightenedPalette(buf, 0x0F);
    sel = 0x40;
    do {
        ReadKeys();
        sub_08015000(v);
        if (gKeysPressed & 1) {
            if (gOptions[3])
                m4aSongNumStart(9);
            sel = v;
        }
        if (gKeysPressed & 2)
            sel = 0x0A;
        v = MenuMoveVertical(gKeysPressed, v, 0, 2);
        WaitForVBlank();
    } while (sel == 0x40);
    FadeToColor(0, 0x0F);
    return sel;
}

void sub_080150F4(void)
{
    u8 buf[0x28];
    u16 m, s, f;
    struct Car **walk;
    u8 *ptr;
    u16 *pm, *ps, *pf;
    u8 i;

    DummyUiFontLoad(gUiFontTable[0]);
    GetString(0x10);
    ((void (*)(void))DrawBigText)();
    walk = gCarOrder;
    i = 0;
    pm = &m;
    ps = &s;
    pf = &f;
    do {
        ptr = (u8 *)*walk;
        SplitMilliseconds(*(u32 *)(ptr + 0x16C), pm, ps, pf);
        if (ptr == (u8 *)gCars && (gMenuBlinkCounter & 0x10) != 0) {
            DrawText(gText_BlankRow36, 1, i + 4, 1);
        } else {
            DrawText(GetDriverName(ptr[0x162]), 1, i + 4, 1);
            buf[0] = (m / 10) % 10 + 0x30;
            buf[1] = m % 10 + 0x30;
            buf[2] = 0x3A;
            buf[3] = (s / 10) % 10 + 0x30;
            buf[4] = s % 10 + 0x30;
            buf[5] = 0x3A;
            buf[6] = (*pf / 100) % 10 + 0x30;
            buf[7] = (*pf / 10) % 10 + 0x30;
            buf[8] = 0;
            DrawText(buf, 0x14, i + 4, 1);
        }
        walk++;
        i++;
    } while (i != 0x18);
    gMenuBlinkCounter++;
}

u8 sub_08015244(void)
{
    u8 buf[0x200];
    s8 v;
    s8 sel;

    v = 0;
    SortCarsByTime();
    LoadMenuScreen(0, (u16 *)buf);
    sub_080150F4();
    FadeToBrightenedPalette(buf, 0x0F);
    sel = 0x40;
    do {
        ReadKeys();
        sub_080150F4();
        if (gKeysPressed & 1)
            sel = v;
        v = MenuMoveVertical(*(volatile u16 *)&gKeysPressed, v, 0, 0);
        WaitForVBlank();
    } while (sel == 0x40);
    FadeToColor(0, 0x0F);
    return sel;
}

extern const u8 gText_ArcadeSplashScreen[];


u8 sub_080152B8(void)
{
    return sub_08012384((u32)gText_ArcadeSplashScreen, 0x28, 0x4C);
}

extern const u8 gText_SplashScreen[];


u8 sub_080152D0(void)
{
    return sub_08012384((u32)gText_SplashScreen, 0x44, 0x4C);
}

extern const u8 gText_CreditsScreen[];


u8 sub_080152E8(void)
{
    return sub_08012384((u32)gText_CreditsScreen, 0x40, 0x4C);
}

void sub_08015300(void)
{
}
