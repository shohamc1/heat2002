#include "global.h"
#include "gba/defines.h"
#include "variables.h"

struct DepthSortedSprite
{
    u32 attr01;
    u32 attr2;
    u16 depth;
    u16 pad0A;
};

void ResetSpriteQueues(void);

void ResetSpriteQueues(void)
{
    gUnk_02024828 = EWRAM_START + 0x24830;
    gUnk_02024C30 = EWRAM_START + 0x24F50;
    gUnk_02024820 = EWRAM_START + 0x24C40;
    gOamEntryCount = 0;
    gOamAffineCount = 0;
    gUnk_02024824 = 0;
}

void ClearOamBuffer(void)
{
    u32 r1;
    u32 r2;
    u32 *r0;

    r1 = 0;
    r2 = 0xAA;
    r0 = (u32 *)gUnk_02024830;
    while (r1 != 0x80) {
        *r0 = r2;
        r0 += 2;
        r1++;
    }
    ResetSpriteQueues();
}

u32 AddOamEntry(u32 a, u32 b)
{
    u32 *p;

    if ((s8)gOamEntryCount < 0)
        return 0;
    p = *(u32 **)&gUnk_02024828;
    p[0] = a;
    p[1] = b;
    *(u32 *)&gUnk_02024828 = p + 2;
    gOamEntryCount = gOamEntryCount + 1;
    return 1;
}

u32 AddDepthSortedSprite(u32 arg0, u32 arg1, u16 arg2)
{
    struct DepthSortedSprite *r3 = *(struct DepthSortedSprite **)&gUnk_02024820;
    u32 r;

    r3->attr01 = arg0;
    r3->attr2 = arg1;
    r3->depth = arg2;
    *(struct DepthSortedSprite **)&gUnk_02024820 = r3 + 1;
    r = gUnk_02024824 + 1;
    gUnk_02024824 = r;
    return r;
}
