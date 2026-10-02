#include "global.h"
#include "variables.h"
#include "functions.h"

typedef struct
{
    u32 a;
    union
    {
        u32 w;
        struct
        {
            u16 lo;
            u16 hi;
        } h;
    } u;
} Ent;

u32 ModuleSortSpritesByDepth(void);
extern u16 gUnk_0203B6A0;
extern u8 gUnk_0203B854;
extern u8 gUnk_0203B6EC;
void ModuleSetSpriteRotMatrices(void);

void ModuleResetSpriteOrderTable(void)
{
    u32 i;
    u16 *tbl;

    i = 0;
    tbl = gModule_SpriteOrderTable;
    do {
        *tbl++ = i;
        i++;
    } while (i != 0x40);
}

u32 ModuleSortSpritesByDepth(void)
{
    u32 swapped;
    u32 i;
    u16 x;
    u16 y;

restart:
    swapped = 0;
    i = 0;
    do {
        x = gModule_SpriteOrderTable[i];
        y = gModule_SpriteOrderTable[i + 1];
        if (gModule_DepthSortedSprites[x].depth < gModule_DepthSortedSprites[y].depth) {
            gModule_SpriteOrderTable[i] = y;
            gModule_SpriteOrderTable[i + 1] = x;
            swapped = 1;
        }
        i++;
    } while (i != 0x3F);
    if (swapped != 0)
        goto restart;
}

void ModuleFlushSortedSprites(void)
{
    struct DepthSortedSprite *spritePtr;
    u32 *oamPtr;
    u16 *orderPtr;
    struct DepthSortedSprite *entry;
    u32 i;

    i = gModule_DepthSortedSpriteCount;
    while (i != 0x3F) {
        spritePtr = gModule_DepthSortedSpriteCursor;
        spritePtr->depth = 0;
        spritePtr->attr2 = 0xFFFFFFFF;
        spritePtr++;
        gModule_DepthSortedSpriteCursor = spritePtr;
        i++;
    }
    ModuleSortSpritesByDepth();
    orderPtr = gModule_SpriteOrderTable;
    for (i = 0; i != gModule_DepthSortedSpriteCount; i++) {
        entry = &gModule_DepthSortedSprites[*orderPtr];
        if (entry->attr2 != 0xFFFFFFFF) {
            oamPtr = gModule_OamEntryQueueCursor;
            oamPtr[0] = entry->attr01;
            oamPtr[1] = entry->attr2;
            gModule_OamEntryQueueCursor = oamPtr + 2;
        }
        orderPtr++;
    }
}

void ModuleSetSpriteRotMatrices(void)
{
    s16 *sinTable;
    u16 *cosEntry;
    register Ent *oam PIN(r4);
    register u32 hiMask PIN(r6);
    register s32 sinEntry PIN(r5);
    register u32 curAngle PIN(r0);
    s32 angleIdx;
    u16 matrixIdx;
    register u32 angle PIN(r0);
    register u16 *anglePtr PIN(r1);
    u32 angleCopy;
    register s32 sinVal PIN(r2);
    register s32 negSinV PIN(r3);
    u32 sinHi, negSinF16, cosF16;
    u16 cosV;
    s32 negSinEntry;
    u32 m0, m1, m2, m3;
    u32 t0, t1, t2, t3;

    ModuleFlushSortedSprites();
    sinTable = gModule_SinTable;
    matrixIdx = gUnk_0203B6DC;
    angleIdx = matrixIdx + 0x40;
    cosEntry = (u16 *)&sinTable[angleIdx];
    sinVal = sinTable[matrixIdx];
    negSinV = -sinVal;
    sinHi = sinVal << 16;
    negSinF16 = negSinV << 16;
    cosV = *cosEntry;
    cosF16 = cosV << 16;
    oam = (Ent *)gModule_OamEntryQueue;
    oam[0].u.w = cosF16 | oam[0].u.h.lo;
    oam[1].u.w = sinHi | oam[1].u.h.lo;
    oam[2].u.w = negSinF16 | oam[2].u.h.lo;
    oam[3].u.w = cosF16 | oam[3].u.h.lo;

    matrixIdx = gUnk_0203B828;
    angleIdx = matrixIdx + 0x40;
    cosEntry = (u16 *)&sinTable[angleIdx];
    sinVal = sinTable[matrixIdx];
    negSinV = -sinVal;
    sinHi = sinVal << 16;
    negSinF16 = negSinV << 16;
    cosV = *cosEntry;
    cosF16 = cosV << 16;
    oam[4].u.w = cosF16 | oam[4].u.h.lo;
    oam[5].u.w = sinHi | oam[5].u.h.lo;
    oam[6].u.w = negSinF16 | oam[6].u.h.lo;
    hiMask = 0xFFFF;
    oam[7].u.w = cosF16 | oam[7].u.h.lo;

    anglePtr = &gUnk_0203B6A0;
    angle = *anglePtr;
    if (angle != 0) {
        angleCopy = angle;
        angle += 0x40;
        sinEntry = sinTable[angle];
        sinVal = sinTable[angleCopy];
        negSinV = -sinVal;
        negSinEntry = sinEntry;
        if (gUnk_0203B854 != 0) {
            sinEntry = -negSinEntry;
            negSinV = sinVal;
        }
        if (gUnk_0203B6EC != 0) {
            sinVal = -sinVal;
            negSinEntry = -negSinEntry;
        }
        m0 = sinEntry & hiMask;
        m1 = sinVal & hiMask;
        m2 = negSinV & hiMask;
        m3 = negSinEntry & hiMask;
        t0 = m0 << 16;
        t1 = m1 << 16;
        t2 = m2 << 16;
        t3 = m3 << 16;
        curAngle = oam[8].u.w;
        curAngle &= hiMask;
        curAngle |= t0;
        oam[8].u.w = curAngle;
        curAngle = oam[9].u.w;
        curAngle &= hiMask;
        curAngle |= t1;
        oam[9].u.w = curAngle;
        curAngle = oam[10].u.w;
        curAngle &= hiMask;
        curAngle |= t2;
        oam[10].u.w = curAngle;
        curAngle = oam[11].u.w;
        curAngle &= hiMask;
        curAngle |= t3;
        oam[11].u.w = curAngle;
    }
}

void ModuleUpdateSprites(void)
{ ModuleSetSpriteRotMatrices(); }
