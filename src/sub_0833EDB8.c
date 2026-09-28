#include "global.h"
#include "functions.h"
#include "variables.h"

extern u8 gModule_TimeLabel[];

void *sub_0833FF44(void);
void sub_0833FF94(u32 r0);
void sub_0833ED10(void);
void sub_0833E0AC(void);
void sub_0833EB90(void);

void sub_0833EDB8(void)
{
    void *p;

    if (gModule_IsDemo[0] != 0)
        return;
    p = sub_0833FF44();
    if (p != 0)
    {
        *(u32 *)((u32)p + 0x0C) = (u32)sub_0833EB90;
        sub_0833FF94((u32)p);
    }
    sub_0833ED10();
    sub_0833EF0C((u8 *)((u32)gModule_TimeLabel), 0, 0x13);
    sub_0833E0AC();
}
