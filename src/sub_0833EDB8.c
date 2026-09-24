#include "global.h"

extern u8 gUnk_020390F0[];
extern u8 gUnk_0200CF88[];

void *sub_0833FF44(void);
void sub_0833FF94(u32 r0);
void sub_0833ED10(void);
void sub_0833EF0C(u32 r0, u32 r1, u32 r2);
void sub_0833E0AC(void);
void sub_0833EB90(void);

void sub_0833EDB8(void)
{
    void *p;

    if (gUnk_020390F0[0] != 0)
        return;
    p = sub_0833FF44();
    if (p != 0)
    {
        *(u32 *)((u32)p + 0x0C) = (u32)sub_0833EB90;
        sub_0833FF94((u32)p);
    }
    sub_0833ED10();
    sub_0833EF0C((u32)gUnk_0200CF88, 0, 0x13);
    sub_0833E0AC();
}
