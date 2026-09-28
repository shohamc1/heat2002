#include "global.h"
#include "functions.h"
#include "data.h"


void sub_08012B24(void)
{
    const u8 *v; DummyUiFontLoad(gUiFontTable[0]);
    GetString(0xBD);
    ((void (*)(void))DrawBigText)();
    v = GetString(0xBE);
    DrawTextCenteredHighlight(v, 6, 1);
}
