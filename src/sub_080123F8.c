#include "global.h"

extern u32 gUnk_083FDE18[];
extern u8 gUnk_0829F354[];
extern u8 gUnk_0829F368[];
extern u8 gUnk_0202EF00[];

extern void sub_08006734(u32 a);
extern u32 sub_08016558(u32 idx);
extern void sub_080065A8(void);
extern void sub_080063BC(u8 *p, u32 a1, u32 a2, u8 a3);

void sub_080123F8(u32 a)
{
    u8 *p;

    sub_08006734(gUnk_083FDE18[0]);
    sub_08016558(0x34);
    sub_080065A8();

    sub_080063BC(sub_08016558(0x35), 3, 5, a == 0);

    sub_080063BC(sub_08016558(0x38), 3, 7, a == 1);

    sub_080063BC(sub_08016558(0x3A), 3, 9, a == 2);

    sub_080063BC(sub_08016558(0x3B), 3, 0xB, a == 3);

    sub_080063BC(sub_08016558(0xBF), 3, 0xD, a == 4);
    p = gUnk_0829F354;
    sub_080063BC(p, 3, 0xF, a == 5);
    p = gUnk_0829F368;
    sub_080063BC(p, 0x15, 5, a == 0);
    sub_080063BC(sub_08016558(gUnk_0202EF00[0] + 0x3D), 0x15, 5, a == 0);
    sub_080063BC(sub_08016558(gUnk_0202EF00[1] + 0xB6), 0x15, 7, a == 1);
    sub_080063BC(sub_08016558(gUnk_0202EF00[2] + 0x41), 0x15, 9, a == 2);
    sub_080063BC(sub_08016558(gUnk_0202EF00[3] + 0x41), 0x15, 0xB, a == 3);
    sub_080063BC(sub_08016558(gUnk_0202EF00[4] + 0x41), 0x15, 0xD, a == 4);
}
