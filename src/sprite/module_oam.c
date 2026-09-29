#include "global.h"
#include "gba/defines.h"
#include "variables.h"

void ModuleResetSpriteQueues(void);

void ModuleResetSpriteQueues(void)
{
    gUnk_0203ACD8 = (u32 *)(EWRAM_START + 0x3ACE0);
    gUnk_0203B0E0 = EWRAM_START + 0x3B400;
    gUnk_0203ACD0 = (u32 *)(EWRAM_START + 0x3B0F0);
    gUnk_0203B600 = 0;
    gUnk_0203B604 = 0;
    gUnk_0203ACD4 = 0;
}

void ModuleClearOamBuffer(void)
{
    u32 i = 0;
    u32 fill = 0xAA;
    u32 *oam = (u32 *)gUnk_0203ACE0;

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
    ptr = gUnk_0203ACD8;
    ptr[0] = attr01;
    ptr[1] = attr2;
    gUnk_0203ACD8 = ptr + 2;
    gUnk_0203B600 = gUnk_0203B600 + 1;
    return 1;
}

u32 ModuleAddDepthSortedSprite(u32 attr01, u32 attr2, u16 depth)
{
    u32 *ptr;
    u32 newCount;

    ptr = gUnk_0203ACD0;
    ptr[0] = attr01;
    ptr[1] = attr2;
    ((u16 *)ptr)[4] = depth;
    gUnk_0203ACD0 = ptr + 3;
    newCount = gUnk_0203ACD4 + 1;
    gUnk_0203ACD4 = newCount;
    return newCount;
}
