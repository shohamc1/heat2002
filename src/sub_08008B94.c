#include "global.h"
#include "functions.h"
#include "variables.h"
#include "data.h"

extern u8 gUnk_0806C8E4[];


void sub_08008B94(void)
{
    u32 base;
    u32 *p;

    base = *(u32 *)&gUnk_08364B08;
    p = base + 0x250;
    sub_0800649C(gUnk_0806C8E4, 8, 8);
    /* DrawBigDigit: this file's old prototype took (u32 *, u32); the matched definition takes (u16 *, u8); call through a function pointer with the old signature. */
    ((void (*)(u32 *, u32))DrawBigDigit)(p, 0);
    p = base + 0x254;
    ((void (*)(u32 *, u32))DrawBigDigit)(p, (*(s32 *)&gUnk_0202CAE4));
    p = base + 0x25A;
    ((void (*)(u32 *, u32))DrawBigDigit)(p, (*(s32 *)&gUnk_0202CADC) / 10);
    p = base + 0x25E;
    ((void (*)(u32 *, u32))DrawBigDigit)(p, (*(s32 *)&gUnk_0202CADC) % 10);
    p = base + 0x264;
    ((void (*)(u32 *, u32))DrawBigDigit)(p, (*(s32 *)&gUnk_0202A534) / 100 % 10);
    p = base + 0x268;
    ((void (*)(u32 *, u32))DrawBigDigit)(p, (*(s32 *)&gUnk_0202A534) / 10 % 10);
}
