#include "global.h"

extern u32 gUnk_083FDE18;
extern u32 GetString(u16 idx);
extern void sub_080065A8(void);
extern void DrawTextCenteredHighlight(u8 *p, u32 a1, u8 a2);
extern void sub_08006734(u32 a);

void sub_0801264C(u32 x)
{
    sub_08006734(gUnk_083FDE18);
    GetString(0x14);
    sub_080065A8();
    DrawTextCenteredHighlight(GetString(0x15), 8, x == 0);
    DrawTextCenteredHighlight(GetString(0x16), 0xA, x == 1);
    DrawTextCenteredHighlight(GetString(0x17), 0xC, x == 2);
    DrawTextCenteredHighlight(GetString(0x18), 0xE, x == 3);
}
