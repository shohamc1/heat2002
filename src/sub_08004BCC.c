#include "global.h"

extern u16 gKeysPressed;
extern u8 gUnk_020020C0;
extern u8 gUnk_02025370;

extern void sub_080047DC(void);
extern void ReadKeys(void);
extern s16 MenuMoveVertical(u16 keys, s16 v, s16 lo, s16 hi);
extern void sub_08004B1C(u8 arg);
extern void AgeGfxCaches(void);
extern void ClearOamBuffer(void);
extern void sub_08004A7C(u8 sel);
extern void WaitForVBlank(void);

void sub_08004BCC(void)
{
    u8 v;
    u16 start;

    if (gKeysPressed & 4) {
        v = 0;
        sub_080047DC();
loop:
        ReadKeys();
        start = gKeysPressed & 4;
        if (start == 0) {
            v = MenuMoveVertical(gKeysPressed, v, 0, 9);
            sub_08004B1C(v);
            AgeGfxCaches();
            ClearOamBuffer();
            sub_08004A7C(v);
            sub_080047DC();
            gUnk_020020C0 = start;
            gUnk_02025370++;
            WaitForVBlank();
            goto loop;
        }
    }
}
