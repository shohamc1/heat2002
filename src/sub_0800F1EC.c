#include "global.h"

extern u32 gUnk_0829EF40[];
extern u32 gUnk_0829EF50[];
extern u32 gUnk_0829EF64[];

void sub_080065A8(u32 a);
void DrawTextCenteredHighlight(u32 a, u32 b, u32 c);

void sub_0800F1EC(u8 a)
{
    u32 p;

    sub_080065A8((u32)gUnk_0829EF40);
    p = (u32)gUnk_0829EF50;
    DrawTextCenteredHighlight(p, 8, a == 0);
    p = (u32)gUnk_0829EF64;
    DrawTextCenteredHighlight(p, 0xA, a == 1);
}
