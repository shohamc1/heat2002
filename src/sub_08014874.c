#include "global.h"
extern u16 gKeysPressed;
extern u8 gUnk_0202EF00[];
extern s8 gUnk_0202EF60[];
extern void sub_08011C9C(u32 a, void *b);
extern void sub_08014708(u8 a, u8 b);
extern void sub_08004238(void *a, u32 b);
extern void sub_0800048C(void);
extern u8 sub_08011D38(u16 keys, s8 v, s16 lo, s16 hi);
extern void sub_08000458(void);
extern void sub_08001208(u16 a);
extern void sub_0800420C(u32 a, u32 b);
u8 sub_08014874(u8 a, u8 b)
{
    u8 buf[0x200];
    s8 v;
    s32 sel;
    v = b;
    sub_08011C9C(5, buf);
    sub_08014708(a, v);
    sub_08004238(buf, 0x0F);
    sel = 0x40;
    do {
        sub_0800048C();
        sub_08014708(a, v);
    retry:
        v = sub_08011D38(gKeysPressed, v, (b >> 2) * 4, (b >> 2) * 4 + 3);
        if (gUnk_0202EF60[v] == -1)
            goto retry;
        if (gKeysPressed & 3)
            sel = 1;
        sub_08000458();
    } while (sel == 0x40);
    if (gUnk_0202EF00[3])
        sub_08001208(9);
    sub_0800420C(0, 0x0F);
    return v;
}
