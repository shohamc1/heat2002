#include "global.h"
#include "variables.h"

void sub_08344B74(void);

void sub_0833C7F0(void)
{
    u16 v;
    u8 unused[4];

    if (gModule_LinkPlayerId == 0)
    {
        sub_08344B74();
    }
    else
    {
        do
            v = *(vu16 *)&gIntrCheck;
        while ((v & 0x80) == 0);
    }
}

void sub_0833C820(void)
{
    u8 unused[0x28];
}
