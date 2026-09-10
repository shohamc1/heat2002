#include "global.h"
extern u16 gKeysPressed;
extern void sub_08011C9C(u32 a, void *b);
extern void sub_08014EE8(u8 a);
extern void sub_08004238(void *a, u32 b);
extern void sub_0800048C(void);
extern u8 sub_08011D38(u16 keys, s8 v, u32 lo, u32 hi);
extern void sub_08000458(void);
extern void sub_0800420C(u32 a, u32 b);
u8 sub_08014F5C(void)
{
    u8 buf[0x200];
    s8 v;
    s8 sel;
    v = 0;
    sub_08011C9C(1, buf);
    sub_08014EE8(0);
    sub_08004238(buf, 0x0F);
    sel = 0x40;
    do {
        sub_0800048C();
        sub_08014EE8(v);
        if (gKeysPressed & 1)
            sel = v;
        v = sub_08011D38(gKeysPressed, v, 0, 3);
        sub_08000458();
    } while (sel == 0x40);
    sub_0800420C(0, 0x0F);
    return sel;
}
