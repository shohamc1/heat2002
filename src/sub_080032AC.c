#include "global.h"

extern u8 gLinkPlayerId;
extern volatile u16 gUnk_03007FF8;

void VBlankIntrWait(void);

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
            v = gUnk_03007FF8;
        while ((v & 0x80) == 0);
    }
}
