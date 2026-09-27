#include "global.h"
extern u16 gKeysPressed;
extern u8 gOptions[];
extern u8 gUnk_083FDA60[];
extern u8 gUnk_083FDA67[];
extern void sub_08011C9C(u8 a, u16 *dst);
extern void DrawOptionsMenu(s8 a);
extern void FadeToBrightenedPalette(u32 a, u32 b);
extern void ReadKeys(void);
extern void sub_0800F600(void);
extern void sub_0800F6A0(void);
extern void sub_0800F740(void);
extern s16 MenuMoveVertical(u16 keys, s16 v, s16 lo, s16 hi);
extern s16 MenuMoveHorizontal(u16 keys, s16 v, s16 lo, s16 hi);
extern void sub_080100B0(void);
extern void StopAllSongs(void);
extern void WaitForVBlank(void);
extern void m4aSongNumStart(u16 a);
extern void FadeToColor(u32 a, u32 b);
u8 OptionsMenu(void)
{
    u8 buf[0x200];
    s8 v;
    s8 sel;
    v = 0;
    sub_08011C9C(7, (u16 *)buf);
    DrawOptionsMenu(0);
    FadeToBrightenedPalette((u32)buf, 0x0F);
    sel = 0x40;
    do {
        ReadKeys();
        DrawOptionsMenu(v);
        if (gKeysPressed & 1) {
            if (v == 5) {
                sub_0800F600();
                sub_0800F6A0();
                sub_0800F740();
                return sel;
            }
            sel = v;
        }
        if (gKeysPressed & 2)
            sel = 1;
        v = MenuMoveVertical(gKeysPressed, v, 0, 5);
        gOptions[v] = MenuMoveHorizontal(gKeysPressed, gOptions[v],
                                        gUnk_083FDA60[v], gUnk_083FDA67[v]);
        if (v == 2) {
            if ((gKeysPressed & 0x30) && gOptions[2] != 0)
                sub_080100B0();
            if ((gKeysPressed & 0x30) && gOptions[2] == 0)
                StopAllSongs();
        }
        WaitForVBlank();
    } while (sel == 0x40);
    if (gOptions[3] != 0)
        m4aSongNumStart(9);
    FadeToColor(0, 0x0F);
    return sel;
}
