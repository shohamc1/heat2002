#include "global.h"

struct EntityB120 {
    /* 0x00 */ u8 pad0[0x18];
    /* 0x18 */ s32 unk18;
};

extern u32 gUnk_083FF5B0[];        /* 0x083FF5B0 */
extern u8 gUnk_08330AD4[];         /* 0x08330AD4 */
extern volatile u8 gIsLinkRace;  /* 0x020020DC */
extern u8 gUnk_020020C4;           /* 0x020020C4 */

u32 *sub_0800754C(u32 a);
u8 RequestObjPalette(u32 a);
u32 AddOamEntry(u32 a, u32 b);
void RemoveTask(struct EntityB120 *e);
void FreeTask(struct EntityB120 *e);

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
        RemoveTask(e);
        FreeTask(e);
        gUnk_020020C4 = 1;
    }
}
