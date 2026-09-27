#include "global.h"
#include "functions.h"
#include "variables.h"



u8 sub_080050F0(void)
{
    u8 unused[0x200];
    u8 *sel;
    u8 *v;
    u16 a;
    u32 b;
    u16 c;
    u32 r;

    gUnk_020253C4 = 0xFF;
    gUnk_02025248 = 0;
    sub_08004DB4();
    if ((gUnk_02025258 & 8) != 0) {
        StopAllSongs();
        sel = &gUnk_02025248;
        v = &gUnk_0202539C;
        while ((r = ExchangeLinkInput()) == 0) {
            sub_08004DB4();
            if ((gUnk_02025258 & 0xC0) != 0)
                *sel ^= 1;
            a = gUnk_02025258 & 8;
            if (a != 0) {
                *v = r;
                sub_08004C44(3);
                return 1;
            }
            b = gUnk_02025258 & 1;
            if (b != 0) {
                *v = a;
                sub_08004C44(3);
                if (gUnk_02025248 != 0)
                    sub_08005024();
                return (u8)(gUnk_02025248 + 1);
            }
            c = gUnk_02025258 & 2;
            if (c != 0) {
                *v = b;
                sub_08004C44(3);
                *sel = b;
                return 1;
            }
            sub_08004C44(*sel);
            *v = *v + 1;
            gUnk_020020C0 = c;
poll:
            if (gUnk_020020C0 == 0)
                goto poll;
        }
    }
    return 0;
}
