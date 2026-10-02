#include "global.h"
#include "functions.h"
#include "gba/defines.h"
#include "variables.h"

void ModuleResetSpriteQueues(void);

void ModuleResetSpriteQueues(void)
{
    gModule_OamEntryQueueCursor = gModule_OamEntryQueue;
    gModule_SecondOamSortCursor = gModule_SecondOamSortBuffer;
    gModule_DepthSortedSpriteCursor = gModule_DepthSortedSprites;
    gUnk_0203B600 = 0;
    gUnk_0203B604 = 0;
    gModule_DepthSortedSpriteCount = 0;
}

void ModuleClearOamBuffer(void)
{
    u32 i = 0;
    u32 fill = 0xAA;
    u32 *oam = gModule_OamEntryQueue;

    do {
        *oam = fill;
        oam += 2;
        i++;
    } while (i != 0x80);
    ModuleResetSpriteQueues();
}

u32 ModuleAddOamEntry(u32 attr01, u32 attr2)
{
    u32 *ptr;

    if ((s8)gUnk_0203B600 < 0)
        return 0;
    ptr = gModule_OamEntryQueueCursor;
    ptr[0] = attr01;
    ptr[1] = attr2;
    gModule_OamEntryQueueCursor = ptr + 2;
    gUnk_0203B600 = gUnk_0203B600 + 1;
    return 1;
}

u32 ModuleAddDepthSortedSprite(u32 attr01, u32 attr2, u16 depth)
{
    struct DepthSortedSprite *entry;
    u32 newCount;

    entry = gModule_DepthSortedSpriteCursor;
    entry->attr01 = attr01;
    entry->attr2 = attr2;
    entry->depth = depth;
    gModule_DepthSortedSpriteCursor = entry + 1;
    newCount = gModule_DepthSortedSpriteCount + 1;
    gModule_DepthSortedSpriteCount = newCount;
    return newCount;
}
