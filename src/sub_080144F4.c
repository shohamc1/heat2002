#include "global.h"
extern u16 gKeysPressed;
extern u8 gUnk_0202EF00[];
extern void sub_08011C9C(u32 a, void *b);
extern void sub_08014480(u8 a);
extern void sub_08004238(void *a, u32 b);
extern void sub_0800048C(void);
extern u8 sub_08011D38(u16 keys, s8 v, u32 lo, u32 hi);
extern void sub_08000458(void);
extern void sub_08001208(u16 a);
extern void sub_0800420C(u32 a, u32 b);
u8 sub_080144F4(void)
{
    u8 buf[0x200];
    s8 v;
    s8 sel;
    v = 0;
    sub_08011C9C(2, buf);
    sub_08014480(0);
    sub_08004238(buf, 0x0F);
    sel = 0x40;
    do {
        sub_0800048C();
        sub_08014480(v);
        if (gKeysPressed & 1)
            sel = v;
        if (gKeysPressed & 2)
            sel = 0x0A;
        v = sub_08011D38(gKeysPressed, v, 0, 3);
        sub_08000458();
    } while (sel == 0x40);
    if (gUnk_0202EF00[3] != 0)
        sub_08001208(9);
    sub_0800420C(0, 0x0F);
    return sel;
}
