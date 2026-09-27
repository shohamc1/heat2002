#include "global.h"
#include "variables.h"

struct SoundSlot0833F {
    /* +0x00 */ u32 unk00;
    /* +0x04 */ u8 unk04;
    /* +0x05 */ u8 unk05[3];
    /* +0x08 */ void *unk08;
    /* +0x0C */ u8 unk0C[8];
};


struct SoundSlot0833F *sub_0833FCE0(void *a)
{
    struct SoundSlot0833F *p;
    u32 i;

    p = (struct SoundSlot0833F *)gModule_ObjTileCache1;
    for (i = 0; i != 0x20; i++, p++)
    {
        if (p->unk08 == a)
        {
            p->unk00 = 1;
            return p;
        }
    }

    p = (struct SoundSlot0833F *)gModule_ObjTileCache1;
    for (i = 0; i != 0x20; i++, p++)
    {
        if (p->unk00 == 0)
        {
            p->unk00 = 1;
            p->unk04 = 1;
            p->unk08 = a;
            return p;
        }
    }

    return 0;
}
