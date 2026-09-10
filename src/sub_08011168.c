#include "global.h"
extern u16 gKeysPressed;
extern volatile u8 gUnk_020020C0;
extern u8 gUnk_0202EED8;
extern u8 gUnk_0202EF00[];
extern u8 gUnk_0202EF8C;
extern void sub_080045D8(void);
extern void sub_08007344(void);
extern void sub_080073D8(void);
extern void sub_08004484(void);
extern void sub_080047DC(void);
extern void sub_08000458(void);
extern void sub_0800F3A4(void);
extern void sub_0800F4FC(void);
extern void sub_0800F328(u32 a, void *b);
extern void sub_08010FE4(u8 a, u8 b);
extern void sub_08004238(void *a, u32 b);
extern void sub_0800048C(void);
extern u8 sub_08011EE8(u16 keys, s8 v, u32 lo, u32 hi);
extern void sub_08001208(u16 a);
extern void sub_0800420C(u32 a, u32 b);

u8 sub_08011168(u8 a, u8 b)
{
    u8 buf[0x200];
    s8 v;
    s8 sel;

    v = 0;
    if (a == 0)
        v = b;
    gUnk_0202EED8 = 0;
    sub_080045D8();
    sub_08007344();
    sub_080073D8();
    sub_08004484();
    sub_080047DC();
    gUnk_020020C0 = 0;
    sub_08000458();
    sub_0800F3A4();
    sub_0800F4FC();
    sub_0800F328(0x082E4328, buf);
    sub_08010FE4(v, a);
    sub_08004238(buf, 0x0F);
    *(volatile u16 *)(0x80 << 19) = 0xA8 << 3;
    sub_08000458();
    *(volatile u16 *)(0x80 << 19) = 0xAA << 5;
    sel = 0x40;
    do {
        sub_08004484();
        sub_08010FE4(v, a);
        sub_0800048C();
        if (((gKeysPressed & 1) && a == 1)
            || (a == 0 && gUnk_0202EED8 == 0x20))
            sel = v;
        if (a != 0)
            v = sub_08011EE8(gKeysPressed, v, 0, 0x0B);
        if (v == 7) {
            if (gKeysPressed & 0x20)
                v = 6;
            if (gKeysPressed & 0x10)
                v = 8;
        }
        gUnk_0202EF8C = v;
        if ((gKeysPressed & 2) && a != 0)
            sel = 0;
        sub_080047DC();
        gUnk_020020C0 = 0;
    spin:
        if (gUnk_020020C0 == 0)
            goto spin;
        sub_08000458();
        sub_08000458();
    } while (sel == 0x40);
    sub_08000458();
    *(volatile u16 *)(0x80 << 19) = 0xA8 << 3;
    sub_08000458();
    if (gUnk_0202EF00[3] != 0)
        sub_08001208(9);
    sub_0800420C(0, 0x0F);
    return sel != 0 ? v : 0;
}
