#include "global.h"

extern u32 gUnk_083FDE18;

void sub_08006734(u32 a);
u32 GetString(u32 idx);
void sub_080065A8(u32 a);
void DrawTextCenteredHighlight(u8 *p, u32 a1, u8 a2);

void sub_08014374(void)
{
    sub_08006734(gUnk_083FDE18);
    sub_080065A8(GetString(0x12));
    DrawTextCenteredHighlight((u8 *)GetString(0x11), 7, 1);
    DrawTextCenteredHighlight((u8 *)GetString(0x11), 8, 1);
    DrawTextCenteredHighlight((u8 *)GetString(0x11), 9, 1);
    DrawTextCenteredHighlight((u8 *)GetString(0x11), 0xA, 1);
    DrawTextCenteredHighlight((u8 *)GetString(0x11), 0xB, 1);
    DrawTextCenteredHighlight((u8 *)GetString(0x11), 0xC, 1);
    DrawTextCenteredHighlight((u8 *)GetString(0x11), 0xD, 1);
    DrawTextCenteredHighlight((u8 *)GetString(0x11), 0xE, 1);
}
