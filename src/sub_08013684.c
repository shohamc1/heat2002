#include "global.h"

extern u32 gUnk_083FDE18[];

extern void sub_08006734(u32 a);
extern u32 GetString(u16 idx);
extern void sub_080065A8(void);
extern void DrawTextCenteredHighlight(u32 a, u32 b, u32 c);

void sub_08013684(u8 a)
{
    u8 b = a;
    u32 v;

    sub_08006734(gUnk_083FDE18[0]);
    GetString(0x00);
    sub_080065A8();
    v = GetString(0x01);
    DrawTextCenteredHighlight(v, 6, a == 0);
    v = GetString(0x02);
    DrawTextCenteredHighlight(v, 8, a == 1);
    v = GetString(0x03);
    DrawTextCenteredHighlight(v, 0xA, a == 2);
    v = GetString(0x08);
    DrawTextCenteredHighlight(v, 0xC, b == 3);
}
