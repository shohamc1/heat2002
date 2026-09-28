#include "global.h"
#include "functions.h"
#include "data.h"


void sub_08014614(u32 a)
{
    u8 i;

    sub_08006734(gUnk_083FDE18[0]);
    GetString(0xA4);
    ((void (*)(void))DrawBigText)();
    i = 0;
    do {
        DrawTextCenteredHighlight(GetString(i + 0xA5), i * 2 + 6, a == i);
        i++;
    } while (i != 4);
}
