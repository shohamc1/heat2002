#include "global.h"

extern u16 gUnk_020020A0;

extern void sub_08011A50(void);
extern void sub_08011C9C(u8 a, void *b);
extern void sub_080115D8(u8 a);
extern void sub_08004238(void *a, u32 b);
extern s32 sub_08003330(void);
extern u8 sub_08011D38(u16 keys, s8 v, u32 lo, u32 hi);
extern void sub_08000458(void);
extern void sub_0800420C(u32 a, u32 b);

u8 sub_0801164C(void)
{
    u8 buf[0x200];
    s8 sel;
    s8 v;
    u16 old;
    u16 keys;

    sub_08011A50();
    v = 0;
    sub_08011C9C(1, buf);
    sub_080115D8(0);
    sub_08004238(buf, 0x0F);
    sel = 0x40;
    do
    {
        old = gUnk_020020A0;
        if (sub_08003330() != 0)
        {
            sel = 5;
        }
        else
        {
            keys = (gUnk_020020A0 ^ old) & gUnk_020020A0;
            if (keys & 9)
                sel = v;
            v = sub_08011D38(keys, v, 0, 3);
            sub_080115D8(v);
            sub_08000458();
        }
    } while (sel == 0x40);
    sub_0800420C(0, 0x0F);
    return sel;
}
