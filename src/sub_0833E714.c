#include "global.h"
extern u8 gUnk_0203916C;
extern u32 gUnk_020251B8[];
extern u8 gUnk_0200CF70[];
void sub_0833EF0C(u32,u32,u32);
void sub_0833E36C(u32,u8);
void sub_0833E714(s32 arg)
{
    u16 *q;
    u16 *p;
    if (gUnk_0203916C == 0x0A || gUnk_0203916C == 0x02)
        return;
    if (arg == 0x64 || gUnk_0203916C == 5) {
        p = (u16 *)gUnk_020251B8[0];
        p[0x16] = 0xE047;
        p[0x17] = 0xE047;
        p[0x18] = 0xE047;
        p[0x19] = 0xE047;
        p[0x1A] = 0xE047;
        p[0x1B] = 0xE047;
        p[0x1C] = 0xE047;
        p[0x1D] = 0xE047;
        q = p + 0x36;
        *q++ = 0xE047;
        *q++ = 0xE047;
        *q++ = 0xE047;
        *q++ = 0xE047;
        *q++ = 0xE047;
        *q++ = 0xE047;
        *q++ = 0xE047;
        *q = 0xE047;
        return;
    }
    sub_0833EF0C((u32)gUnk_0200CF70, 0x16, 0);
    if (arg <= 9) {
        register u16 *w asm("r0");
        p = (u16 *)gUnk_020251B8[0];
        p[0x1C] = 0xE047;
        p[0x1D] = 0xE047;
        w = p + 0x3C;
        *w++ = 0xE047;
        *w = 0xE047;
        w -= 0x23;
        sub_0833E36C((u32)w, (u8)arg);
    } else if (arg <= 0x13) {
        sub_0833E36C(gUnk_020251B8[0] + 0x34, 1);
        sub_0833E36C(gUnk_020251B8[0] + 0x38, (u8)(arg - 0x0A));
    } else {
        sub_0833E36C(gUnk_020251B8[0] + 0x34, 2);
        sub_0833E36C(gUnk_020251B8[0] + 0x38, (u8)(arg - 0x14));
    }
}
