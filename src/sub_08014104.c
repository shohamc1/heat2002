#include "global.h"

extern u32 gUnk_083FDE18;
extern u32 sub_08016558(u16 idx);
extern void sub_080065A8(void);
extern void sub_080063BC(u8 *p, u32 a1, u32 a2, u8 a3);
extern u32 sub_0800F110(u8 r0);
extern void sub_08006734(u32 a);
extern u32 gUnk_0202EFC0[];
extern u32 gUnk_0202F020[];
extern u8 gUnk_0202A550[];
extern u8 gUnk_0202539C;
extern u8 gUnk_0829F44C[];
extern u8 gUnk_0829F2AC[];
extern u8 gUnk_0829F440[];
extern u8 gUnk_0829F444[];
extern u8 gUnk_0829F448[];

void sub_08014104(u8 a)
{
    u8 buf[0x28];
    u32 *walk;
    u8 *ptr;
    u16 *t;
    u8 off;
    u8 i;
    u8 z;
    u8 *p;

    off = a * 15;
    sub_08006734(gUnk_083FDE18);
    sub_08016558(0x32);
    sub_080065A8();
    walk = (u32 *)((u8 *)gUnk_0202EFC0 + off * 4);
    i = 0;
    p = buf;
    z = 0;
    do {
        sub_080063BC(gUnk_0829F44C, 1, i + 4, 1);
        if (walk < gUnk_0202F020) {
            ptr = (u8 *)*walk;
            if (ptr == gUnk_0202A550 && (gUnk_0202539C & 0x10) != 0) {
                sub_080063BC(gUnk_0829F2AC, 1, i + 4, 1);
            } else {
                sub_080063BC((u8 *)sub_0800F110(ptr[0x162]), 1, i + 4, 1);
                t = (u16 *)(ptr + 0x164);
                p[0] = (*t / 1000) % 10 + 0x30;
                p[1] = (*t / 100) % 10 + 0x30;
                p[2] = (*t / 10) % 10 + 0x30;
                p[3] = *t % 10 + 0x30;
                p[4] = z;
                sub_080063BC(buf, 0x1A, i + 4, 1);
            }
            walk++;
        }
        i++;
    } while (i != 0x0F);
    gUnk_0202539C++;
    if (gUnk_0202539C & 8) {
        if (a == 0)
            sub_080063BC(gUnk_0829F440, 0x1A, 0x13, 1);
        else
            sub_080063BC(gUnk_0829F444, 0x1A, 0x13, 1);
    } else {
        sub_080063BC(gUnk_0829F448, 0x1A, 0x13, 1);
    }
}
