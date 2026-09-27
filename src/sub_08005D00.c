#include "global.h"
#include "functions.h"

extern u8 gUnk_0806C770[];
extern u8 gUnk_0806C780[];
extern u32 gUnk_08364B08[];


void DrawLapCounter(s32 a, s32 b)
{
    u8 *q;
    u8 *base;
    u8 *p;

    if (a == 999) {
        q = gUnk_0806C770;
        sub_0800649C((u8 *)((u32)q), 0, 1);
        sub_0800649C((u8 *)((u32)q), 0, 0);
        return;
    }
    if (a > b)
        a = b;
    sub_0800649C((u8 *)((u32)gUnk_0806C780), 0, 1);
    base = (u8 *)gUnk_08364B08[0];
    p = base + 8;
    if (a > 99) {
        DrawBigDigit((u16 *)p, sub_08017230(a, 100));
        p += 4;
        DrawBigDigit((u16 *)p, sub_080172C8(sub_08017230(a, 10), 10));
        p += 4;
        DrawBigDigit((u16 *)p, sub_080172C8(a, 10));
        p += 4;
    } else if (a > 9) {
        DrawBigDigit((u16 *)p, sub_080172C8(sub_08017230(a, 10), 10));
        p = base + 12;
        DrawBigDigit((u16 *)p, sub_080172C8(a, 10));
        p += 4;
    } else {
        DrawBigDigit((u16 *)p, sub_080172C8(a, 10));
        p = base + 12;
    }
    p += 0x40;
    DrawSmallDigit((u16 *)p, 11);
    p += 2;
    if (b > 99) {
        DrawSmallDigit((u16 *)p, sub_08017230(b, 100));
        p += 2;
        DrawSmallDigit((u16 *)p, sub_080172C8(sub_08017230(b, 10), 10));
        p += 2;
        DrawSmallDigit((u16 *)p, sub_080172C8(b, 10));
    } else if (b > 9) {
        DrawSmallDigit((u16 *)p, sub_080172C8(sub_08017230(b, 10), 10));
        p += 2;
        DrawSmallDigit((u16 *)p, sub_080172C8(b, 10));
    } else {
        DrawSmallDigit((u16 *)p, sub_080172C8(b, 10));
    }
}
