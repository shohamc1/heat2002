#include "global.h"
#include "functions.h"
#include "data.h"



void sub_080115D8(u8 a)
{
    u8 b = a;
    const u8 *v; sub_08006734(gUiFontTable[0]);
    GetString(0x5A);
    ((void (*)(void))DrawBigText)();
    v = GetString(0x05);
    DrawTextCenteredHighlight(v, 7, a == 0);
    v = GetString(0x06);
    DrawTextCenteredHighlight(v, 9, a == 1);
    v = GetString(0x07);
    DrawTextCenteredHighlight(v, 0xB, a == 2);
    v = GetString(0x08);
    DrawTextCenteredHighlight(v, 0xD, b == 3);
}
