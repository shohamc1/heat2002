#include "global.h"
#include "functions.h"
#include "variables.h"



u8 PauseMenu(void)
{
    u8 unused[0x200];
    u16 *kp;
    u8 *p248;
    u8 *p39c;
    register u16 k asm("r1");
    u16 t;
    u8 bit1;
    u8 *p248b;

    gUnk_02025248 = 0;
    if (gKeysPressed & 8) {
        sub_08007EF8();
        sub_08004A18();
        StopAllSongs();
        ReadKeys();
        kp = &gKeysPressed;
        p248 = &gUnk_02025248;
        p39c = &gUnk_0202539C;
        while (1) {
            if (*kp & 0xC0)
                *p248 ^= 1;
            k = *(volatile u16 *)kp;
            t = k & 8;
            if (t != 0) {
                *p39c = 0;
                sub_08004C44(3);
                sub_08004A18();
                return 1;
            }
            bit1 = k & 1;
            if (bit1 != 0) {
                *p39c = t;
                sub_08004C44(3);
                p248b = &gUnk_02025248;
                if (*p248b != 0)
                    sub_08004EA4();
                sub_08004A18();
                return (u8)(*p248b + 1);
            }
            if (k & 2) {
                *p39c = bit1;
                sub_08004C44(3);
                *p248 = bit1;
                sub_08004A18();
                return (u8)(*p248 + 1);
            }
            sub_08004C44(*p248);
            WaitForVBlank();
            *p39c = (u8)(*p39c + 1);
            ReadKeys();
        }
    }
    return 0;
}
