#include "global.h"

extern u32 gUnk_083FFAA8[];

u32 sub_0801B034(u32 id)
{
    u32 *tbl = (u32 *)gUnk_083FFAA8[0];

    if (id == ((s16 *)tbl[1])[7])
        return *(u32 *)0x020004AC;
    else if (id == ((s16 *)tbl[2])[7])
        return *(u32 *)0x020004B0;
    else if (id == ((s16 *)tbl[3])[7])
        return *(u32 *)0x020004B4;
    else
        return id - 0x20;
}
