#include "global.h"
#include "functions.h"
#include "data.h"



void sub_08013684(u8 a)
{
    u8 b = a;
    const u8 *v; sub_08006734(gUiFontTable[0]);
    GetString(0x00);
    ((void (*)(void))DrawBigText)();
    v = GetString(0x01);
    DrawTextCenteredHighlight(v, 6, a == 0);
    v = GetString(0x02);
    DrawTextCenteredHighlight(v, 8, a == 1);
    v = GetString(0x03);
    DrawTextCenteredHighlight(v, 0xA, a == 2);
    v = GetString(0x08);
    DrawTextCenteredHighlight(v, 0xC, b == 3);
}
