#include "global.h"
extern u16 gKeysPressed;
extern void sub_08011C9C(u32 a, void *b);
extern void sub_08012984(u8 a);
extern void sub_08004238(void *a, u32 b);
extern void sub_0800048C(void);
extern void sub_08000458(void);
extern void sub_0800420C(u32 a, u32 b);
u8 sub_080129E8(u8 arg)
{
    u8 buf[0x200];
    s8 sel;
    /* Keep this signed-byte local: its allocation reproduces the saved registers. */
    s8 v = 0;
    sub_08011C9C(3, buf);
    sub_08012984(arg);
    sub_08004238(buf, 0x0F);
    sel = 0x40;
    do {
        sub_0800048C();
        sub_08012984(arg);
        if (gKeysPressed & 1)
            sel = v;
        sub_08000458();
    } while (sel != 0);
    sub_0800420C(0, 0x0F);
    return sel;
}
