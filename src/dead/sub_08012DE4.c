#include "global.h"
#include "functions.h"
#include "data.h"
#include "m4a.h"
#include "variables.h"

void sub_08012DE4(void)
{
}

void sub_08012DE8(void)
{
}

void sub_08012DEC(u8 a)
{
    const u8 *v; sub_08006734(gUnk_083FDE18[0]);
    GetString(8);
    ((void (*)(void))DrawBigText)();
    v = GetString(0x66);
    DrawTextCenteredHighlight(v, 7, 1);
    v = GetString(0x67);
    DrawTextCenteredHighlight(v, 9, a == 0);
    v = GetString(0x68);
    DrawTextCenteredHighlight(v, 0xB, a == 1);
}

u8 sub_08012E48(void)
{
    u8 buf[0x200];
    s8 v;
    s8 sel;

    v = 0;
    WaitForVBlank();
    sub_08011C9C(3, (u16 *)buf);
    /* sub_08012DEC: this file's old local prototype differs from
       functions.h; call through the old signature (solved-walls 31). */
    ((void (*)(u8, u8))sub_08012DEC)(0, gChallengeIndex);
    FadeToBrightenedPalette((u32)buf, 0x0F);
    sel = 0x40;
    do {
        ReadKeys();
        ((void (*)(u8, u8))sub_08012DEC)(v, gChallengeIndex);
        if (gKeysPressed & 1)
            sel = v;
        v = MenuMoveVertical(gKeysPressed, v, 0, 1);
        WaitForVBlank();
    } while (sel == 0x40);
    if (gOptions[3] != 0)
        m4aSongNumStart(9);
    FadeToColor(0, 0x0F);
    return sel ^ 1;
}

void sub_08012EE8(u32 unused, u8 v)
{
    const u8 *r; sub_08006734(gUnk_083FDE18[0]);
    GetString(0x1E);
    ((void (*)(void))DrawBigText)();
    r = GetString(v + 0x1F);
    DrawTextCenteredHighlight(r, 8, 1);
}

u8 sub_08012F1C(void)
{
    u8 buf[0x200];
    s8 v;
    s8 sel;
    v = 0;
    sub_08011C9C(3, (u16 *)buf);
    /* sub_08012EE8: this file's old prototype differs from the matched definition; call through the old one */
    ((void (*)(u8, u8))sub_08012EE8)(0, gChallengeIndex);
    FadeToBrightenedPalette((u32)buf, 0x0F);
    sel = 0x40;
    do {
        ReadKeys();
        ((void (*)(u8, u8))sub_08012EE8)(v, gChallengeIndex);
        if (gKeysPressed & 1)
            sel = v;
        v = MenuMoveVertical(gKeysPressed, v, 0, 3);
        WaitForVBlank();
    } while (sel == 0x40);
    if (gOptions[3] != 0)
        m4aSongNumStart(9);
    FadeToColor(0, 0x0F);
    return sel;
}

void sub_08012FB0(void)
{
    sub_08006734(gUnk_083FDE18[0]);
    GetString(0x23);
    ((void (*)(void))DrawBigText)();
    DrawTextCenteredHighlight(GetString(0x11), 7, 1);
    DrawTextCenteredHighlight(GetString(0x11), 8, 1);
    DrawTextCenteredHighlight(GetString(0x11), 9, 1);
    DrawTextCenteredHighlight(GetString(0x11), 0xA, 1);
    DrawTextCenteredHighlight(GetString(0x11), 0xB, 1);
    DrawTextCenteredHighlight(GetString(0x11), 0xC, 1);
    DrawTextCenteredHighlight(GetString(0x11), 0xD, 1);
    DrawTextCenteredHighlight(GetString(0x11), 0xE, 1);
}

u8 sub_0801303C(void)
{
    u8 buf[0x200];
    s8 v;
    s8 sel;

    v = 0;
    sub_08011C9C(3, (u16 *)buf);
    sub_08012FB0();
    FadeToBrightenedPalette((u32)buf, 0x0F);
    sel = 0x40;
    do {
        ReadKeys();
        sub_08012FB0();
        if (gKeysPressed & 1)
            sel = v;
        v = MenuMoveVertical(*(volatile u16 *)&gKeysPressed, v, 0, 0);
        WaitForVBlank();
    } while (sel == 0x40);
    if (gOptions[3] != 0)
        m4aSongNumStart(9);
    FadeToColor(0, 0x0F);
    return sel;
}

void sub_080130BC(void)
{
}

void sub_080130C0(void)
{
}

void sub_080130C4(void)
{
}

void sub_080130C8(u8 a)
{
    const u8 *p; sub_08006734(gUnk_083FDE18[0]);
    p = GetString(0x0B);
    DrawBigText(p);
    p = GetString(0x05);
    DrawTextCenteredHighlight(p, 8, a == 0);
    p = GetString(0x08);
    DrawTextCenteredHighlight(p, 0x0B, a == 1);
}

u8 sub_08013114(void)
{
    u8 buf[0x200];
    s8 v;
    s8 sel;
    v = 0;
    sub_08011C9C(3, (u16 *)buf);
    sub_080130C8(0);
    FadeToBrightenedPalette((u32)buf, 0x0F);
    sel = 0x40;
    do {
        ReadKeys();
        sub_080130C8(v);
        if (gKeysPressed & 1)
            sel = v;
        v = MenuMoveVertical(gKeysPressed, v, 0, 1);
        WaitForVBlank();
    } while (sel == 0x40);
    if (gOptions[3] != 0)
        m4aSongNumStart(9);
    FadeToColor(0, 0x0F);
    return sel;
}

