#include "global.h"

extern u32 gUnk_083FDE18[];
extern u8 gUnk_0202EF78[];
extern u8 gUnk_0202EEB4;
extern u8 gUnk_0202EDB0;
extern u8 gUnk_0829F2AC[];

void sub_08006734(u32 r0);
u32 sub_08016558(u32 a);
void sub_080065A8(void);
void sub_080064F8(u32 r0, u32 r1, u32 r2, u32 r3);
void sub_08006950(u32 a, u32 b, u32 c);
void sub_080063BC(u32 r0, u32 r1, u32 r2, u32 r3);

void sub_080131F8(u8 arg)
{
    u8 buf[0x12];
    u8 *p;

    p = &buf[0x10];
    p[1] = 0;
    sub_08006734(gUnk_083FDE18[0]);
    sub_08016558(0x6B);
    sub_080065A8();
    p[0] = (gUnk_0202EF78[0] << 1) - 0x80;
    sub_080064F8((u32)p, 4, 7, arg == 0);
    p[0] = (gUnk_0202EF78[1] << 1) - 0x80;
    sub_080064F8((u32)p, 9, 7, arg == 1);
    p[0] = (gUnk_0202EF78[2] << 1) - 0x80;
    sub_080064F8((u32)p, 0xE, 7, arg == 2);
    p[0] = (gUnk_0202EF78[3] << 1) - 0x80;
    sub_080064F8((u32)p, 0x13, 7, arg == 3);
    p[0] = (gUnk_0202EF78[4] << 1) - 0x80;
    sub_080064F8((u32)p, 0x18, 7, arg == 4);
    if (gUnk_0202EEB4 != 0) {
        if (gUnk_0202EEB4 & 0x10) {
            sub_08006950(sub_08016558((u32)(gUnk_0202EDB0 + 0x6C)), 0xF, 1);
        } else {
            sub_080063BC((u32)gUnk_0829F2AC, 0, 0xF, 0);
        }
        gUnk_0202EEB4--;
    }
}
