#include "global.h"
#include "data.h"
#include "functions.h"
#include "variables.h"



void sub_0800B384(u32 a)
{
    u8 unused[0x28];

    DrawTextAt(GetString(0x9A), 9, 5);
    DrawTextAt(gLapTimeTextBuf, 0xD, 5);
    if (--*(u32 *)(a + 0x18) == 0)
    {
        DrawTextAt(gText_BlankRowRaceMsg, 9, 5);
        RemoveTask(a);
        FreeTask(a);
    }
}
