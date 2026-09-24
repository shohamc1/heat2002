#include "global.h"

extern u16 gKeysPressed;           /* 0x020005CC */
extern u8 gUnk_02025248;           /* 0x02025248 */
extern u8 gUnk_0202539C;           /* 0x0202539C */

extern void ReadKeys(void);
extern void WaitForVBlank(void);
extern void sub_08004D1C(u8 a);

u8 sub_08004EA4(void)
{
    u8 unused[0x200];
    u16 v;
    u32 w;
    gUnk_02025248 = 0;
    ReadKeys();
    while (1) {

    if (gKeysPressed & 0xC0)
        gUnk_02025248 ^= 1;
    v = gKeysPressed & 8;
    if (v != 0) {
        gUnk_0202539C = 0;
        sub_08004D1C(3);
        return 0;
    }
    w = gKeysPressed & 1;
    if (w != 0) {
        gUnk_0202539C = v;
        sub_08004D1C(3);
        return gUnk_02025248 + 1;
    }
    if (gKeysPressed & 2) {
        gUnk_0202539C = w;
        sub_08004D1C(3);
        gUnk_02025248 = w;
        return 1;
    }
    sub_08004D1C(gUnk_02025248);
    WaitForVBlank();
        gUnk_0202539C++;
        ReadKeys();
    }
}
