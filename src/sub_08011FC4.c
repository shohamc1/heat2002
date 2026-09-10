#include "global.h"
extern u16 gKeysPressed;
extern u8 gUnk_0202EF00[];
extern void sub_08011C9C(u32 a, void *b);
extern void sub_08011F78(s32 a);
extern void sub_08004238(void *a, u32 b);
extern void sub_0800048C(void);
extern void sub_08000458(void);
extern void sub_08001208(u16 a);
extern void sub_0800420C(u32 a, u32 b);
s8 sub_08011FC4(void)
{
    u8 buf[0x200];
    s32 a;
    s8 b;
    a = 0;
    b = 0;
    sub_08011C9C(4, buf);
    sub_08011F78(0);
    sub_08004238(buf, 0x0F);
    do {
        sub_0800048C();
        sub_08011F78(a);
        if (gKeysPressed & 0xC0) {
            a ^= 1;
            if (gUnk_0202EF00[3])
                sub_08001208(8);
        }
        if (gKeysPressed & 2)
            b = -1;
        if (gKeysPressed & 9) {
            b = a + 1;
            if (gUnk_0202EF00[3])
                sub_08001208(9);
        }
        sub_08000458();
    } while (b == 0);
    if (gUnk_0202EF00[3])
        sub_08001208(9);
    sub_0800420C(0, 0x0F);
    return b;
}
