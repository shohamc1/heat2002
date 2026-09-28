#include "global.h"
#include "functions.h"
#include "data.h"

extern u8 gText_Practice[];


void sub_080134E8(u8 a)
{
    u8 b = a;
    const u8 *v; sub_08006734(gUnk_083FDE18[0]);
    GetString(0x00);
    ((void (*)(void))DrawBigText)();
    v = (u32)gText_Practice;
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
