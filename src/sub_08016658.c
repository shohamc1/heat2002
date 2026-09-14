#include "global.h"

extern u8 gUnk_0202F020;
extern u8 gUnk_0202F024;
extern u8 gUnk_0202EEC8;
extern u8 gUnk_0202F034;
extern u8 gUnk_0202EDD8;
extern u16 gUnk_0202F04A[];
extern u8 gUnk_0202EF10;
extern u8 gUnk_0202EF20[];
extern void sub_08010074(void);
extern void sub_0801659C(u32 a, u32 b);
extern void sub_080100B0(void);

struct Car {
    u8 filler0[0x162];
    u8 unk162;
    u16 unk164;
    u8 filler166[0x16C - 0x166];
    u32 unk16C;
    u8 filler170[400 - 0x170];
};
extern struct Car gUnk_0202A550[];

void sub_08016658(void)
{
    u16 *p;
    s32 i;
    struct Car *q;
    u32 t;

    sub_08010074();
    p = gUnk_0202F04A;
    *p = 1;
    p += 27;
    *p++ = gUnk_0202F020;
    *p++ = (gUnk_0202F024 << 8) | gUnk_0202EEC8;
    *p++ = gUnk_0202F034;
    *p++ = gUnk_0202EDD8;
    q = gUnk_0202A550;
    i = 0;
    do {
        *p++ = q->unk162;
        *p++ = q->unk164;
        t = q->unk16C;
        *p++ = t >> 16;
        *p++ = t;
        i++;
        q++;
    } while (i != 0x18);
    i = 0;
    do {
        *p++ = gUnk_0202EF20[i];
        i++;
    } while (i != 0x11);
    *p = gUnk_0202EF10;
    sub_0801659C(0x40, 0xF0);
    sub_0801659C(8, 8);
    sub_080100B0();
}
