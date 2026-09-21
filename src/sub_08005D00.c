#include "global.h"

extern u8 gUnk_0806C770[];
extern u8 gUnk_0806C780[];
extern u32 gUnk_08364B08[];

extern void sub_0800649C(u32 a, u32 b, u32 c);
extern void sub_08005870(u8 *a, u8 b);
extern void sub_080058CC(u8 *a, u8 b);
extern s32 sub_08017230(s32 a, s32 b);
extern s32 sub_080172C8(s32 a, s32 b);

void sub_08005D00(s32 a, s32 b)
{
    u8 *q;
    u8 *base;
    u8 *p;

    if (a == 999) {
        q = gUnk_0806C770;
        sub_0800649C((u32)q, 0, 1);
        sub_0800649C((u32)q, 0, 0);
        return;
    }
    if (a > b)
        a = b;
    sub_0800649C((u32)gUnk_0806C780, 0, 1);
    base = (u8 *)gUnk_08364B08[0];
    p = base + 8;
    if (a > 99) {
        sub_08005870(p, sub_08017230(a, 100));
        p += 4;
        sub_08005870(p, sub_080172C8(sub_08017230(a, 10), 10));
        p += 4;
        sub_08005870(p, sub_080172C8(a, 10));
        p += 4;
    } else if (a > 9) {
        sub_08005870(p, sub_080172C8(sub_08017230(a, 10), 10));
        p = base + 12;
        sub_08005870(p, sub_080172C8(a, 10));
        p += 4;
    } else {
        sub_08005870(p, sub_080172C8(a, 10));
        p = base + 12;
    }
    p += 0x40;
    sub_080058CC(p, 11);
    p += 2;
    if (b > 99) {
        sub_080058CC(p, sub_08017230(b, 100));
        p += 2;
        sub_080058CC(p, sub_080172C8(sub_08017230(b, 10), 10));
        p += 2;
        sub_080058CC(p, sub_080172C8(b, 10));
    } else if (b > 9) {
        sub_080058CC(p, sub_080172C8(sub_08017230(b, 10), 10));
        p += 2;
        sub_080058CC(p, sub_080172C8(b, 10));
    } else {
        sub_080058CC(p, sub_080172C8(b, 10));
    }
}
