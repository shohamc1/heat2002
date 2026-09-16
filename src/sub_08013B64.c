#include "global.h"

extern u32 gUnk_083FDE18;
extern u32 sub_08016558(u16 idx);
extern void sub_080065A8(void);
extern void sub_080063BC(u8 *p, u32 a1, u32 a2, u8 a3);
extern u32 sub_0800F110(u8 r0);
extern void sub_08006734(u32 a);
extern void sub_08016C50(u32 a, u16 *b, u16 *c, u16 *d);
extern u32 gUnk_0202EFC0[];
extern u32 gUnk_0202F020[];
extern u8 gUnk_0202A550[];
extern u8 gUnk_0202539C;
extern u8 gUnk_0829F41C[];
extern u8 gUnk_0829F440[];
extern u8 gUnk_0829F444[];
extern u8 gUnk_0829F448[];

void sub_08013B64(u8 a)
{
    u8 buf[0x28];
    u16 m, s, f;
    u8 i;
        u32 *walk;
        u8 *ptr;
        u8 off;

    off = a * 15;
    sub_08006734(gUnk_083FDE18);
    sub_08016558(0x31);
    sub_080065A8();
    walk = (u32 *)((u8 *)gUnk_0202EFC0 + off * 4);
    i = 0;
    do {
        ptr = (u8 *)*walk;
        sub_080063BC(gUnk_0829F41C, 0, i + 4, 1);
        if (walk < gUnk_0202F020) {
            sub_08016C50(*(u32 *)(ptr + 0x16C), &m, &s, &f);
            if (ptr != gUnk_0202A550 || (gUnk_0202539C & 0x10) == 0) {
                buf[0] = ((i + off + 1) / 10) % 10 + 0x30;
                buf[1] = (i + off + 1) % 10 + 0x30;
                buf[2] = 0x2E;
                buf[3] = 0;
                sub_080063BC(buf, 0, i + 4, 1);
                sub_080063BC((u8 *)sub_0800F110(ptr[0x162]), 3, i + 4, 1);
                buf[0] = (m / 10) % 10 + 0x30;
                buf[1] = m % 10 + 0x30;
                buf[2] = 0x3A;
                buf[3] = (s / 10) % 10 + 0x30;
                buf[4] = s % 10 + 0x30;
                buf[5] = 0x3A;
                buf[6] = (f / 100) % 10 + 0x30;
                buf[7] = (f / 10) % 10 + 0x30;
                buf[8] = 0;
                sub_080063BC(buf, 0x16, i + 4, 1);
            }
            walk++;
        }
        i++;
    } while (i != 0x0F);
    if ((gUnk_0202539C & 8) != 0) {
        if (a == 0)
            sub_080063BC(gUnk_0829F440, 0x1A, 0x13, 1);
        else
            sub_080063BC(gUnk_0829F444, 0x1A, 0x13, 1);
    } else {
        sub_080063BC(gUnk_0829F448, 0x1A, 0x13, 1);
    }
    gUnk_0202539C++;
}
