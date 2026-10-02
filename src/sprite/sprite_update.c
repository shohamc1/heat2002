#include "global.h"
#include "gba/defines.h"
#include "variables.h"
#include "data.h"
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

u32 SortSpritesByDepth(void);
void SetSpriteRotMatrices(void);

/* The file's RAM variables (gDepthSortedSprites, gSpriteOrderTable,
   gUnk_0202522C and gUnk_02025398) moved to src/hud/globals.c, the
   owner of the 0x02024C40-0x02025270 and 0x02025380 EWRAM runs they
   sit in; they are declared in variables.h. */

void ResetSpriteOrderTable(void)
{
    u32 i = 0;
    u16 *orderEntry = gSpriteOrderTable;

    while (i != 0x40) {
        *orderEntry = i;
        orderEntry += 1;
        i++;
    }
}

u32 SortSpritesByDepth(void)
{
    u8 swapped;
    u32 i;
    u16 a;
    u16 b;

outer:
    swapped = 0;
    i = 0;
    do {
        a = gSpriteOrderTable[i];
        b = gSpriteOrderTable[i + 1];
        if (gDepthSortedSprites[a].depth < gDepthSortedSprites[b].depth) {
            gSpriteOrderTable[i] = b;
            gSpriteOrderTable[i + 1] = a;
            swapped = 1;
        }
        i++;
    } while (i != 0x3F);
    if (swapped)
        goto outer;
#if PORTABLE
    /* The ROM falls off the end; no caller reads the result. */
    return 0;
#endif
}

void FlushSortedSprites(void)
{
    register struct DepthSortedSprite *p PIN(r0);
    register u32 *oam PIN(r0);
    u32 i;
    struct DepthSortedSprite *e;
    struct DepthSortedSprite *base;
    u16 *tbl;

    for (i = gDepthSortedSpriteCount; i != 0x3F; i++) {
        p = gDepthSortedSpriteCursor;
        p->depth = 0;
        p->attr2 = -1;
        p++;
        gDepthSortedSpriteCursor = p;
    }
    SortSpritesByDepth();
    tbl = gSpriteOrderTable;
    for (i = 0; i != gDepthSortedSpriteCount; tbl++, i++) {
        base = gDepthSortedSprites;
        e = &base[*tbl];
        if (e->attr2 != -1) {
            oam = gOamEntryQueueCursor;
            oam[0] = e->attr01;
            oam[1] = e->attr2;
            oam += 2;
            gOamEntryQueueCursor = oam;
        }
    }
}

void SetSpriteRotMatrices(void)
{
    const s16 *sinTable;
    u16 *cosEntry;
    register Ent *oamEntry PIN(r4);
    register u32 hiMask PIN(r6);
    register s32 cosA PIN(r5);
    register u32 entry PIN(r0);
    s32 cosIdx;
    u16 angle;
    register u32 cueAngle PIN(r0);
    register u16 *cueAnglePtr PIN(r1);
    u32 cueAngleCopy;
    register s32 sinVal PIN(r2);
    register s32 negSin PIN(r3);
    u32 sinHi, negSinHi, cosHi;
    u16 cosVal;
    s32 cosB;
    u32 lo0, lo1, lo2, lo3;
    u32 hi0, hi1, hi2, hi3;

    FlushSortedSprites();
    sinTable = gSinTable;
    angle = gUnk_0202522C;
    cosIdx = angle + 0x40;
    cosEntry = (u16 *)&sinTable[cosIdx];
    sinVal = sinTable[angle];
    negSin = -sinVal;
    sinHi = sinVal << 16;
    negSinHi = negSin << 16;
    cosVal = *cosEntry;
    cosHi = cosVal << 16;
    oamEntry = (Ent *)gOamEntryQueue;
    oamEntry[0].u.w = cosHi | oamEntry[0].u.h.lo;
    oamEntry[1].u.w = sinHi | oamEntry[1].u.h.lo;
    oamEntry[2].u.w = negSinHi | oamEntry[2].u.h.lo;
    oamEntry[3].u.w = cosHi | oamEntry[3].u.h.lo;

    angle = gUnk_02025398;
    cosIdx = angle + 0x40;
    cosEntry = (u16 *)&sinTable[cosIdx];
    sinVal = sinTable[angle];
    negSin = -sinVal;
    sinHi = sinVal << 16;
    negSinHi = negSin << 16;
    cosVal = *cosEntry;
    cosHi = cosVal << 16;
    oamEntry[4].u.w = cosHi | oamEntry[4].u.h.lo;
    oamEntry[5].u.w = sinHi | oamEntry[5].u.h.lo;
    oamEntry[6].u.w = negSinHi | oamEntry[6].u.h.lo;
    hiMask = 0xFFFF;
    oamEntry[7].u.w = cosHi | oamEntry[7].u.h.lo;

    cueAnglePtr = &gUnk_020251F0;
    cueAngle = *cueAnglePtr;
    if (cueAngle != 0) {
        cueAngleCopy = cueAngle;
        cueAngle += 0x40;
        cosA = sinTable[cueAngle];
        sinVal = sinTable[cueAngleCopy];
        negSin = -sinVal;
        cosB = cosA;
        if (gUnk_020253C8 != 0) {
            cosA = -cosB;
            negSin = sinVal;
        }
        if (gUnk_0202523C != 0) {
            sinVal = -sinVal;
            cosB = -cosB;
        }
        lo0 = cosA & hiMask;
        lo1 = sinVal & hiMask;
        lo2 = negSin & hiMask;
        lo3 = cosB & hiMask;
        hi0 = lo0 << 16;
        hi1 = lo1 << 16;
        hi2 = lo2 << 16;
        hi3 = lo3 << 16;
        entry = oamEntry[8].u.w;
        entry &= hiMask;
        entry |= hi0;
        oamEntry[8].u.w = entry;
        entry = oamEntry[9].u.w;
        entry &= hiMask;
        entry |= hi1;
        oamEntry[9].u.w = entry;
        entry = oamEntry[10].u.w;
        entry &= hiMask;
        entry |= hi2;
        oamEntry[10].u.w = entry;
        entry = oamEntry[11].u.w;
        entry &= hiMask;
        entry |= hi3;
        oamEntry[11].u.w = entry;
    }
}

void UpdateSprites(void)
{ SetSpriteRotMatrices(); }
