#include "global.h"
#include "functions.h"
#include "data.h"

extern u8 gUnk_0202EEFC;
extern u16 gUnk_083FDE5E[];


void sub_0801060C(u8 a)
{
    u8 *d;
    u32 i;
    u16 *p;
    u32 j;

    d = &gUnk_0202EEFC;
    /* sub_0800E730: this file's old prototype returns u8; the matched
       definition returns void; call through a function pointer. */
    *d = ((u8 (*)(void))sub_0800E730)();
    DummyUiFontLoad(gUiFontTable[0]);
    GetString(0x59);
    ((void (*)(void))DrawBigText)();
    i = 0;
    j = 5;
    p = gUnk_083FDE5E;
    do {
        DrawTextCenteredHighlight(GetString(*p), j, a == i);
        j += 2;
        p++;
        i++;
    } while (i != 7);
}
