#include "global.h"
#include "functions.h"
#include "variables.h"



u8 sub_08005024(void)
{
    u8 unused[0x200];
    u8 *p248;
    u8 *p39c;
    register u16 k asm("r1");
    u16 t;
    u16 t2;
    u8 bit1;
    s32 v;

    gUnk_02025248 = 0;
    ReadKeys();
    sub_08004DB4();
    p248 = &gUnk_02025248;
    p39c = &gUnk_0202539C;
    while ((v = ExchangeLinkInput()) == 0) {
        sub_08004DB4();
        if (gUnk_02025258 & 0xC0)
            *p248 ^= 1;
        k = *(volatile u16 *)&gUnk_02025258;
        t = k & 8;
        if (t != 0) {
            *p39c = v;
            sub_08004D1C(3);
            return 0;
        }
        bit1 = k & 1;
        if (bit1 != 0) {
            *p39c = t;
            sub_08004D1C(3);
            return (u8)(*p248 + 1);
        }
        t2 = k & 2;
        if (t2 != 0) {
            *p39c = bit1;
            sub_08004D1C(3);
            *p248 = bit1;
            return 1;
        }
        sub_08004D1C(*p248);
        gUnk_020020C0 = t2;
spin:
        if (gUnk_020020C0 == 0)
            goto spin;
        *p39c = (u8)(*p39c + 1);
        ReadKeys();
    }
}
