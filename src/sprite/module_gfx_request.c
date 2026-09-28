#include "global.h"
#include "variables.h"

struct SoundSlot0833F {
    /* +0x00 */ u32 unk00;
    /* +0x04 */ u8 unk04;
    /* +0x05 */ u8 unk05[3];
    /* +0x08 */ void *unk08;
    /* +0x0C */ u8 unk0C[8];
};


struct SoundSlot0833F *ModuleRequestObjTiles16(void *gfx)
{
    struct SoundSlot0833F *entry;
    u32 i;

    entry = (struct SoundSlot0833F *)gModule_ObjTileCache16;
    for (i = 0; i != 0x18; i++, entry++)
    {
        if (entry->unk08 == gfx)
        {
            entry->unk00 = 1;
            return entry;
        }
    }

    entry = (struct SoundSlot0833F *)gModule_ObjTileCache16;
    for (i = 0; i != 0x18; i++, entry++)
    {
        if (entry->unk00 == 0)
        {
            entry->unk00 = 1;
            entry->unk04 = 1;
            entry->unk08 = gfx;
            return entry;
        }
    }

    return 0;
}


struct SoundSlot0833F *ModuleRequestObjTiles2(void *gfx)
{
    struct SoundSlot0833F *entry;
    u32 i;

    entry = (struct SoundSlot0833F *)gModule_ObjTileCache2;
    for (i = 0; i != 0x20; i++, entry++)
    {
        if (entry->unk08 == gfx)
        {
            entry->unk00 = 1;
            return entry;
        }
    }

    entry = (struct SoundSlot0833F *)gModule_ObjTileCache2;
    for (i = 0; i != 0x20; i++, entry++)
    {
        if (entry->unk00 == 0)
        {
            entry->unk00 = 1;
            entry->unk04 = 1;
            entry->unk08 = gfx;
            return entry;
        }
    }

    return 0;
}


struct SoundSlot0833F *ModuleRequestObjTiles8(void *gfx)
{
    struct SoundSlot0833F *entry;
    u32 i;

    entry = (struct SoundSlot0833F *)gModule_ObjTileCache8;
    for (i = 0; i != 0x14; i++, entry++)
    {
        if (entry->unk08 == gfx)
        {
            entry->unk00 = 1;
            return entry;
        }
    }

    entry = (struct SoundSlot0833F *)gModule_ObjTileCache8;
    for (i = 0; i != 0x14; i++, entry++)
    {
        if (entry->unk00 == 0)
        {
            entry->unk00 = 1;
            entry->unk04 = 1;
            entry->unk08 = gfx;
            return entry;
        }
    }

    return 0;
}


struct SoundSlot0833F *ModuleRequestObjTiles4(void *gfx)
{
    struct SoundSlot0833F *entry;
    u32 i;

    entry = (struct SoundSlot0833F *)gModule_ObjTileCache4;
    for (i = 0; i != 0x10; i++, entry++)
    {
        if (entry->unk08 == gfx)
        {
            entry->unk00 = 1;
            return entry;
        }
    }

    entry = (struct SoundSlot0833F *)gModule_ObjTileCache4;
    for (i = 0; i != 0x10; i++, entry++)
    {
        if (entry->unk00 == 0)
        {
            entry->unk00 = 1;
            entry->unk04 = 1;
            entry->unk08 = gfx;
            return entry;
        }
    }

    return 0;
}


struct SoundSlot0833F *ModuleRequestObjTiles1(void *gfx)
{
    struct SoundSlot0833F *entry;
    u32 i;

    entry = (struct SoundSlot0833F *)gModule_ObjTileCache1;
    for (i = 0; i != 0x20; i++, entry++)
    {
        if (entry->unk08 == gfx)
        {
            entry->unk00 = 1;
            return entry;
        }
    }

    entry = (struct SoundSlot0833F *)gModule_ObjTileCache1;
    for (i = 0; i != 0x20; i++, entry++)
    {
        if (entry->unk00 == 0)
        {
            entry->unk00 = 1;
            entry->unk04 = 1;
            entry->unk08 = gfx;
            return entry;
        }
    }

    return 0;
}

