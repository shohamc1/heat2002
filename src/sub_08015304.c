#include "global.h"
extern u32 gUnk_02022DE8;
extern u32 gUnk_02022DE0;
extern u32 gUnk_0200BC2C;
extern u32 gUnk_02022DF8;
extern u32 gUnk_0200BC4C;
extern u32 gUnk_0200BC48;
void sub_08015304(void)
{
    gUnk_0200BC48 = gUnk_0200BC4C = gUnk_02022DF8 = gUnk_0200BC2C = gUnk_02022DE0 =
        gUnk_02022DE8 = 0;
    *(volatile u16 *)0x0400001C = 0;
    *(volatile u16 *)0x0400001E = 0;
    *(volatile u16 *)0x04000018 = 0;
    *(volatile u16 *)0x0400001A = 0;
    *(volatile u16 *)0x04000014 = 0;
    *(volatile u16 *)0x04000016 = 0;
    *(volatile u16 *)0x04000010 = 0;
    *(volatile u16 *)0x04000012 = 0;
}
