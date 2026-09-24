#include "global.h"

extern u32 gUnk_083FDE18;
extern u32 GetString(u16 idx);
extern void sub_080065A8(void);
extern void DrawTextCenteredHighlight(u8 *p, u32 a1, u8 a2);
extern void sub_08006734(u32 a);

void sub_08014480(u8 a)
{
    u8 b;

    b = a;
    sub_08006734(gUnk_083FDE18);
    GetString(4);
    sub_080065A8();
    DrawTextCenteredHighlight(GetString(5), 7, a == 0);
    DrawTextCenteredHighlight(GetString(6), 9, a == 1);
    DrawTextCenteredHighlight(GetString(0x9D), 0xB, a == 2);
    DrawTextCenteredHighlight(GetString(8), 0xD, b == 3);
}
