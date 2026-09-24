#include "global.h"

extern u16 gKeysPressed;
extern u8 gUnk_0202EF78[];
extern u8 gUnk_0202EF80[];
extern u8 gUnk_0202EEC0[];
extern u8 gUnk_0202EDC8[];
extern u8 gUnk_0202ED80[];
extern u8 gOptions[];
extern u8 gUnk_0202EEB4;
extern u8 gUnk_0202EDB0;

extern void sub_08011C9C(u32 a, void *b);
extern void sub_080131F8(u8 a);
extern void FadeToBrightenedPalette(void *a, u32 b);
extern void ReadKeys(void);
extern s8 sub_0801319C(void);
extern void sub_08016330(u8 a);
extern void SaveProgress(void);
extern void m4aSongNumStart(u16 a);
extern u8 MenuMoveHorizontal(u16 keys, s8 v, u32 lo, u32 hi);
extern u32 MenuMoveVertical(u16 keys, u8 v, u32 lo, u32 hi);
extern void WaitForVBlank(void);
extern void FadeToColor(u32 a, u32 b);

void sub_080132F8(void)
{
    u8 buf[0x200];
    s8 v;
    s8 r;
    u8 i;
    u32 t;
    u32 sel;

    v = 0;
    gUnk_0202EF78[0] = 0;
    gUnk_0202EF78[1] = 0;
    gUnk_0202EF78[2] = 0;
    gUnk_0202EF78[3] = 0;
    gUnk_0202EF78[4] = 0;
    sub_08011C9C(6, buf);
    sub_080131F8(0);
    FadeToBrightenedPalette(buf, 0xF);
    gUnk_0202EEB4 = 0;
    sel = 0x40;
    do {
        ReadKeys();
        sub_080131F8(v);
        if (gKeysPressed & 1) {
            r = sub_0801319C();
            if (r != -1) {
                if (r == 4) {
                    gUnk_0202EEC0[0] = 1;
                    gUnk_0202EEC0[1] = 1;
                    gUnk_0202EEC0[2] = 1;
                    gUnk_0202EEC0[3] = 1;
                    gUnk_0202EEC0[4] = 1;
                    gUnk_0202EEC0[5] = 1;
                    gUnk_0202EEC0[6] = 1;
                    gUnk_0202EEC0[7] = 1;
                    i = 0;
                    do {
                        gUnk_0202EF80[i] = 1;
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
                    gUnk_0202EEC0[r + 4] = 1;
                    SaveProgress();
                }
                if (gOptions[3] != 0)
                    m4aSongNumStart(0x18);
                gUnk_0202EEB4 = 0x40;
                gUnk_0202EDB0 = 1;
            } else {
                if (gOptions[3] != 0)
                    m4aSongNumStart(0x19);
                gUnk_0202EEB4 = 0x40;
                gUnk_0202EDB0 = 0;
            }
        }
        if (gKeysPressed & 2)
            sel = 0xFF;
        v = MenuMoveHorizontal(gKeysPressed, v, 0, 4);
        {
            /* The r0 pin keeps CSE from folding t into the call result:
               the store reads r0, and only the copy t lives on in r1. */
            register u32 r asm("r0") =
                MenuMoveVertical(gKeysPressed, gUnk_0202EF78[v], 0, 9);
            gUnk_0202EF78[v] = t = r;
        }
        if (gKeysPressed & 0xC0
            && ((u8)t == 0x41 || (u8)t == 0x45 || (u8)t == 0x49
                || (u8)t == 0x4F || (u8)t == 0x55))
            gUnk_0202EF78[v] =
                MenuMoveVertical(gKeysPressed, gUnk_0202EF78[v], 0x41, 0x5A);
        WaitForVBlank();
    } while (sel == 0x40);
    if (gOptions[3] != 0)
        m4aSongNumStart(9);
    FadeToColor(0, 0xF);
}
