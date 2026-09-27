#include "global.h"
#include "data.h"
#include "functions.h"
#include "variables.h"

struct EntityB120 {
    /* 0x00 */ u8 pad0[0x18];
    /* 0x18 */ s32 unk18;
};



void sub_0800B120(struct EntityB120 *e)
{
    u32 *spr;
    s32 counter;
    u32 idx;
    u32 arg1;
    u32 t;

    counter = e->unk18;
    idx = (u8)((u8)e->unk18 % 0x17);
    e->unk18 = counter + 1;
    if (e->unk18 > 0x1E)
    {
        spr = sub_0800754C(gUnk_083FF5B0[idx]);
        if (spr != 0)
        {
            register u32 attr asm("r6") = 0x80680040;

            t = (RequestObjPalette((u32)gUnk_08330AD4) << 12) | 0x400;
            arg1 = spr[4] | t;
            if (gIsLinkRace == 0)
                AddOamEntry(attr, arg1);
        }
    }
    if (e->unk18 == 0x4E)
    {
        RemoveTask((u32)e);
        FreeTask((u32)e);
        gUnk_020020C4 = 1;
    }
}
