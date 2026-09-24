#include "global.h"

extern u32 gUnk_083FDE18[];

void sub_08006734(u32 a);
u32 GetString(u16 idx);
void sub_080065A8(void);
void DrawTextCenteredHighlight(u32 a, u32 b, u32 c);

void sub_08012FB0(void)
{
    sub_08006734(gUnk_083FDE18[0]);
    GetString(0x23);
    sub_080065A8();
    DrawTextCenteredHighlight(GetString(0x11), 7, 1);
    DrawTextCenteredHighlight(GetString(0x11), 8, 1);
    DrawTextCenteredHighlight(GetString(0x11), 9, 1);
    DrawTextCenteredHighlight(GetString(0x11), 0xA, 1);
    DrawTextCenteredHighlight(GetString(0x11), 0xB, 1);
    DrawTextCenteredHighlight(GetString(0x11), 0xC, 1);
    DrawTextCenteredHighlight(GetString(0x11), 0xD, 1);
    DrawTextCenteredHighlight(GetString(0x11), 0xE, 1);
}
