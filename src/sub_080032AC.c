#include "global.h"
#include "functions.h"

extern u8 gLinkPlayerId[];
extern u16 gUnk_03007FF8;


void sub_080032AC(void)
{
    u16 v;
    u8 unused[4];

    if (gLinkPlayerId[0] == 0)
    {
        VBlankIntrWait();
    }
    else
    {
        do
            v = *(vu16 *)&gUnk_03007FF8;
        while ((v & 0x80) == 0);
    }
}
