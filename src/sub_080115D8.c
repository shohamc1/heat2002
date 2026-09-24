#include "global.h"

extern u32 gUnk_083FDE18[];

void sub_08006734(u32 a);
u32 GetString(u16 idx);
void sub_080065A8(void);
void DrawTextCenteredHighlight(u32 a, u32 b, u32 c);

void sub_080115D8(u8 a)
{
    u8 b = a;
    u32 v;

    sub_08006734(gUnk_083FDE18[0]);
    GetString(0x5A);
    sub_080065A8();
    v = GetString(0x05);
    DrawTextCenteredHighlight(v, 7, a == 0);
    v = GetString(0x06);
    DrawTextCenteredHighlight(v, 9, a == 1);
    v = GetString(0x07);
    DrawTextCenteredHighlight(v, 0xB, a == 2);
    v = GetString(0x08);
    DrawTextCenteredHighlight(v, 0xD, b == 3);
}
