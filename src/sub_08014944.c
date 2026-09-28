#include "global.h"
#include "functions.h"
#include "data.h"



void sub_08014944(u8 a)
{
    const u8 *v;
    u8 b;

    b = a;
    sub_08006734(gUnk_083FDE18[0]);
    GetString(0x0D);
    ((void (*)(void))DrawBigText)();
    v = GetString(0x05);
    DrawTextCenteredHighlight(v, 8, a == 0);
    v = GetString(0x0E);
    DrawTextCenteredHighlight(v, 0xA, a == 1);
    v = GetString(0x08);
    DrawTextCenteredHighlight(v, 0xC, b == 2);
}
