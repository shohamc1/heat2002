#include "global.h"

extern u8 gUnk_0202525C[];
extern s32 gUnk_0202521C;
extern u32 gUnk_08364B08[];
extern s32 gUnk_020253C0;

extern void DrawBigDigit(u8 *a, u8 b);
extern void DrawSmallDigit(u16 *dest, u8 idx);
extern s32 sub_08017230(s32 a, s32 b);
extern s32 sub_080172C8(s32 a, s32 b);

void sub_080059A8(void)
{
    u8 *d;
    s32 v;
    s32 w;

    d = gUnk_0202525C;
    v = gUnk_0202521C;
    d[1] = sub_080172C8(v, 10);
    d[0] = sub_08017230(v, 10);
    DrawBigDigit((u8 *)(gUnk_08364B08[0] + 0x82), d[0]);
    DrawBigDigit((u8 *)(gUnk_08364B08[0] + 0x86), d[1]);
    w = gUnk_020253C0;
    d[1] = sub_080172C8(sub_08017230(w, 10), 10);
    d[0] = sub_08017230(w, 100);
    DrawSmallDigit((u16 *)((u8 *)(gUnk_08364B08[0] + 0xCA)), 10);
    DrawSmallDigit((u16 *)((u8 *)(gUnk_08364B08[0] + 0xCC)), d[0]);
    DrawSmallDigit((u16 *)((u8 *)(gUnk_08364B08[0] + 0xCE)), d[1]);
}
