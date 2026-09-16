#include "global.h"

extern u16 gKeysPressed;
extern u8 gUnk_082EE104[];

extern void sub_0800F3A4(void);
extern void sub_0800F498(void);
extern void sub_0800F328(void *a, void *b);
extern void sub_080127E4(u8 a);
extern void sub_08004238(void *a, u32 b);
extern void sub_0800048C(void);
extern void sub_08000458(void);
extern void sub_0800420C(u32 a, u32 b);

void sub_08012874(s8 a)
{
    void *p;
    u8 buf[0x200];
    s8 sel;

    sub_0800F3A4();
    sub_0800F498();
    p = gUnk_082EE104;
    sub_0800F328(p, buf);
    sub_080127E4(a);
    sub_08004238(buf, 0x0F);
    sel = 0x40;
    do {
        sub_0800048C();
        sub_080127E4(a);
        if (gKeysPressed & 1)
            sel = a;
        sub_08000458();
    } while (sel == 0x40);
    sub_0800420C(0, 0x0F);
}
