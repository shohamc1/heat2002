#include "global.h"

struct Car137C {
    u8 pad[0x16C];
    u32 unk16C;
    u8 pad2[0x190 - 0x170];
};

extern struct Car137C gUnk_0202A550[];
extern struct Car137C *gUnk_0202EFC0[];
extern u32 gUnk_083FDE18[];
extern u8 gUnk_0202EF90[];
extern u8 gUnk_020020AC[];
extern u8 gUnk_0202539C;
extern u8 gUnk_0829F2F0[];

extern void sub_08006734(u32 a);
extern u32 sub_08016558(u32 idx);
extern void sub_080065A8(void);
extern void sub_08016C50(u32 a, u16 *b, u16 *c, u16 *d);
extern void sub_080063BC(u8 *p, u32 a1, u32 a2, u8 a3);

void sub_0801137C(void)
{
    u8 buf[0x28];
    u16 q1, q2, q3;
    struct Car137C **p;
    struct Car137C *car;
    u8 i;
    u16 tile;

    sub_08006734(gUnk_083FDE18[0]);
    sub_08016558(0x5B);
    sub_080065A8();
    p = gUnk_0202EFC0;
    for (i = 0; i != gUnk_020020AC[0]; i++) {
        car = *p;
        sub_08016C50(car->unk16C, &q1, &q2, &q3);
        if (car == &gUnk_0202A550[gUnk_0202EF90[0]] && (gUnk_0202539C & 0x10)) {
            sub_080063BC(gUnk_0829F2F0, 4, 2 * i + 4, 1);
        } else {
            sub_080063BC(sub_08016558(i + 0xC0), 1, 2 * i + 4, 1);
            tile = 0x53 + (car - gUnk_0202A550);
            sub_080063BC(sub_08016558(tile), 6, 2 * i + 4, 1);
            buf[0] = (u16)(q1 / 10) % 10 + 0x30;
            buf[1] = q1 % 10 + 0x30;
            buf[2] = 0x3A;
            buf[3] = (u16)(q2 / 10) % 10 + 0x30;
            buf[4] = q2 % 10 + 0x30;
            buf[5] = 0x3A;
            buf[6] = (u16)(q3 / 100) % 10 + 0x30;
            buf[7] = (u16)(q3 / 10) % 10 + 0x30;
            buf[8] = 0;
            sub_080063BC(buf, 0x12, 2 * i + 4, 1);
        }
        p++;
    }
    gUnk_0202539C++;
}
