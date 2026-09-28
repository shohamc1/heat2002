#include "global.h"
#include "functions.h"
#include "data.h"



void sub_08013908(u8 a)
{
    u8 v;

    v = a;
    sub_08006734(gUnk_083FDE18[0]);
    GetString(0x60);
    ((void (*)(void))DrawBigText)();
    if (a == 0)
        DrawTextCenteredHighlight(GetString(0x63), 9, 1);
    if (a == 1)
        DrawTextCenteredHighlight(GetString(0x61), 9, 1);
    if (v == 2)
        DrawTextCenteredHighlight(GetString(0x62), 9, 1);
}
