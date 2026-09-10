#include "global.h"

extern u16 gUnk_0202EF40[];
extern u16 gUnk_020020A0;
extern u8 gUnk_0202EF90;

extern void sub_08011A50(void);
extern void sub_080112E0(void);
extern void sub_08011C9C(u8 a, void *b);
extern void sub_0801137C(void);
extern void sub_08004238(void *a, u32 b);
extern s32 sub_08003330(void);
extern u32 sub_08016558(u16 idx);
extern void sub_08006950(u32 a, u32 b, u32 c);
extern void sub_08000458(void);
extern void sub_0800420C(u32 a, u32 b);

u8 sub_08011528(void)
{
    u8 buf[0x200];
    s8 sel;
    u16 keys;
    u8 v;

    sub_08011A50();
    gUnk_0202EF40[0] = 0;
    gUnk_0202EF40[4] = 0;
    gUnk_0202EF40[8] = 0;
    gUnk_0202EF40[12] = 0;
    v = 0;
    sub_080112E0();
    sub_08011C9C(0, buf);
    sub_0801137C();
    sub_08004238(buf, 0x0F);
    sel = 0x40;
    do
    {
        keys = gUnk_020020A0;
        if (sub_08003330() != 0)
        {
            sel = 5;
        }
        else
        {
            keys = (keys ^ gUnk_020020A0) & gUnk_020020A0;
            sub_0801137C();
            if (gUnk_0202EF90 != 0)
                sub_08006950(sub_08016558(0x58), 0x0E, 1);
            else
                sub_08006950(sub_08016558(0x0F), 0x0E, 1);
            if (keys & 9)
                sel = v;
            sub_08000458();
        }
    } while (sel == 0x40);
    sub_0800420C(0, 0x0F);
    return sel;
}
