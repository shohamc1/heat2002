#include "global.h"
#include "functions.h"
#include "data.h"

extern u8 gUnk_0806C8EC[];


void sub_08008C48(s32 x)
{
    u32 *base;
    u32 *p;
    u32 s;

    base = (u32 *)*(u32 *)&gTextLayerMapPtr;
    p = base + 0xE5;
    /* DrawBigDigit: this file's old prototype took (u32 *, u32); the matched definition takes (u16 *, u8); call through a function pointer with the old signature. */
    ((void (*)(u32 *, u32))DrawBigDigit)(p, x / 100 % 10);
    p = base + 0xE6;
    ((void (*)(u32 *, u32))DrawBigDigit)(p, x / 10 % 10);
    p = base + 0xE7;
    ((void (*)(u32 *, u32))DrawBigDigit)(p, x % 10);
    s = (u32)gUnk_0806C8EC;
    sub_0800649C((u8 *)s, 0x10, 0x0F);
}