extern const u8 *const gCheatCodeTable[];

s8 sub_0801319C(void)
{
    u8 i;
    const u8 *e;

    i = 0;
    do {
        e = gCheatCodeTable[i];
        if (e[0] == gCheatCodeDials[0]
            && e[1] == gCheatCodeDials[1]
            && e[2] == gCheatCodeDials[2]
            && e[3] == gCheatCodeDials[3]
            && e[4] == gCheatCodeDials[4])
            return i;
        i++;
    } while (i != 5);
    return -1;
}

void sub_080064F8(u32 r0, u32 r1, u32 r2, u32 r3);

void sub_080131F8(u8 arg)
{
    u8 buf[0x12];
    u8 *p;

    p = &buf[0x10];
    p[1] = 0;
    sub_08006734(gUnk_083FDE18[0]);
    GetString(0x6B);
    ((void (*)(void))DrawBigText)();
    p[0] = (gCheatCodeDials[0] << 1) - 0x80;
    sub_080064F8((u32)p, 4, 7, arg == 0);
    p[0] = (gCheatCodeDials[1] << 1) - 0x80;
    sub_080064F8((u32)p, 9, 7, arg == 1);
    p[0] = (gCheatCodeDials[2] << 1) - 0x80;
    sub_080064F8((u32)p, 0xE, 7, arg == 2);
    p[0] = (gCheatCodeDials[3] << 1) - 0x80;
    sub_080064F8((u32)p, 0x13, 7, arg == 3);
    p[0] = (gCheatCodeDials[4] << 1) - 0x80;
    sub_080064F8((u32)p, 0x18, 7, arg == 4);
    if (gCheatMsgBlinkTimer != 0) {
        if (gCheatMsgBlinkTimer & 0x10) {
            DrawTextCenteredHighlight(GetString(gCheatCodeWasValid + 0x6C), 0xF, 1);
        } else {
            DrawText(gText_BlankRowMenu, 0, 0xF, 0);
        }
        gCheatMsgBlinkTimer--;
    }
}

void sub_080132F8(void)
{
    u8 buf[0x200];
    s8 v;
    s8 r;
    u8 i;
    u32 t;
    u32 sel;

    v = 0;
    gCheatCodeDials[0] = 0;
    gCheatCodeDials[1] = 0;
    gCheatCodeDials[2] = 0;
    gCheatCodeDials[3] = 0;
    gCheatCodeDials[4] = 0;
    sub_08011C9C(6, (u16 *)buf);
    sub_080131F8(0);
    FadeToBrightenedPalette((u32)buf, 0xF);
    gCheatMsgBlinkTimer = 0;
    sel = 0x40;
    do {
        ReadKeys();
        sub_080131F8(v);
        if (gKeysPressed & 1) {
            r = sub_0801319C();
            if (r != -1) {
                if (r == 4) {
                    gCheatFlags[0] = 1;
                    gCheatFlags[1] = 1;
                    gCheatFlags[2] = 1;
                    gCheatFlags[3] = 1;
                    gCheatFlags[4] = 1;
                    gCheatFlags[5] = 1;
                    gCheatFlags[6] = 1;
                    gCheatFlags[7] = 1;
                    i = 0;
                    do {
                        gProgressFlags[i] = 1;
                        i++;
                    } while (i != 10);
                    i = 0;
                    do {
                        gUnk_0202EDC8[i] = 1;
                        i++;
                    } while (i != 4);
                    i = 0;
                    do {
                        gUnk_0202ED80[i] = 0;
                        i++;
                    } while (i != 4);
                    gOptions[4] = 0x5B;
                    sub_08016330(3);
                } else {
                    gCheatFlags[r + 4] = 1;
                    SaveProgress();
                }
                if (gOptions[3] != 0)
                    m4aSongNumStart(0x18);
                gCheatMsgBlinkTimer = 0x40;
                gCheatCodeWasValid = 1;
            } else {
                if (gOptions[3] != 0)
                    m4aSongNumStart(0x19);
                gCheatMsgBlinkTimer = 0x40;
                gCheatCodeWasValid = 0;
            }
        }
        if (gKeysPressed & 2)
            sel = 0xFF;
        v = MenuMoveHorizontal(gKeysPressed, v, 0, 4);
        {
            /* The r0 pin keeps CSE from folding t into the call result:
               the store reads r0, and only the copy t lives on in r1. */
            register u32 r asm("r0") =
/* old prototype u32 MenuMoveVertical(...): the s16 return would add a
                         sign-extension pair before the r0 copy */
                ((u32 (*)(u16, u8, u32, u32))MenuMoveVertical)(gKeysPressed, gCheatCodeDials[v], 0, 9);
            gCheatCodeDials[v] = t = r;
        }
        if (gKeysPressed & 0xC0
            && ((u8)t == 0x41 || (u8)t == 0x45 || (u8)t == 0x49
                || (u8)t == 0x4F || (u8)t == 0x55))
            gCheatCodeDials[v] =
                MenuMoveVertical(gKeysPressed, gCheatCodeDials[v], 0x41, 0x5A);
        WaitForVBlank();
    } while (sel == 0x40);
    if (gOptions[3] != 0)
        m4aSongNumStart(9);
    FadeToColor(0, 0xF);
}
