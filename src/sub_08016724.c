#include "global.h"
struct Unk_0202A550 {
    u8 filler0[0x162];
    u8 unk162;
    u8 filler163;
    u16 unk164;
    u8 filler166[6];
    u32 unk16C;
    u8 filler170[400 - 0x170];
};
extern struct Unk_0202A550 gUnk_0202A550[];
extern u16 gUnk_0202F080[];
extern u8 gUnk_0202F020;
extern u8 gUnk_0202F024;
extern u8 gUnk_0202EEC8;
extern u8 gUnk_0202F034;
extern u8 gUnk_0202EDD8;
extern u8 gUnk_0202EF10;
extern u8 gUnk_0202EF20[];
extern void sub_08010074(void);
extern void sub_080165E0(u32 a, u32 b);
extern void sub_080100B0(void);
void sub_08016724(void)
{
    struct Unk_0202A550 *q;
    u16 *p;
    u32 t;
    s32 i;
    sub_08010074();
    sub_080165E0(0x40, 0xF0);
    p = gUnk_0202F080;
    gUnk_0202F020 = *p++;
    gUnk_0202F024 = *p >> 8;
    gUnk_0202EEC8 = *p++;
    gUnk_0202F034 = *p++;
    gUnk_0202EDD8 = *p++;
    q = gUnk_0202A550;
    i = 0;
    do {
        q->unk162 = *p++;
        q->unk164 = *p++;
        q->unk16C = (*p++ << 16);
        q->unk16C |= *p++;
        i++;
        q++;
    } while (i != 0x18);
    i = 0;
    do {
        gUnk_0202EF20[i] = *p++;
        i++;
    } while (i != 0x11);
    gUnk_0202EF10 = *p;
    sub_080100B0();
}
