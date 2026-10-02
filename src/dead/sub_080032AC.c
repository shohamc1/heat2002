#include "global.h"
#include "functions.h"
#include "variables.h"

void sub_080032AC(void)
{
    u16 v;
    u8 unused[4];

    if (gLinkPlayerId == 0)
    {
        VBlankIntrWait();
    }
    else
    {
        do
            v = *(vu16 *)&gIntrCheck;
        while ((v & 0x80) == 0);
    }
}

void sub_080032DC(void)
{
    u8 unused[0x28];
}
