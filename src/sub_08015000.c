#include "global.h"
#include "functions.h"
#include "data.h"



void sub_08015000(u8 a)
{
    const u8 *v;
    u8 b;

    b = a;
    sub_08006734(gUnk_083FDE18[0]);
    GetString(0x0A);
    ((void (*)(void))DrawBigText)();
    v = GetString(0x05);
    DrawTextCenteredHighlight(v, 7, a == 0);
    v = GetString(0x07);
    DrawTextCenteredHighlight(v, 9, a == 1);
    v = GetString(0x08);
    DrawTextCenteredHighlight(v, 0xB, b == 2);
}
