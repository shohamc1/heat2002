#include "global.h"
extern u16 gKeysPressed;
extern void sub_08011C9C(u32 a, void *b);
extern void sub_08012AF8(u8 a, u8 b);
extern void sub_08004238(void *a, u32 b);
extern void sub_0800048C(void);
extern void sub_08000458(void);
extern void sub_0800420C(u32 a, u32 b);
u8 sub_08012B50(u8 a, u8 b)
{
    u8 buf[0x200];
    s8 sel;
    /* The signed local keeps the parameter conversions in ROM order. */
    s8 v = a;
    sub_08011C9C(3, buf);
    sub_08012AF8(v, b);
    sub_08004238(buf, 0x0F);
    sel = 0x40;
    do {
        sub_0800048C();
        sub_08012AF8(v, b);
        if (gKeysPressed & 1)
            sel = v;
        sub_08000458();
    } while (sel == 0x40);
    sub_0800420C(0, 0x0F);
    return sel;
}
