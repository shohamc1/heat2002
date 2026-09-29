#include "global.h"
#include "data.h"
#include "functions.h"
#include "variables.h"

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
void SetSpriteRotMatrices(void);

void SetSpriteRotMatrices(void)
{
    s16 *sinTable;
    u16 *cosEntry;
    register Ent *oamEntry asm("r4");
    register u32 hiMask asm("r6");
    register s32 cosA asm("r5");
    register u32 entry asm("r0");
    s32 cosIdx;
    u16 angle;
    register u32 cueAngle asm("r0");
    register u16 *cueAnglePtr asm("r1");
    u32 cueAngleCopy;
    register s32 sinVal asm("r2");
    register s32 negSin asm("r3");
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
    oamEntry = (Ent *)gUnk_02024830;
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
