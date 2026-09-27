#include "global.h"

extern u8 gUnk_0203E1B0;
extern u16 gUnk_03007FF8;

void sub_08344B74(void);

void sub_0833C7F0(void)
{
    u16 v;
    u8 unused[4];

    if (gUnk_0203E1B0 == 0)
    {
        sub_08344B74();
    }
    else
    {
        do
            v = *(vu16 *)&gUnk_03007FF8;
        while ((v & 0x80) == 0);
    }
}
