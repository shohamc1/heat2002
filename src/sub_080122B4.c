#include "global.h"

extern u16 gKeysPressed;
extern u16 gUnk_020020B8;
extern u8 gUnk_0202EF00[];

extern void sub_08011A50(void);
extern void sub_0800F3A4(void);
extern void sub_0800F4FC(void);
extern void sub_0800F328(u32 a, void *b);
extern void sub_08012228(u8 a);
extern void sub_08004238(void *a, u32 b);
extern void sub_0800048C(void);
extern s8 sub_08012074(void);
extern void sub_08001208(u16 a);
extern void sub_0800420C(u32 a, u32 b);

u8 sub_080122B4(void)
{
    u8 buf[0x200];
    u8 v;
    u8 sel;
    s8 r;

    v = 0;
    sel = 0x40;
    sub_08011A50();
    sub_0800F3A4();
    sub_0800F4FC();
    sub_0800F328(0x082E4328, buf);
    sub_08012228(0);
    sub_08004238(buf, 0x0F);
    gUnk_020020B8 = v;
    do
    {
        sub_0800048C();
        sub_08012228(v);
        r = sub_08012074();
        switch (r)
        {
        case 1:
            sel = 1;
            break;
        case -1:
            sel = 0;
            break;
        }
        if (gKeysPressed & 2)
            sel = 0;
    } while (sel == 0x40);
    if (gUnk_0202EF00[3] != 0)
        sub_08001208(9);
    sub_0800420C(0, 0x0F);
    return sel;
}
