#include "global.h"
#include "functions.h"
#include "data.h"



void sub_08012984(u8 a)
{
    sub_08006734(gUiFontTable[0]);
    GetString(0xA9);
    ((void (*)(void))DrawBigText)();
    DrawTextCenteredHighlight(GetString(0xC5), 6, 1);
    DrawTextCenteredHighlight(GetString(a + 0xC5), 7, 1);
    if (a != 4)
        DrawTextCenteredHighlight(GetString(a + 0xAA), 0xA, 1);
    else
        DrawTextCenteredHighlight(GetString(0xB3), 0xA, 1);
}
