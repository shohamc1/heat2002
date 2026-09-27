#include "global.h"

extern u32 gUnk_083FDE18[];
extern u8 gUnk_0829F3BC[];

extern void sub_08006734(u32 a);
extern u32 GetString(u16 idx);
extern void sub_080065A8(void);
extern void DrawTextCenteredHighlight(u8 *p, u32 a1, u8 a2);

void sub_080134E8(u8 a)
{
    u8 b = a;
    u32 v;

    sub_08006734(gUnk_083FDE18[0]);
    GetString(0x00);
    sub_080065A8();
    v = (u32)gUnk_0829F3BC;
    DrawTextCenteredHighlight(v, 6, a == 0);
    v = GetString(0x02);
    DrawTextCenteredHighlight(v, 8, a == 1);
    v = GetString(0x03);
    DrawTextCenteredHighlight(v, 0xA, a == 2);
    v = GetString(0x60);
    DrawTextCenteredHighlight(v, 0xC, a == 3);
    v = GetString(0x08);
    DrawTextCenteredHighlight(v, 0xE, b == 4);
}
