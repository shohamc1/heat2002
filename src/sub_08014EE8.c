#include "global.h"
#include "functions.h"
#include "data.h"


void sub_08014EE8(u8 a)
{
    u8 b;

    b = a;
    sub_08006734(gUnk_083FDE18[0]);
    GetString(9);
    ((void (*)(void))DrawBigText)();
    DrawTextCenteredHighlight(GetString(5), 7, a == 0);
    DrawTextCenteredHighlight(GetString(6), 9, a == 1);
    DrawTextCenteredHighlight(GetString(0x9D), 0xB, a == 2);
    DrawTextCenteredHighlight(GetString(8), 0xD, b == 3);
}
