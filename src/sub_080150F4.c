#include "global.h"

extern u32 gUnk_083FDE18;
extern u32 GetString(u16 idx);
extern void sub_080065A8(void);
extern void DrawText(u8 *p, u32 a1, u32 a2, u8 a3);
extern u32 GetDriverName(u8 r0);
extern void sub_08006734(u32 a);
extern void SplitMilliseconds(u32 a, u16 *b, u16 *c, u16 *d);
extern u32 gCarOrder[];
extern u8 gCars[];
extern u8 gUnk_0202539C;
extern u8 gUnk_0829F44C[];

void sub_080150F4(void)
{
    u8 buf[0x28];
    u16 m, s, f;
    u32 *walk;
    u8 *ptr;
    u16 *pm, *ps, *pf;
    u8 i;

    sub_08006734(gUnk_083FDE18);
    GetString(0x10);
    sub_080065A8();
    walk = gCarOrder;
    i = 0;
    pm = &m;
    ps = &s;
    pf = &f;
    do {
        ptr = (u8 *)*walk;
        SplitMilliseconds(*(u32 *)(ptr + 0x16C), pm, ps, pf);
        if (ptr == gCars && (gUnk_0202539C & 0x10) != 0) {
            DrawText(gUnk_0829F44C, 1, i + 4, 1);
        } else {
            DrawText((u8 *)GetDriverName(ptr[0x162]), 1, i + 4, 1);
            buf[0] = (m / 10) % 10 + 0x30;
            buf[1] = m % 10 + 0x30;
            buf[2] = 0x3A;
            buf[3] = (s / 10) % 10 + 0x30;
            buf[4] = s % 10 + 0x30;
            buf[5] = 0x3A;
            buf[6] = (*pf / 100) % 10 + 0x30;
            buf[7] = (*pf / 10) % 10 + 0x30;
            buf[8] = 0;
            DrawText(buf, 0x14, i + 4, 1);
        }
        walk++;
        i++;
    } while (i != 0x18);
    gUnk_0202539C++;
}
